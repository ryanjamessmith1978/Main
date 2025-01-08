#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdbool.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;
int maxVotes = 0;
int indexWinner = 0;
int rankIndex = 0;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

// *** MAIN ***
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if(!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();


        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }

    return 0;

}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // candidates

    for(int i = 0; i < candidate_count; i++)
    {
        if(!candidates[i].eliminated)
        {
            if(strcmp(name, candidates[i].name) == 0)
            {
                // Populate preferences array
                // int preferences[MAX_VOTERS][MAX_CANDIDATES];
                preferences[voter][rank] = i;

                return true;
            }
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
// Having trouble getting the correct output for multiple eliminated candidates
void tabulate(void)
{
    int indexCandidate = 0;
    indexWinner = 0;

    // for each voter
    for(int i = 0; i < voter_count; i++)
    {
        // find their 1rst preference - find that candidates index
       indexCandidate = preferences[i][0];

       // if not eliminated add one to vote
       if(!(candidates[indexCandidate].eliminated))
       {
            candidates[indexCandidate].votes = candidates[indexCandidate].votes + 1;
       }
       else // if first preference is eliminated, loop through that voter's next candidate
       {
            //else, find that voters next, non-eliminated candidate
            for(int j = 1; j < candidate_count; j++) // looping based on number of candidates
                                                     // loop starts at 1 because we are starting at 2nd preference (or index 1)
                                                     // ends at less than candidate_count because, the index of preferences for candidates
                                                     // will still be number of candidates less one because of index 0.
            {
                indexCandidate = preferences[i][j]; // selecting the voter's [i] - [j]th preference
                                                    // if voter's [i], [j]th preference is not eliminated
                                                    // add one vote to that candidate and break out of inner loop
                                                    // onto next voter - when all voter's are accounted for break both loops, return.
                if(!(candidates[indexCandidate].eliminated))
                {
                    candidates[indexCandidate].votes = candidates[indexCandidate].votes + 1;
                    break;
                }
            }
        }
    }

    // *** IMPORTANT *** Once I realized I didn't understand what the problem was asking, I should have re-done this function from scratch

    /*
    int candidateIndex;

    // grab the first place votes
    for(int i = 0; i < voter_count; i++)
    {
        candidateIndex = preferences[i][0];
        if(!candidates[candidateIndex].eliminated)
        {
            candidates[candidateIndex].votes = candidates[candidateIndex].votes + 1;
        }
    }

    int min = find_min();

    // whoever has the minimum number of votes - find the voter who voted for them and select their next ranked candidate
    for(int i = 0; i < voter_count; i++)
    {
        candidateIndex = preferences[i][rankIndex];

        if(!(candidates[candidateIndex].eliminated) && candidates[candidateIndex].votes == min)
        {
            candidateIndex = preferences[i][rankIndex+1];
            candidates[candidateIndex].votes = candidates[candidateIndex].votes + 1;
        }
    }


    rankIndex++; // changes the rank preference to the next one for comparing votes

    return;
    */
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int majorityVote = voter_count / 2;

    for(int i = 0; i < candidate_count; i++)
    {
        if(!(candidates[i].eliminated))
        {
            if(candidates[i].votes > majorityVote)
            {
                printf("%s\n", candidates[i].name);
                return true;
            }
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int candidateIndex = 0;
    int minVotes;

    for(int j = 0; j < candidate_count; j++)
    {
        if(!candidates[j].eliminated)
        {
            candidateIndex = j;
            break;
        }
    }

    minVotes = candidates[candidateIndex].votes;

    for (int i = candidateIndex; i < candidate_count; i++)
    {
        if(!(candidates[i].eliminated))
        {
            if (candidates[i].votes <= minVotes)
            {
                minVotes = candidates[i].votes;
            }
        }
    }

    return minVotes;
}

// Return true if the election is tied between all candidates, false otherwise
// Struggled with the tie logic, passing in a min value seems counterintuitive to me
// This tie function doesn't fully work - see other problem set folder for correct solution.
bool is_tie(int min)
{
    bool isTied = false;
    int numTied = 0;

    // check each candidates votes and if they equal min votes, and add to array.
    for(int i = 0; i < candidate_count; i++)
    {
        if(!candidates[i].eliminated)
        {
            // STOP overthinking solution, didn't need a new array, just an int value
            if(candidates[i].votes == min && candidates[i].votes == maxVotes)
            {
                numTied++;
            }
        }
    }

    if(numTied > 0)
    {
        return true;
    }

    return isTied;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Checks each candidate to see if their vote total is equal to the min votes,
    // Eliminates the candidates that meet that condition
    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }

    return;
}