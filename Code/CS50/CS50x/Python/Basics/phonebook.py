# phonebook with csv.writer
import csv

file = open("phonebook.csv", "a") # append, doesn't write over what's already there ('w') - write writes over what's there

name = input("Name: ")
number = input("Number: ")

writer = csv.writer(file)

writer.writerow([name, number])

file.close()