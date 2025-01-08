s = input("s: ")
t = input("t: ")

if s == t: ## no pointer in python, so you aren't comparing memory locations anymore
    print("Same")
else:
    print("Different")