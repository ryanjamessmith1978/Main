// *** scrabble ***
// Compute scrabble score using the POINTS array, and return the score for the string argument
// Characters that are not letters should be given zero points,
// Uppercase and lowercase letters should be given the same point values

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int pointsArrSize = 26;

// Points assigned to each letter of the alphabet
int POINTS[pointsArrSize] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
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

// Player 1: COMPUTER
// Player 2: science
// Player 1 wins!

int compute_score(string word)
{
    int score = 0;
    int charValue = 0;
    int index = 0;

    int length = strlen(word);
    char letter;

    // Loop through string one character at a time
    for(int i = 0; i < length; i++)
    {
        letter = toupper(word[i]);

        if( (int)letter > 64 && (int)letter < 91)
        {
            // find the based on letterindex of points array 0-25, a = 0, ect...
            // index'd letter equivalent in ascii (65 - 90) - ASCII upper
            index = (int)letter - 65;
            charValue = POINTS[index];
            score = score + charValue;
        }
    }

    return score;
}