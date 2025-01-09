import csv
import cs50

counts = dict()

def main():
    ...
    with open("favorites.csv", "r") as file:
        reader = csv.DictReader(file)

        for row in reader:
            favorite = row["language"]
            if favorite in counts:
                counts[favorite] += 1
            else:
                counts[favorite] = 1

    for favorite in sorted(counts, key=get_value, reverse=True):
        print(f"{favorite}: {counts[favorite]}")


def get_value(language):
        return counts[language]

main()