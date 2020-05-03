from flask import Flask, request, render_template, redirect, url_for, Response
app = Flask(__name__)

messages = [
    ('mocha', '真相只有一個！'),
    ('rilak', '好想睡覺QAQ'),
    ('abbie', '?'),
    ('melody', '幫QQ'),
    ('hortune', 'YO!'),
]

@app.route("/", methods=['GET'])
def homepage():
    return '<h1>This is homepage</h1>'



@app.route("/show", methods=['GET'])
def show_message():
    result = ''
    for message in messages:
        result += '<p>' + message[0] + ':「' + message[1] + '」</p>'
    return result


@app.route("/new", methods=['GET', 'POST'])
def add_message():
    
    return redirect(url_for('homepage'))
