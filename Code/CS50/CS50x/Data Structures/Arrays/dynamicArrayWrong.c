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

    intPtr = malloc(4 * sizeof(int)); // WRONG - creating a new block of memory using the same pointer without free'n previous
    // Garbage values now exist at the original 3 chuck memory created up top because it wasn't freed.
    intPtr[3] = 4; // You CANNOT dynamically extend the previous list and just add a new value to the end.
    // Upon malloc'n a larger size list, all the values get initialized to 0 (int list)
    // The original elements added above are no longer accessible because this pointer was reassigned to a new chuck of memory

    printf("\n");

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", intPtr[i]);
    }

    return 0;
}