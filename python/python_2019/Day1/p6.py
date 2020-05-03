
ip = '''拉布 89 Blue
寶寶 27 Green
任禎 49 Green
Sean 41 Black
欣岑 10 Black
Vense 27 Green
去冰 86 Yellow
YC 37 Black
腋毛 18 Black
Trista 58 Blue
彥伊 46 Green
鈺婷 88 Blue
小知 91 Green
雷孟 67 Black
肥貓 91 Yellow
Rong 94 Black
宙斯 16 Black
凱凱 89 Blue
古哥 49 Yellow
AllenChou 34 Blue
Eva 34 Blue
攤攤 26 Black'''

dic = ip.split("\n")

d = {}
for i in dic:
        imformation = i.split(" ")
        d[imformation[0]] = {"age": imformation[1], "color": imformation[2]}

print(d)

for i in d:
        print(i, d[i]["age"], d[i]["color"])