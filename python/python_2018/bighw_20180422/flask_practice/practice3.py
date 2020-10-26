from flask import Flask, request, render_template, redirect, url_for, Response
app = Flask(__name__)

messages = [
    ('mocha', '真相只有一個！'),
    ('rilak', '好想睡覺QAQ'),
    ('abbie', '?'),
    ('melody', '幫QQ'),
    ('hortune', 'YO!'),
]

@app.route("/", methods=['GET', 'POST'])
def homepage():
    #handle GET method
    if request.method == 'GET':
        #這裡有一個bug，真ㄉ是故意的
        return render_template('index.html', message_pool=message)

    #handle POST method
    name      = request.form['from_user']
    content   = request.form['new_message']
    messages.append( (name, content) )
    return redirect(url_for('homepage'))
