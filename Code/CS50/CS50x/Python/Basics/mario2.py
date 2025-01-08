## Converting input - TRY

def main():
    height = get_height()
    for i in range(height):
        print("#")


def get_height():
    while True:
        try:  ## This checks for valid integer input and return with error message if it doesn't
            n = int(input("Height: ")) ## n is defined in the loop
        except ValueError:
            print("Not an number")
            return 0

        if n > 0: ## this checks for a negative value, breaks and returns value if it is a positive num.
            break

    return n ## python ignores scope - n can be returned after breaking out of the while loop


main()