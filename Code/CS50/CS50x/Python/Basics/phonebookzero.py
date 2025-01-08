## Dictionary
# people = dict()
people = {
    "Carter": "+1-617-495-1000",
    "David": "+1-949-468-2750"
}

name = input("Name: ")
if name in people: # even though this is an if statement, it acts as a loop, checks the key and prints its value
    number = people[name] # people["David"]
    print("Number:", number)
    #print(f"Number: {people[name]}")