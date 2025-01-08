#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

int main (void)
{
    int scores[3];
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", scores[i]);
    }

    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42; // assign the memory address that int x pointer points to the value of 42
    // *y = 13; // FAIL - Need to assign memory first to y before storing a value in it.


}