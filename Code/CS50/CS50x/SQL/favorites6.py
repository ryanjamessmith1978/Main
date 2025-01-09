# using lambas
import csv
import cs50

def main():
    ...
    counts = dict()

    with open("favorites.csv", "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            favorite = row["problem"]
            if favorite in counts:
                counts[favorite] += 1
            else:
                counts[favorite] = 1

    for favorite in sorted(counts, key=lambda problem: counts[problem], reverse=True):
        print(f"{favorite}: {counts[favorite]}")

main()