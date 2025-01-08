### COOKIES ### - Flask manages cookies for you automatically, setting and checking

from flask import Flask, redirect, render_template, request, session #
from flask_session import Session # session variable is a dictionary (shopping cart) - used for cookies

# Configure app
app = Flask(__name__)

# Configure session
app.config["SESSION_PERMANENT"] = False # this is how to enable a session in a web application
app.config["SESSION_TYPE"] = "filesystem" # storing the session information on the web server itself
Session(app)


@app.route("/")
def index(): # common paradigm for establishing a session
    if not session.get("name"):
        return redirect("/login")
    return render_template("index.html")


@app.route("/login", methods=["GET", "POST"]) # if user visits /login via GET or POST call login function
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name") # store in this special SESSION variable a "name" key and store it in the user's name
        return redirect("/") # redirect back to home page
    return render_template("login.html") # otherwise visit via GET, show them the login screen again


@app.route("/logout")
def logout():
    session["name"] = None # change the value of that specific session's key's value to None.
    return redirect("/")
