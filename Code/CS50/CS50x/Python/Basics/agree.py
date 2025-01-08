from cs50 import *

s = input("Do you agree? ")

x = s.isnumeric()

if x == True:
    floatx = round(s, 2)
    print(floatx)

"""
if s == "y" or s == "Y":
    print("Agreed.")
elif s == "n" or s == "N":
    print("Not Agreed.")
    """

# if s in ["Y", "y"]:
#   print("Agreed.")
# elif s in ["N", "n"]:
#   print("Disagree")

# if s in ["y", "yes"]:
#   print("Agreed")

# s = input("Do you agree? ")
# s = s.lower()
# t = s.lower()

# if s in ["y", "yes"]
#   print("Agreed.")
# elif s in ["n", "no"]
#   print("Disagree")

# stings are immutable in python - they cannot change
# Bake into our dataTypes it's own built-in functionality -
# Example of Object Orientated Programming in Python