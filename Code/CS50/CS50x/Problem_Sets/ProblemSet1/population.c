#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Say we have a population of n llamas. Each year,
    // n / 3 new llamas are born, and n / 4 llamas pass away.

    // TODO: Prompt for start size

    int startSize;
    int endSize;

    do
    {
        startSize = get_int("What is the starting population of llamas: ");
    }
    while(startSize < 9);

    printf("\n");

    // TODO: Prompt for end size
    do
    {
        endSize = get_int("What is the ending population of llamas: \n");
    }
    while(startSize > endSize);

    printf("\n");

    // TODO: Calculate number of years until we reach threshold

    int years = 0;

    while(endSize > startSize)
    {
        startSize = startSize + (startSize / 3) - (startSize / 4);
        years++;
    }

    printf("Years: %i\n", years);
}