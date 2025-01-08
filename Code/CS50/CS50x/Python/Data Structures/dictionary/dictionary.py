### DICTIONARY ###

words = set()

def check(word):
    if word.lower() in words:
        return true
    else:
        return false

def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        word = line.rstrip()
        words.add(word)
    close(file)
    return True

def size():
    return len(words)

def unload():
    return True