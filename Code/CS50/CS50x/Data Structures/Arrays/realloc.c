#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    // Setting up a list dynamically - putting it on the heap
    int *intArray = malloc(3 * sizeof(int));

    // Checks if there any more memory available
    if(intArray == NULL)
    {
        return 1;
    }

    // Can still use array assignment notation for assigning values to the series of memory chunks
    // associated with the intArray pointer (aka a dynamic int array).
    intArray[0] = 1;
    intArray[1] = 2;
    intArray[2] = 3;

    // Resize of old array to be of size 4 - pass in address, and new size
    int *tmp = realloc(intArray, 4 * sizeof(int));
    tmp[3] = 5; // add a new value to the tmp int Array, so all 4 values are in tmp array

    // Realloc doesn't require programmer to manually use free<ptr> function because thats handled automatically.
    // Realloc might continue to use the same pointer address if memory exists direactly after the end of the array -or-
    // Realloc will reserve a new chunk of memory elsewhere to accomodate new size, copy contents that already existed in original memory block
    // then free up the original memory block.

    intArray = tmp; // copies the pointer address value of tmp -> into intArray.  Both tmp and intArray pointers point to the same memory chunk

    for(int i = 0; i < 4; i++)
    {
        printf("%i\n", intArray[i]); // this could also be tmp[i], since both pointers point to the same chunk of memory.
    }

    free(intArray);
    return 0;
}