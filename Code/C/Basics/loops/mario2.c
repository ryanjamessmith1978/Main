#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int n;
    do
    {
        n = get_int("Size Squared: ");
    }
    while (n <= 0);

    for (int i = 0; i < n; i++)
    {
        // Fills the current row per 'n' number of columns
        for (int j = 0; j < n; j++)
        {
            printf("# ");
        }
        printf("\n");
    }
}