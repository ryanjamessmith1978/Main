# phonebook with csv.DictWriter
# allows you  to mix up the columns, dictreader will auto-associate

import csv

file = open("phonebook.csv", "a")
## with open("phonebook.csv", "a") as file: ##(need to indent and remove file.close())

name = input("Name: ")
number = input("Number: ")

writer = csv.DictWriter(file, fieldnames=["name", "number"])
writer.writerow({"name": name, "number": number})

file.close()

## with open("phonebook.csv", "a") as file: