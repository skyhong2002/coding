num = int(input("幫你從1加到n："))
ans = 0
for i in range(num):
    ans = ans + i + 1
    print("-"*(i+1))

print("答案是：", ans)