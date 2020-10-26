from flask import Flask, request, render_template, redirect, url_for, Response
app = Flask(__name__)

@app.route("/", methods=['GET'])
def homepage():
    return '<h1>This is homepage</h1>'
