// *** POPULATION ***
// Each year, n / 3 new llamas are born, and n / 4 llamas pass away.

// Prompt the user for a starting population size.
// Prompt the user for an ending population size.
// Calculate the (integer) number of years required for the population to reach at least the size of the end value
// Print the number of years required for the llama population to reach that end size

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int CalculateYears(int start, int end);

int main(void)
{
    // TODO: Prompt for start size

    int startSize = 0;
    int endSize = 0;

    do
    {
        startSize = get_int("Start size: ");

    } while(startSize < 9);

    // TODO: Prompt for end size

    do
    {
        endSize = get_int("End size: ");

    } while(startSize > endSize);

    // TODO: Calculate number of years until we reach threshold
    int years = CalculateYears(startSize, endSize);

    // TODO: Print number of years
    printf("Years: %i\n", years);


/*  Start size: 100
    End size: 200
    Years: 9
*/
}

// Don't actually care about change - focus on years
int CalculateYears(int start, int end)
{
    int years = 0;

    while(start < end)
    {
        years++;
        start = start + (start / 3) - (start / 4);
    }

    return years;
}

// Calculate the (integer) number of years required for the population to reach at least the size of the end value
// Figure out the population growth (endsize - startsize) = change.
// n/3 gained - n/4 lost
//
// 1/3 (start) - 1/4 (start) = new startPopulation - loop that
// check if new StartPopluation < endPopulation - keep looping - otherwise exit - count number of loops

//