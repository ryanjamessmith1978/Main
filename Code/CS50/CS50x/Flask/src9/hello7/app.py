
from flask import Flask, render_template, request

app = Flask(__name__)

# "/" - forward slash represents the default page, execute the code below when going to main default homepage, also known as index.
@app.route("/")
def index():
    return render_template("index.html")

# post hides the data both in the address bar and in the greet page, showing the text
# if you select inspect, network tab, click the greet page under name, payload to see the data passed into the server (PSET9)
@app.route("/greet", methods=["POST"]) # when you open the greet.html page (greet needs to be in the defaults templates folder), you route to this page,
def greet(): # execute this function greet(): which passes the placeholder value into the greet.html page.
    return render_template("greet.html", placeholder=request.args.get("placeholder", "world"))