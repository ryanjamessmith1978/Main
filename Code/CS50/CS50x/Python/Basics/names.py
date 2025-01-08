import sys

names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"] # list

name = input("Name: ")

for n in names:
    if name == n:
        print("Found")
        sys.exit(0)

# if name in names:
  #  print("Found")
   # sys.exit(0)

print("Not Found")
sys.exit(1)