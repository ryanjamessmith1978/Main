#include <cs50.h>
#include <stdio.h>

void printBlocks(int num);

int main(void)
{
    int height = 0;

    do
    {
        height = get_int("What is the block height: ");
    }
    while((height < 1) || (height > 8));

    printBlocks(height);
}

void printBlocks(int num)
{
    int spaces;

    for (int i = 1; i <= num; i++)
    {
        spaces = num - i;

        for (int j = num; j > 0; j--)
        {
            if (spaces > 0)
            {
                spaces--;
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}