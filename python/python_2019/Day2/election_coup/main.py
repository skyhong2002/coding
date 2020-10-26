
from validator import validator
from saveTicket import setAllTicket, setValidTicket, allTicketNumber
from numvote import numvote
from people import people

'''拉布 89 1
寶寶 27 3
任禎 49 3
Sean 41 4
欣岑 10 4
Vense 27 3
去冰 86 2
YC 37 4
腋毛 18 4
Trista 58 1
彥伊 46 3
鈺婷 88 1
小知 91 3
雷孟 67 4
肥貓 91 2
Rong 94 4
宙斯 16 4
凱凱 89 1
古哥 49 2
AllenChou 34 1
Eva 34 1
攤攤 26 4'''

lines = []
for i in range (22) :
    lines.append(input())

#people(lines)

allTicket = setAllTicket(lines)

ValidTicket = setValidTicket(allTicket)

TicketCount = len(allTicket)

v = numvote(ValidTicket,TicketCount)

if __name__ == "__main__":
    print("候選人一：{}票, 得票率為：{:0.2f}％。".format(v[0], (v[0]/TicketCount)*100))
    print("候選人二：{}票, 得票率為：{:0.2f}％。".format(v[1], (v[1]/TicketCount)*100))
    print("候選人三：{}票, 得票率為：{:0.2f}％。".format(v[2], (v[2]/TicketCount)*100))
    print("廢票率為：{:0.2f}％。".format(((TicketCount - v[0] - v[1] - v[2])/TicketCount)*100))