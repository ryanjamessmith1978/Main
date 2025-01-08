### READABILITY ###

# Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
# Grade 3

#  0.0588 * L - 0.296 * S - 15.8 | Coleman-Liau formula
# L = the average number of letters per 100 words
# S = the average number of sentences per 100 words

from cs50 import *

def main():

    ...
    #  asks the user to type in some text
    # get_string from the CS50 Library to get the user’s input
    text = get_string("Text: ")

    # count the number of characters, letters, words, and sentences
    # characters
    numOfChars: int = len(text)
    # letters
    numOfLetters: int = 0
    numOfSpaces: int = 0
    numOfWords: int = 0
    numOfSentences: int = 0

    # count spaces (aka words), check for valid letter, and sentences
    for i in text:
        aValue = ord(i)
        if i == " ":
            numOfSpaces += 1
        elif isALetter(i):
            numOfLetters += 1
        elif (aValue == 33 or aValue == 46 or aValue == 63):
            numOfSentences += 1

    numOfWords = numOfSpaces + 1

    #print("number of letters: ", numOfLetters) # 33 | 46 | 63
    #print("number of words: ", numOfWords)
    #print("number of sentences: ", numOfSentences)

    # outputs the grade level for the text
    #  0.0588 * L - 0.296 * S - 15.8 | Coleman-Liau formula L*100/words
    L = numOfLetters * 100.0 / numOfWords
    S = numOfSentences * 100.0 / numOfWords
    gradeLevel = (0.0588 * L) - (0.296 * S) - 15.8
    gradeLevel = round(gradeLevel)

    if gradeLevel < 1:
        print("Before Grade 1")
    elif gradeLevel > 15:
        print("Grade 16+")
    else:
        print("Grade", gradeLevel)

def isALetter(letter):

    isLetter: bool = False
    asciiValue = ord(letter.upper())

    if(asciiValue > 64 and asciiValue < 91):
        isLetter = True

    return isLetter


main()