money = int(input("輸入金額："))
rate = float(input("輸入年利率："))
year = int(input("輸入存入時間(年)："))

ans = money * ((1 + rate) ** year)

print("領出", format(ans, "0.0f"), "元！")