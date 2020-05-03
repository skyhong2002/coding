import socket
import json
import select
import sys

def receive(sock):
    s = sock.recv(6000)
    while True:
        if 10 not in s:
            s = s + sock.recv(6000)
        else:
            break
    return json.loads(s.decode('utf8'))

def receive_from_input():
    if select.select([sys.stdin], [], [], 0) == ([sys.stdin], [], []):
        s = sys.stdin.readline()
        d = {'cmd':'text','content':'Sky:' + s[:len(s)-1]}
        return d
    else:
        return None
    
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
try:
    sock.connect(('140.112.30.42',44449))
except:
    sock.close()
    print('socket fail.')
    exit()
print('connect succeed')

#TrafficLight,Sky

try:
    name_dic = {'cmd':'matching','name':'Sky','target':'TrafficLight'}
    sock.send((json.dumps(name_dic)+'\n').encode('utf8'))
except:
    sock.close()
    print('Transfer instructions fail.')
    exit()
print('Transfer instructions succeed')

try:
    recv_dict = receive(sock)
except:
    print('Bang')
    
print('waiting...')

sock.settimeout(0.1)
while True:
    get = None
    try:
        get = sock.recv(6000)
    except:
        pass
    if get:
        get_string = get.decode('utf8')
        text = json.loads(get_string)
        #text[text.keys()[2]]
        text = text[list(text.keys())[1]]
        print(text)
        
    s_dict = receive_from_input()
    if s_dict:
        sock.send((json.dumps(s_dict)+'\n').encode('utf8'))
        
sock.close()

'''
if text == 'quit':
    sock.close()
    print('quit.')
    exit()
'''