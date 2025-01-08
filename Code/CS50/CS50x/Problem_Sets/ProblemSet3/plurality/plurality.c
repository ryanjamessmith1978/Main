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
    if(candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for(int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for(int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            while(!vote(name))
            {
                name = get_string("Vote: ");
            }
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    bool isVoter = false;

    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            isVoter = true;
        }
    }

    return isVoter;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int greatest = candidates[0].votes;
    int voterIndex = 0;
    int tieIndex[MAX] = {0};
    int currentTieIndex = 0;

    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes > greatest)
        {
            greatest = candidates[i].votes;
            voterIndex = i;
        }
        else if(candidates[i].votes == greatest)
        {
            tieIndex[currentTieIndex] = i;
            currentTieIndex++;
        }
    }

    string name = candidates[voterIndex].name;;
    printf("%s\n", name);

    for(int i = 0; i <= currentTieIndex; i++)
    {
        if(tieIndex[i] > 0)
        {
            string winner = candidates[tieIndex[i]].name;
            printf("%s\n", winner);
        }
    }

    return;
}