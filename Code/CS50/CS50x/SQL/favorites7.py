import csv
import cs50

counts = dict()

def main():
    ...
    with open("favorites.csv", "r") as file:
        reader = csv.DictReader(file)

        for row in reader:
            favorite = row["problem"]
            if favorite in counts: # checks if value exists in the problems column
                counts[favorite] += 1 # if dictionary element already exist in count dict, increment the value by 1
            else:
                counts[favorite] = 1 # if that key:value pair does not exist, create a new dict() element and set value to 1

        favorite = input("Favorite: ")
        if favorite in counts:
            print(f"{favorite}:{counts[favorite]}")

main()