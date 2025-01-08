#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Linear Search - O(n)

const int arrayNum = 6;

int main(void)
{
    //
    string strings[arrayNum] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("Name: ");

    for (int i = 0; i < arrayNum; i++)
    {
        // unlike numbers, strings can't use ==.
        if (strcmp(s, strings[i]) == 0) // Need <string.h> and use strcmp() - strings are just memory addresses
        {
            printf("Found\n");
            return 0;
        }
    }

    printf("Not Found\n");
    return 1;
}