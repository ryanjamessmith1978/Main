// *** Readability ***

// Coleman-Liau index
// index = 0.0588 * L - 0.296 * S - 15.8
// L is the average number of letters per 100 words
// S is the average number of sentences per 100 words


#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>

const int WHITESPACE = 32;
const int EXCLAMATION = 33;
const int PERIOD = 46;
const int QUESTIONMARK = 63;

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);
    int whitespace = 0;
    int words = 0;
    int letters = 0;
    int sentences = 0;
    int years = 0;

    // Calculate words. Look for whitespace.  Whitespace + 1;
    for(int i = 0; i < length; i++)
    {
        if ( (int)text[i] == WHITESPACE)
        {
            whitespace++;
        }
        else if( (int)text[i] == EXCLAMATION || (int)text[i] == PERIOD || (int)text[i] == QUESTIONMARK)
        {
            sentences++;
        }
        else if( (int)(toupper(text[i])) > 64 && (int)(toupper(text[i])) < 91 )
        {
            letters++;
        }
    }

    words = whitespace + 1;

    // Letters and Sentences per 100 words.
    double L = ((double)letters / (double)words) * 100.0;
    double S = ((double)sentences / (double)words) * 100.0;

    // index = 0.0588 * L - 0.296 * S - 15.8
    years = round( (double)(0.0588 * L) - (double)(0.296 * S) - (double)15.8);

    // Words
    //printf("Number of words: %i\n", words); // One less space than total words, +1.

    // Calculate letters (L) average letters / 100 words
    //printf("Number of letters: %i\n", letters);

    // Calculate sentences (S) average sentence / 100 words
    //printf("Number of sentences: %i\n", sentences);
    if (years < 1)
    {
         printf("Before Grade 1\n");
    }
    else if (years > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", years);
    }
}