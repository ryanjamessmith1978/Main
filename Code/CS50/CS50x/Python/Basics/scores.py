from cs50 import *

def main():
    ...
    scores = [72, 73, 33]
    average = sum(scores) / len(scores)

    print("average:", + average)

    scores = []

    for i in range(3):
        score = get_int("Score: ")
        scores.append(score)
        ## scores += [score] - this does same thing as above
        ## ^ This line is creating a new list of size 1 and merges with scores

    average2 = sum(scores) / len(scores)
    print("Average2:", + average2)

    # Converting numeric string to int
    i = "123456789"
    print(int(i))

    # Converting non-numeric string to int
    x = "super"
    xValue = 0
    for char in x:
        xValue += (ord(char))
    print(xValue)


main()