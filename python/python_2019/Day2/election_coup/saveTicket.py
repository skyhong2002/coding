
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Aug  8 15:25:53 2019

@author: cobra
"""

from validator import validator 

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

# 將輸入結果轉成清單
def setAllTicket(rawData):
    tickets = rawData
    allTicket = []
    for vote in tickets:
        voteList3 = vote.split() 
        allTicket.append({'name':voteList3[0], 'age':int(voteList3[1]),
                          'voted':int(voteList3[2])})
    return allTicket


# 建立有效票清單
def setValidTicket(allTicket):
    validTicket = []
    for ticket in allTicket:
        age = ticket['age']
        voted = ticket['voted']
        if validator(age, voted):
            validTicket.append(ticket)
    return validTicket
            
# 輸出總票數
def allTicketNumber(allTicket):
    return len(allTicket)


    


