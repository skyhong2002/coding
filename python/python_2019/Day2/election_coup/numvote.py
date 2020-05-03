def numvote(x,y):
    firstticket = 0
    secondticket = 0
    thirdticket = 0
    for i in x:
        if i["voted"] == 1:
            firstticket+=1
        elif i["voted"] == 2:
            secondticket+=1
        elif i["voted"] ==3:
            thirdticket+=1
    ret = [firstticket,secondticket,thirdticket]
    return ret
