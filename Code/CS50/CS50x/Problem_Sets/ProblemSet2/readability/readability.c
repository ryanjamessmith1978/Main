#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculateGradeLvl(int let, int word, int sent);
void printOutValues(int let, int word, int sent);

// Figure out number of letters
// Figure number of words
// Figure out number of sentences
// Calculate out Letter / Word * 100 = L
// Calculate Sent/Words * 100 = S

int main(void)
{
    // Get User input
    string text = get_string("Text: ");

    // Count letters, words, sent
    int letterCount = count_letters(text);
    int wordCount = count_words(text);
    int sentenceCount = count_sentences(text);
    // printOutValues(letterCount, wordCount, sentenceCount);
    // printf("%s\n", text); // re-print text

    int gradeLvl = calculateGradeLvl(letterCount, wordCount, sentenceCount);

    if (gradeLvl < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }

    if (gradeLvl > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }

    printf("Grade %i\n", gradeLvl);
}

// Returns num of letters
int count_letters(string text)
{
    int count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        char n = text[i];

        if ((n > 64 && n < 91) || (n > 96 && n < 123))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    // count spaces + 1
    for (int i = 0; i < strlen(text); i++)
    {
        char n = text[i];

        if (n == 32)
        {
            count++;
        }
    }

    count = count + 1;

    return count;
}

int count_sentences(string text)
{
    int count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        char n = text[i];

        if (n == 33 || n == 46 || n == 63)
        {
            count++;
        }
    }
    return count;
}

// Calculates grade level dependent on arguments passed in using
// the Coleman-Liau index method
int calculateGradeLvl(int let, int word, int sent)
{
    int grade;

    double L = ((double) let / (double) word) * 100.0;
    double S = ((double) sent / (double) word) * 100.0;

    // The Coleman-Liau index
    grade = round(0.0588 * L - 0.296 * S - 15.8);

    return grade;
}

// index = 0.0588 * L - 0.296 * S - 15.8
// L is the average number of letters per 100 words in the text
// S is the average number of sentences per 100 words in the text

void printOutValues(int let, int word, int sent)
{
    printf("Letters: %i\n", let);
    printf("Words: %i\n", word);
    printf("Sentences: %i\n", sent);
}