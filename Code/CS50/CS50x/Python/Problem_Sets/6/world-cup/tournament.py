# Simulate a sports tournament
# Complete Main function()

import csv
import sys
import random
import math

# Number of simluations to run
N = 1000

def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # TODO: Read teams into memory from file
    csvName = sys.argv[1]
    # teams = dict() -or- teams = {}
    # teams = list() -or- newList = []

    teams = list() # a list of individual dictionaries {'name': <teamName>, 'rating': <rating>}
    count = dict() # a dictionary {"team": wins}

    infile = open(csvName, "r")
    reader = csv.DictReader(infile) # READER is a list of dictionary elements
    for row in reader: # Each ROW is a separate dictionary of (2) elements of key:value pairs, where values are related
        # teams.append(row) # Need to convert and create a new dictionary
        teamName = row['team'] # got confused here because I'm used to assigning values instead of retrieving them.
        teamRating = int(row['rating']) # team and rating are the properties, keys, or fieldnames.
        teams.append({'team': teamName, 'rating': teamRating})
        count[teamName] = 0

    """ - This is incorrect - this does not take into account a key label['team'] or value label['rating']
    for row in reader:
        x, y = row
        if(y != 'rating'):
            y = int(y)

        myDict[x] = y
        counts[x] = 0

    for item in myDict.items():
        teams.append(item)
    """

    infile.close()

    """
    myDict2 = {}

    with open(csvName, "r") as file:
        reader = csv.reader(file)
        for rows in reader:
            k, v = rows
            myDict2[k] = v
    """

    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(N):
        winner = simulate_tournament(teams)
        if winner in count:
            wins = count[winner]
            wins += 1
            count[winner] = wins

    # Print each team's chances of winning, according to simulation
    for team in sorted(count, key=lambda team: count[team], reverse=True):
        print(f"{team}: {count[team] * 100 / N:.1f}% chance of winning")

def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams): # give a list of 8 teams - a new list of 4 teams will be returned.
                            # Recursion until only one team left - set as winner.  add one to win count for that team
                            # using powers of 2 to narrow down teams?
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # Simulate all rounds for a single tournament. simulate_round(teams)
    # while(team[].len > 1 - keep calling simulate_rounds)
    # Whatever team remains, add a +1 to that teams win totals in the count = {} dictionary
    # TODO

    rounds = int((math.log(16)) / (math.log(2))) # Solve to find exponent | 16 = 2^X | x = log(y) / log(x) | 4
    for i in range(rounds):
        if len(teams) > 1:
            teams = simulate_round(teams)

    winner = teams[0]['team']
    return winner

    """
    if name in people: # even though this is an if statement, it acts as a loop, checks the key and prints its value
    number = people[name] # people["David"]
    print("Number:", number)

    """

if __name__ == "__main__":
    main()