# Uses parameter with same name as variable

# Couldn't do this part with http-server!
# Python will allow us to access the http parameters
# Using the reequest variable - request.args
from flask import Flask, render_template, request

app = Flask(__name__)
@app.route("/")  # What data type is request.args?  Dictionary
def index():     # request.args are all the key-value pairs that have come in via the URL ?key=value (?x=Name)
    if "x" in request.args: # x is the key for the key-value pair that goes at the end of the url (?x=)
        Name = request.args["x"] # Name is VALUE of the key-Value pair that gets referenced via request.args dictionary (the args dictionary)
    else:
        Name = "world"
    return render_template("index.html", placeholder=Name) #placeholder is a placeholder field name from html page where the
                                                        # placeholder variable name needs to match exactly the field name is curly braces
                                                        # in the html page


# 3 dependencies for these dictionaries / html field parameters passing data into the web server:
# * Whatever field is in quotes (eg."placeholder") is the key field for the address bar of the URL. (?placeholder=)
# * Name is value of the key-value pair that is passed into the url,
#  name is retrieved as part of the request.args function (native to Flask), name needs to be the value assigned as a RHV in the return.
# * The 3rd dependency is with the 2nd arugment passed into render-template (x=Namea)
# Whatever variable name is chosen for value to be stored in (x in this case), needs to be the same name as the field in
