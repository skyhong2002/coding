import random, os
from telegram.ext import Updater, CommandHandler, MessageHandler, Filters
    



updater = Updater('看誰要創ㄍOuO')

def importMusic(bot, update):
    
    #選擇第0個檔案
    

    #傳送音訊
    bot.send_audio(chat_id=chat_id, audio=open('tests/test.mp3', 'rb'))

def judge(bot, update):
    inp = update.message.text # 希望不要/answer
    now = waitSongs[0]
    for keyword in now.keywords:
        fuznum = fuzCmp(inp, now)
        if fuznum > 0.7:
            #答對ㄌ
            return True
        else
            #告訴大家幾成對（？
            continue
    return False



def announce(bot, update):
    song = waitSongs[0]



updater.start_polling()
updater.idle()