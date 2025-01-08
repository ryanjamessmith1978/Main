# Adds a form and a second route
# <--- ROUTES --->
# Creation of a webform that submits whatever the value of text box is to a ROUTE called /greet -->
# /greet is not a http or domain,  it's assumed it corresponds to whatever my own server's URL is, explicit prefix to the route -->

from flask import Flask, render_template, request

app = Flask(__name__) # Creating a web app

# Programmer decides what to do - based on the browser's request - what file I'm going to send from my web server to the browser
# Here is a code I want to execute on the web server, whenever the user logs into the default page.

# So, the default route("/") is called by the user, triggers automatically, when clicking on web server's default homepage.
# Other routes like /greet are called internally from the server, serving additional actions for the server to push back to the user.  
@app.route("/")
def index(): #
    return render_template("index.html")

@app.route("/greet")
def greet():
    return render_template("greet.html", placeholder=request.args.get("name", "world"))
    # "name" is the key for the args dictionary
    # .get is a method for checking whether an argument was submitted via form (or left it blank) when hitting submit button
    # "name" could be labeled with any variable name
    # As long as the first argument of args.get("") contains that same "field" as the
    # right hand value of <input name=""> of the index.html form tag, then this will work.
    # args.get("name", "")) =  <input name="name" ... the "name" in double quotes needs to be the same