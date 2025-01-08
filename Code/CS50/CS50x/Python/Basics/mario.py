from cs50 import *

# blocks = get_int("Number of Blocks: ")
# for i in range(blocks):
def main():

    while True:
        blocks = get_int("Number of Blocks: ")
        if blocks > 0:
            loopMe(blocks)
            break

def loopMe(n):
    for i in range(n):
        print("#")

### main() ###
main()