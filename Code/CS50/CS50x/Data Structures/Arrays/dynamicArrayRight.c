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

    // Correct Way to add dynamic values to list - start by creating a new temporary int pointer with..
    // Memory size to hold 4 integers - aka an dynamic array of 4 ints.
    int *tmp = malloc(4*sizeof(int));

    // Copy the 3 previous values from original intArray pointer to new memory block represented by tmp.
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = intArray[i];
    }
    tmp[3] = 4; // add a new value to the tmp int Array, so all 4 values are in tmp array

    // Not freeing the variable intArray, but freeing the memory the address that intArray is pointing to.
    free(intArray); // frees up the memory chunk that the intArray pointer originally points to, <this doesn't delete the intArray pointer itself>
    intArray = tmp; // copies the pointer address value of tmp -> into intArray.  Aestetics.
    // Both tmp and intArray pointers point to the same memory chunk.  Altering either pointers' pointee values will affect both.

    for(int i = 0; i < 4; i++)
    {
        printf("%i\n", intArray[i]); // this could also be tmp[i], since both pointers point to the same chunk of memory.
    }

    free(intArray);
    return 0;
}