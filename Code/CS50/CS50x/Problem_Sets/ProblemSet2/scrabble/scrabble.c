#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// Ascii comparison value to figure out char location in list.
const int LOWER_BOUND = 'A';

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Computes the score of a name entered
int compute_score(string word)
{
    int points = 0;
    int length = 0;
    int currentCharPos = 0;
    length = strlen(word);

    // loop through each character of the string
    for (int i = 0; i < length; i++)
    {
        // convert it to upper case, cast to int, then
        // subtract 'A' ascii value's to find position in POINTs list.
        if (islower(word[i]) || isupper(word[i]))
        {
            currentCharPos = toupper(word[i]) - LOWER_BOUND;
            // retrieve position value and add to overall points value of word.
            points = points + POINTS[currentCharPos];
        }
    }

    // printf("Points: %i\n", points);
    return points;
}

// int points = 0;
// Loop through each character in the name string
// Return that char.ToUpper()
// Convert that to an int.
// figure char position relative to ASCII table by subtracting the lowerbound capital letter.
// go to relative ascii table value via [] notation and retrive the value