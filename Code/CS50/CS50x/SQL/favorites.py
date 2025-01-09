from cs50 import *
import sys
import csv

with open("favorites.csv", "r") as openfile:
    ...
    reader = csv.reader(openfile)
    for row in reader:
        ...
        favorite = row[1]
        print(favorite) # print the second element of a row | timestamp, language, problem
                      # language