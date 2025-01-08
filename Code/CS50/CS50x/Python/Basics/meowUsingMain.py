## Using Main
## Main needs to be defined up top and called at bottom
## Calling main at the bottom means below all other function definitions (not prototypes, definitions)
## Don't need prototypes.  While main may seem like a prototype, it's not, its just
## another function definition.

def main():
    for i in range(3):
        meow()

    print()
    meowTwo(2)

def meow():
    print("meow")

def meowTwo(n):
    for i in range(n):
        print("Meow2")

main()






