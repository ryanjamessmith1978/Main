// *** PLURALITY VOTE ***
// Complete the vote function
// Vote takes a single argument, a string called name, representing the name of the candidate who was voted for.
// If name matches one of the names of the candidates in the election, then update that candidate’s vote total to account for the new vote.
// The vote function in this case should return true to indicate a successful ballot.
// If name does not match the name of any of the candidates in the election, no vote totals should change

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        while(!vote(name))
        {
            printf("Invalid vote.\n");
            name = get_string("Vote: ");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // check if name is in array
    for (int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }
    // add one to vote total
    // return true

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int mostVotes = candidates[0].votes;
    int winnerIndex = 0;
    int winnersArray[MAX];
    winnersArray[0] = 0;
    int totalTied = 0;

    for(int i = 1; i < candidate_count; i++)
    {
        if(candidates[i].votes > mostVotes)
        {
            mostVotes = candidates[i].votes;
            winnerIndex = i;
        }
        else if(candidates[i].votes == mostVotes)
        {
            totalTied++;
            winnersArray[totalTied] = i;
        }
    }

    if(totalTied > 0)
    {
        for(int i = 0; i <= totalTied; i++)
        {
            printf("%s\n", candidates[winnersArray[i]].name);
        }
    }
    else
    {
        printf("%s\n", candidates[winnerIndex].name);
    }

    return;
}

// $ ./plurality Alice Bob
// Number of voters: 3
// Vote: Alice
// Vote: Bob
// Vote: Alice
// Alice