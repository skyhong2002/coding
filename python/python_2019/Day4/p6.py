from telegram.ext import Updater, CommandHandler
from telegram.ext import MessageHandler, Filters
import random
import logging
import os
import jellyfish

waitSongs= []
dik = {}
dik["keywords"] = ['ewwf','ewewszfwez','sfds']
dik["url"] = "rdgewrrewger.sdf"
dik["name"] = 'Eric'
dik["provider"] = 'Mary'
waitSongs.append(dik)
def judge(bot, update):
    inp = update.message.text # 希望不要/answer
    if(len(waitSongs) <= 0):
        update.message.reply_text("nothing")#sky 要打
        return False
    nw = waitSongs[0]
    k = False
    for keyword in nw["keywords"]:
        fuznum = jellyfish.levenshtein_distance(inp, keyword)
        if fuznum/len(keyword) < 0.8:
            #答對ㄌ
            k = True
    if k:
        opt = "答對了！\n公佈正確答案：\n歌名：{}\n關鍵字有：".format(nw["name"])
        for keyword in nw["keywords"]:
            opt = opt + keyword + " "
        opt = opt + "\n"
        opt = opt + "影片連結：{}\n".format(nw["url"])
        opt = opt + "出題者：{}\n".format(nw["provider"])
        opt = opt + "答對的人是：{}\n".format(update.message.from_user.first_name)
        update.message.reply_text(opt)
        del waitSongs[0]
    else:
        update.message.reply_text("繼續加油")#sky 要打
    
logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                     level=logging.INFO)
updater = Updater('957812667:AAE8vX5-AO9xGw_sVoA74YC2Lrm4wQWTCro')
updater.dispatcher.add_handler(MessageHandler(Filters.text, judge))
updater.start_polling()
updater.idle()


    