# AJAX example - Using both Python code and JavaScript code in this example
# Python in app.py for the web application and JavaScript for retrieving info via script tag in the search.html page.
#
# Searches for shows using Ajax
# AJAX -  Asynchronous JavaScript and XML
# Don't have submit forms anymore to get data from the server
# Use listener events (like a keypress), secretly send a request to the server to retrieve data

from cs50 import SQL
from flask import Flask, render_template, request

app = Flask(__name__)

db = SQL("sqlite:///shows.db")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/search")
def search():
    q = request.args.get("q")
    if q:
        shows = db.execute("SELECT * FROM shows WHERE title LIKE ? LIMIT 50", "%" + q + "%")
    else:
        shows = []
    return render_template("search.html", shows=shows)
