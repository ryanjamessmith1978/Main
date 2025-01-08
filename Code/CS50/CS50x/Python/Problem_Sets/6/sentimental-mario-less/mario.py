# bool value to indicate whether input is non-numeric
isInt = True

try:  # ask for user input for the height of half-pyramid
    height = int(input("Height: "))
except ValueError:
    isInt = False  # if a letter is entered, bool is set False

# continue prompting user for input until input is valid, non-numeric between 1 and 8 inclusive
while isInt == False or height <= 0 or height >= 9:
    try:
        height = int(input("Height: "))
        isInt = True
    except ValueError:
        isInt = False

spaces = height
pounds = 0

# print blocks while decrementing in the loop
while spaces > 0:
    spaces -= 1
    pounds = height - spaces
    print(spaces * " " + pounds * "#")
