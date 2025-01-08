# Says hello to requesg.args["name"]

from flask import Flask, render_template, request

app = Flask(__name__) # __name__ is needed to check whether name of the file is 'Main'.  Take this file and make a flask web app.

# I'm in charge of the webserver, what file or files am I going to send to the Web Server
@app.route("/") # Here is the code I want the user to execute whenever user visits "/" forward flash (the default homepage of website)

def index():
    return render_template("index.html") # returns content of html with view page source, find file in templates folder by convention.
