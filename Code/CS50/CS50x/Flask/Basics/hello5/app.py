### HELLO2 ###
### Multiple routes with multiple HTML files (index2 and greet)
from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/greet", methods=["POST"])
def greet():
    return render_template("greet.html", name=request.args.get("name", "world"))
