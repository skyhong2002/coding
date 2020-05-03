demo_list = list(map(int, input("輸入一堆數字幫你找最大值和位址OuO：").split()))

maxnum = 0
index = 0

for i in range(len(demo_list)):
    if maxnum < demo_list[i]:
        maxnum = demo_list[i]
        index = i

print("最大數字 =", demo_list[index])
print("位址在：", index)
