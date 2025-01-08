from cs50 import *

def main():

    ...
    validInput = True
    numCoins = 0.0


    try:
        change = get_float("Change owed: ")
        if change < 0.0:
            validInput = False
    except ValueError:
        validInput = False

    while validInput == False:
        try:
            change = get_float("Change owed: ")
            if change < 0.0:
                validInput = False
            else:
                validInput = True
        except ValueError:
            validInput = False

    # print(validInput)
    coins, change = numQuarters(change)
    numCoins += coins
    coins, change = numDimes(change)
    numCoins += coins
    coins, change = numNickels(change)
    numCoins += coins
    coins, change = numPennies(change)
    numCoins += coins

    print(int(numCoins))


def numQuarters(money):
    ...

    coins = int(money / 0.25)
    change = money % 0.25
    if(change > 0):
        change = "{:.2f}".format(change)

    return coins, float(change)


def numDimes(money):
    ...
    coins = int(money / 0.10)
    change = money % 0.10
    if(change > 0):
        change = "{:.2f}".format(change)

    return coins, float(change)


def numNickels(money):
    ...
    coins = int(money / 0.05)
    change = money % 0.05
    if(change > 0):
        change = "{:.2f}".format(change)

    return coins, float(change)


def numPennies(money):
    ...
    coins = money * 100
    change = 0

    return coins, float(change)



main()