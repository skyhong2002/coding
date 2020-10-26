def people(lines) :

    i = input("輸入資料：")
    if i == "": return
    lines.append(i)

    while not i == "":
        i = input()
        lines.append(i)
    return lines
