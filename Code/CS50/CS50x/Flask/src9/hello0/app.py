### FLASK ### - what is Flask?  what's it for?

# HTML, CSS, JS ARE RUN in the User's broswer
# Server side is from C, Python, running code form a server, distributing code from a server
# replacing http that we used with http-server with our own web server
# https://www.example.com/routes (ROUTES)
# https://www.example.com/routes?key-value (ROUTES)
# ?key=value - Parameters in a broswer - key-value pairs
# q is the name of the html text box you type your query into for Google ?
# & separate key-value pairs. A list of multiple key value pair dictionaries, or dictionaries of dictionaries.

# http-server has been serving up html, css, JS files, but has been ignoring any http parameters
# no decisions to be made, until introducing a proper programming language on the server
# Introducing our own server, that will handle the parsing, parses our own key, value pairs.
# No additional python code needed to analyze routes, pairs, ect... when writing our own server code using Flask

# Python with Flask and Jinja (frameworks and syntax for placeholders)
# flask run - cmd for creating your own web server
# app.py is where Python code goes
# templates/ folder is where your HTML goes
# static folder/ is a convention where images, media files, ect...

from flask import Flask, render_template, request

@app.route("/")
def index():
    return hello, world