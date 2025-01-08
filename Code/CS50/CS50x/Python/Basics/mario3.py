### Nested Loops for rows and columns

from cs50 import *

def main():

    for i in range(3):
        for j in range(3):
            print("#", end="") # overrides the end of line value to nothing.
        print()


    for i in range(4):
        print("#" * 4)


main()