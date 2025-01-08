#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    // delcares an int pointer - creates a chunk of memory for holding 3 ints
    // assigns pointer the memory address of that start of that memory chunk
    int *intPtr = malloc(3*sizeof(int));
    intPtr[0] = 1;
    intPtr[1] = 2;
    intPtr[2] = 3;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", intPtr[i]);
    }

    // Clobbering the value of list - don't point at this chunk of memory - point at this new chunk of memory
    // And I forgot where the old chunk of memory and now garbage data exists.

    intPtr = malloc(4 * sizeof(int)); // WRONG - creating a new block of memory with the intArray pointer pointing to new block
    intPtr[3] = 4; // WRONG - this will assign the value 4 to the to the 4th index of intArray, but the other 3 values from intArray are gone.

    printf("\n");

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", intPtr[i]);
    }

    return 0;
}