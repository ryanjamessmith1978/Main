# Implements a registration form using radio buttons

from flask import Flask, render_template, request

app = Flask(__name__)

REGISTRANTS = {} # store the registered students who registered for a sport in the index form to a DICTIONARY

SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport") # <select name="sport"> needs to be added to the index.html
    if sport not in SPORTS:
        return render_template("failure.html")
    REGISTRANTS[name] = sport
    # registrants()
    return render_template("success.html")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)
# passing in a whole dictionary to the registrants html