from flask import Flask, request, render_template, redirect, url_for, Response
from flask import jsonify
import time, json
import os, pickle
import traceback
import string
app = Flask(__name__)

def itemgetter(*items):
    if len(items) == 1:
        item = items[0]
        def g(obj):
            return obj[item]
    else:
        def g(obj):
            return tuple(obj[item] for item in items)
    return g

# 載入歷史訊息
# message = [ (name, content, mid, timestamp), (name, content, mid, timestamp), ... ]
# message[0] 最新
# message[-1] 最舊

#載入留言資料
messages_file = "messages.pickle"
if os.path.exists(messages_file):
    with open(messages_file, 'rb') as f:
        messages = pickle.load(f)
else:
    messages = []
    with open(messages_file, 'wb') as f:
        pickle.dump(obj=messages, file=f)


@app.route("/", methods=['GET'])
def homepage():
    
    sort_key   = request.args.get('sort', '')   
    filter_key = request.args.get('filter', '') 
    page       = request.args.get('page', 1) 

    #判斷timestamp是否有效
    
    #filter_key排序
    if filter_key == '':
        messages_filted = messages
    else:
        messages_filted = []
        for i in range(len(messages)):
            if messages[i][0].find(filter_key) != -1 or messages[i][1].find(filter_key) != -1:
                messages_filted.append(messages[i])
                continue
    
    #sort_key排序
    
    if sort_key == 'time':
        messages_sorted = messages_filted
    elif sort_key == 'r_time':
        messages_sorted = messages_filted
        messages_sorted.reverse()
        
    elif sort_key == 'user':
        messages_sorted = sorted(messages_filted, reverse=False)
    elif sort_key == 'r_user':
        messages_sorted = sorted(messages_filted, reverse=True)
        
    elif sort_key == 'len':
        messages_sorted = sorted(messages_filted, key = lambda x: len(x[1]), reverse=False)
    elif sort_key == 'r_len':
        messages_sorted = sorted(messages_filted, key = lambda x: len(x[1]), reverse=True)
        
    else:
        messages_sorted = messages_filted #不變
    
    #判斷page是否有效
    
    if str(page).isdigit():
        cnt = 0
    else:
        page = 1
        return redirect(f'/?sort={sort_key}&filter={filter_key}&page={1}')
    
    if int(page) <= 0:
        page = 1
        return redirect(f'/?sort={sort_key}&filter={filter_key}&page={1}')
    elif int(page) > (len(messages_sorted)//5 + 1):
        page = len(messages_sorted)//5 + 1
        return redirect(f'/?sort={sort_key}&filter={filter_key}&page={len(messages_sorted)//5 + 1}')
    
    #載入分頁
    messages_paged = []
    for i in range(5):
        if len(messages_sorted) > (int(page) - 1) * 5 + i:
            messages_paged.append(messages_sorted[(int(page) - 1) * 5 + i])
        else:
            break
            
    #de
    print(messages_paged)
            
    #return redirect(f'/?sort={sort_key}&filter={filter_key}&page={page}')
    return render_template('index.html', message_pool=messages_paged)


@app.route("/add", methods=['POST'])
def add_message():
    global messages
    name      = request.form['from_user']
    content   = request.form['new_message']
    timestamp = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())

    # 產生一個 messages 裡面沒有出現過的 mid
    mid = len(messages) + 1

    # 在 messages 新增
    messages.insert(0, [name, content, mid, timestamp])
    
    # 儲存更新後的messages
    with open(messages_file, 'wb') as f:
        pickle.dump(obj=messages, file=f)

    return redirect(url_for('homepage'))



#留言刪除（有時候會出現"Error!"，但是重整後還是可以正常刪除）
@app.route("/delete", methods=['DELETE'])
def delete_message():
    data = json.loads(request.data)
    delete_mid  = data['index']

    # Delete the message whose id == mid
    for i in range(len(messages)):
        
        if int(messages[i][2]) == int(delete_mid):
            messages.pop(i)
            break

    # 儲存更新後的 messages
    with open(messages_file, 'wb') as f:
        pickle.dump(obj=messages, file=f)

    return Response("", status=200, mimetype='application/json')