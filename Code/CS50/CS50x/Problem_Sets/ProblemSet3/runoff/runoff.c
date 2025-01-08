#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// preferences[0][0] = 2;
// 1rst voter - 1rst rank = prefers candidate at index 2(candidate 3);
// preferences[2][1] = 0;
// 3rd voter - 2nd rank = prefers candidate at index 0 (candidate 1);

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
int indexWinner;
bool isWinner = false;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
int greatestVotesIndex();

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

    // Calculate # of voters
    voter_count = get_int("Number of voters: ");
    if(voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes - Records each voters preferences
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                i--;
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
            if(!candidates[i].eliminated)
            {
                candidates[i].votes = 0;
            }
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    int voterIndex = candidate_count + 1;

    for(int i = 0; i < candidate_count; i++)
    {
        if( strcmp(name, candidates[i].name) == 0 )
        {
            voterIndex = i;
        }
    }

    if(voterIndex == candidate_count + 1)
    {
        return false;
    }

    preferences[voter][rank] = voterIndex;

    return true;
}

// Tabulate votes for non-eliminated candidates
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
       else
       {
            //else, find that voters next, non elminated candidate
            for(int j = 1; j < candidate_count; j++)
            {
                indexCandidate = preferences[i][j];
                if(!(candidates[indexCandidate].eliminated))
                {
                    candidates[indexCandidate].votes = candidates[indexCandidate].votes + 1;
                    break;
                }
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    indexWinner = greatestVotesIndex();

    if (((float)candidates[indexWinner].votes / (float)voter_count) > 0.5)
    {
        printf("%s\n", candidates[indexWinner].name);
        return true;
    }
    else
    {
        return false;
    }
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // find least amount of votes
    int leastVotes = 0;

    for(int i = 0; i < candidate_count; i++)
    {
        if(!candidates[i].eliminated)
        {
            leastVotes = candidates[i].votes;
            break;
        }
    }

    for(int j = 0; j < candidate_count; j++)
    {
        if(!(candidates[j].eliminated))
        {
            if(candidates[j].votes < leastVotes)
            {
                leastVotes = candidates[j].votes;
            }
        }
    }

    return leastVotes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int greatestNumVotes = 0;
    indexWinner = greatestVotesIndex();
    greatestNumVotes = candidates[indexWinner].votes;

    if(greatestNumVotes == min)
    {
        return true;
    }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(!(candidates[i].eliminated))
        {
            if(candidates[i].votes == min)
            {
                candidates[i].eliminated = true;
            }
        }
    }
}

int greatestVotesIndex()
{
    indexWinner = 0;
    int greatestVotes = 0;

    for(int i = 0; i < candidate_count; i++)
    {
        if(!candidates[i].eliminated)
        {
            greatestVotes = candidates[i].votes;
            break;
        }
    }

    for(int j = 0; j < candidate_count; j++)
    {
        if(!candidates[j].eliminated)
        {
            if(candidates[j].votes > greatestVotes)
            {
                greatestVotes = candidates[j].votes;
                indexWinner = j;
            }
        }
    }

    return indexWinner;
}