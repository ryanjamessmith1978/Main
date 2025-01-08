### Finance web app ### | Manage portfolios

# register - allow users to register an account
# quote - retrieve current stock price
# buy - buy a share of stock
# index - view current stocks you own
# sell - sell a stock you own
# history - view buy/sell purchase history
# Personal Touch - (dollar image on the website)

import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

### INDEX ###
## Display HTML table with...
#  - all stocks owned
#  - number of shares of each stock
#  - current price of each stock
#  - total value of each holding
# - user's current cash balance
# - total value of stocks and cash together

# Looping using Jinja
#  {% for contact in contact %}
#   <p> {{ contact.name }} lives in {{contact.house }} </p>
#  {% endblock %}

@app.route("/")
@login_required
def index():

    user_id = session["user_id"]
    # can return a list of elements from a single SELECT query, don't need 3 separate lines of code
    userTransactions = db.execute("SELECT symbol, SUM(shares) AS shares, price FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)
    cash_dict = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    cash = cash_dict[0]["cash"] # forgot this part

    totalStockAssetBase = 0
    # [{"price":321.88,"shares":1,"symbol":"MSFT"},{"price":408.29,"shares":3,"symbol":"NFLX"},{"price":231.28,"shares":25,"symbol":"TSLA"}]
    for element in userTransactions:
        price = element["price"]
        shares = element["shares"]
        totalStockAssetBase += price * shares

    cashAndStockAssets = totalStockAssetBase + cash


    return render_template("index.html", totalAssets = cashAndStockAssets, database = userTransactions, cash = usd(cash))

    """
    symbols = db.execute("SELECT symbol FROM transactions WHERE id = ? GROUP by symbol", user_id)
    shares = db.execute("SELECT shares FROM transactions WHERE symbol = ? AND id = ?", symbols, user_id)
    price = db.execute("SELECT price FROM transactions WHERE symbol = ? AND id = ?", symbols, user_id)
    totalShareValue = shares * price
    cash = db.execute("SELECT cash FROM users WHERE id = :id", user_id) # got this right except did convert to real number
    totalAssetBase = totalShareValue + cash
    return render_template("index.html" )"""

### REGISTER ###
# Display a form the user can register to with a submit button
@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "GET":
        return render_template("registration.html")
    else:
        username = request.form.get("username")
        if not username:
            return apology("No username entered")

        password = request.form.get("password")
        if not password:
            return apology("No password entered")

        confirmation = request.form.get("confirmation")
        if not confirmation:
            return apology("No confirmation entered")

        if(confirmation != password):
            return apology("Password doesn't match confirmation")

        hash = generate_password_hash(password)

        try:
            new_user = db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)
        except:
            return apology("Name already exists")

        session["user_id"] = new_user
        return redirect("/")

    # POST submits the form and inserts a new user into the user's table of the finance.db
    # Auto log the user in after submitting form
    # Use if checks to verify the registration is correct

    # add the user to the database securely
    # use generate_password_hash (no plain text pwds) - then store the hash of the password inside the db
    # use db.execute(INSERT ...) - use ? for placeholders
    # then log user in session["user_id"]

### QUOTE ###
@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    ### GET ### - display form to request a stock quote (Display Form)
    if request.method == "GET":
        return render_template("quote.html")
    else:
        ### POST ### - lookup stock symbol by calling lookup function, to display results (Display search results)
        ## Lookup() - takes stock symbol, returns a quote, if success, returns a dict{} with name, price, symbol, otherwise returns None.
        # if lookup is success - display stock.html showing stock info - passing values into quoted.html template

        symbol = request.form.get("symbol")
        if not symbol:
            return apology("Please enter a stock symbol")

        ### stock will be a dictionary - {"name": symbol, "price": price, "symbol": symbol}
        stock = lookup(symbol.upper())

        if stock == None or not stock:
            return apology("Symbol doesn't exist")

        ### sending data form the backend to the frontend
        return render_template("quoted.html", name=stock["name"], price=stock["price"], symbol=stock["symbol"])

        """
        try:
            quote_py = lookup(request.form.get("quote")) # request.form.get("quote") should store a local variable before doing lookup
        except:
            return apology("Invalid Stock Symbol")

        return render_template("quoted.html", quotes=quote_py) # unable to send entire dictionary, need to send 3 individual dict{} values
        """

### BUY ###
@app.route("/buy", methods=["GET", "POST"]) # POST submits data securely
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        stockName = request.form.get("symbol")
        if not stockName:
            return apology("Enter stock symbol in input field")

        sharesCheck = request.form.get("shares")

        if not sharesCheck.isdigit():
            return apology("Invalid shares input")
        else:
            shares = int(float(sharesCheck))

        if shares < 0:
            return apology("You cannot purchase 0 or less shares.")

        stock = lookup(stockName)
        if stock == None:
            return apology("Not a valid stock symbol")

        transaction_value = stock["price"] * shares

        # Wrong  but close, need WHERE and lookup filtering by id, not cash
        # userTotal = db.execute("SELECT cash FROM users (cash) VALUES(?)", row[0][cash])
        user_id = session["user_id"]
        userTotal = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        cashTotal = userTotal[0]["cash"]

        if cashTotal < transaction_value:
            return apology("Not enough money")

        newCashTotal = cashTotal - transaction_value

        db.execute("UPDATE users SET cash = ? WHERE id = ?", newCashTotal, user_id)
        date = datetime.datetime.now()

        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES(?, ?, ?, ?, ?)",
                   user_id, stock["symbol"], shares, stock["price"], date)

        flash("Bought!")

        return redirect("/")


### SELL ###
@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        user_id = session["user_id"]
        symbols_user = db.execute("SELECT symbol FROM transactions WHERE user_id = :id GROUP BY symbol HAVING SUM(shares) > 0", id=user_id)
        return render_template("sell.html", symbols = [row["symbol"] for row in symbols_user])
    else:
        stockName = request.form.get("symbol")
        if not stockName:
            return apology("Enter stock symbol in input field")

        shares = int(request.form.get("shares"))
        if shares < 1:
            return apology("Enter a valid number of shares")

        stock = lookup(stockName)
        if stock == None:
            return apology("Not a valid stock symbol")

        transaction_value = stock["price"] * shares

        # Wrong  but close, need WHERE and lookup filtering by id, not cash
        # userTotal = db.execute("SELECT cash FROM users (cash) VALUES(?)", row[0][cash])
        user_id = session["user_id"]
        userTotal = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        cashTotal = userTotal[0]["cash"]

        user_shares = db.execute("SELECT shares FROM transactions WHERE user_id=:id AND symbol=:symbol GROUP BY symbol",
                                 id=user_id, symbol=stockName)

        user_shares_real = user_shares[0]["shares"]

        if shares > user_shares_real:
            return apology("You don't have enough shares to sell")

        newCashTotal = cashTotal + transaction_value

        db.execute("UPDATE users SET cash = ? WHERE id = ?", newCashTotal, user_id)
        date = datetime.datetime.now()

        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES(?, ?, ?, ?, ?)",
                   user_id, stock["symbol"], -1*shares, stock["price"], date)

        flash("SOLD!")

        return redirect("/")

### HISTORY ###
@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    transactions_db = db.execute("SELECT * FROM transactions WHERE user_id = :id", id=user_id)
    return render_template("history.html", transactions = transactions_db)

    ## Display an html table with a history of all transactions
    ## One row for every buy or sell
    ## Information about what and how many stocks bought or sold, and when the transactions took place
    ## Revise database?

### CASH ###
@app.route("/addFunds", methods=["GET", "POST"])
@login_required
def addFunds():
    """Adding funds to Wallet"""
    user_id = session["user_id"]

    if request.method == "GET":
        return render_template("addCash.html")
    else:
        new_cash = int(request.form.get("addedFunds"))

        if not new_cash:
            return apology("Add some money")

        userTotal = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        cashTotal = userTotal[0]["cash"]

        newCashTotal = cashTotal + new_cash

        db.execute("UPDATE users SET cash = ? WHERE id = ?", newCashTotal, user_id)

        flash("ADDED MORE CASH!")

        return redirect("/")


### LOGIN ###
@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


