# Favorite problem instead of favorite language
from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Favorite: ")

# SELECT * FROM favorites WHERE problem = 'Mario'; # SQL Query
# rows = db.execute("SELECT * FROM favorites WHERE problem = 'Mario'")
# for row in rows:
#    print(row["Timestamp"])

rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?", favorite)
print(rows[0]["n"])

rows = db.execute("SELECT COUNT(*) FROM favorites WHERE problem = 'Mario'")
# rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = 'Mario'")
row = rows[0]
print(row["COUNT(*)"]) # print(row["n"])


"""
# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    counts = {}

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["problem"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

# Print count
favorite = input("Favorite: ")

if favorite in counts:
    print(f"{favorite}: {counts[favorite]}")

## Making statements Atomic ## (RACE Conditions)

db.execute("BEGIN TRANSACTION")
rows = db.execute("SELECT likes FROM posts WHERER id = ?", id);  id being provided previously
likes = rows[0]["likes"]
db.execute("UPDATE posts SET likes = ? WHERE id = ?", likes + 1, id);
db.execute("COMMIT")

"""