### HELLO2 ###
### Multiple routes with multiple HTML files (index2 and greet)
from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index2.html")

# Creating my own back-end
# route changes
# Instead of submitting form to Google (previous example),
# I'm implementing to myself, to my own back-end to same front-end.
@app.route("/greet")
def greet():
    name = request.args.get("name", "world")
    return render_template("greet.html", name=name) # first name is placeholder in greet.html
                                                    # second name is the variable created in line above.