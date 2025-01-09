import csv
import cs50

def main():
    ...
    with open("favorites.csv", "r") as file:
        reader = csv.DictReader(file)
        counts = dict()
        for row in reader:
            favorite = row["language"]
            if favorite in counts:
                counts[favorite] += 1
            else:
                counts[favorite] = 1

    for favorite in counts:
        print(f"{favorite}: {counts[favorite]}")


main()