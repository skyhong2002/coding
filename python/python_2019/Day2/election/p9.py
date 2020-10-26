
from judge import judge

ip = '''拉布 89 1
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

voteData = ip.split("\n")

d = {}

c = 0
vaild = 0
fail = 0
c1 = 0
c2 = 0
c3 = 0

for i in voteData:
        imformation = i.split(" ")
        d[imformation[0]] = {"age": int(imformation[1]), "candidate": int(imformation[2])}
        
        c += 1

        if judge(d[imformation[0]]["age"], d[imformation[0]]["candidate"]):
            fail += 1
            continue

        vaild += 1

        if d[imformation[0]]["candidate"] == 1:
            c1 += 1
        elif d[imformation[0]]["candidate"] == 2:
            c2 += 1
        elif d[imformation[0]]["candidate"] == 3:
            c3 += 1





if __name__ == "__main__":
    print("候選人一：{}票, 得票率為：{:0.2f}％。".format(c1, (c1/c)*100))
    print("候選人二：{}票, 得票率為：{:0.2f}％。".format(c2, (c2/c)*100))
    print("候選人三：{}票, 得票率為：{:0.2f}％。".format(c3, (c3/c)*100))
    print("廢票率為：{:0.2f}％。".format((fail/c)*100))