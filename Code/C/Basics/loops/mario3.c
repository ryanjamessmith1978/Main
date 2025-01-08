#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int n);

int main (void)
{
    // Get size of grid
    int numOfGrid = get_size();

    // Print grid of bricks
    print_grid(numOfGrid);
}

int get_size(void)
{
    int n = get_int("What size of squares? ");

    while (n <= 0)
    {
        n = get_int("What size of squares? ");
    }
    return n;
}

void print_grid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("# ");
        }
        printf("\n");
    }
}