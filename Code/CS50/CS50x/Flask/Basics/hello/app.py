from flask import Flask, render_template, request # web server template

# Convention in python to create a web app:
# Reason you use __name__ - to check if the name of the file contains main
# which prevents (__name__) your own library code to not be called automatically
# TURN this file into a Flask application

app = Flask(__name__)

#  what code file(s) I'm going to send to server.
# @ - decorator in Python

# This represents the default function I want the user to run when starting server.
@app.route("/")
def index():  # "name" is the variable after the ? in html name in address bar (q is what googled used to name the search bar (it's key))
    if "name" in request.args: # all key value pairs that came in via the URL
        name = request.args["name"] # need an if statement, if there was no ?name=<some name> after original URL
    else:
        name = "world"                # placeholder is a placeholder similiar to %s in C to plug into that value.
    return render_template("index.html", placeholder=name) # Need double quotes for "index.html" argument

# name = request.args.get("name", "world") # another design - cuts 4 lines to 1
#  return render_template("index.html", placeholder=name)