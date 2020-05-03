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
def show_message():
    name = request.args.get('name', '')
    result = "The name '" + name + "' not found"
    for message in messages:
        if message[0] == name:
            result = '<p>' + message[0] + ':「' + message[1] + '」</p>'
    return result

@app.route("/all", methods=['GET'])
def show_all_message():
    result = ''
    for message in messages:
        result += '<p>' + message[0] + ':「' + message[1] + '」</p>'
    return result