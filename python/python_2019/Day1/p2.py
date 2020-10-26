year = int(input("輸入年份幫你判斷OuO："))
ans = True

if year%4 == 0:
    ans = False

if year%100 == 0:
    ans = True

if year%400 == 0:
    ans = False

if ans:
    print("平年！")
else:
    print("閏年QQ")