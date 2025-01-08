// Even though this file is called list,
// This list.c file is actually an example of int arrays and int pointers for copying Arrays

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int list[3]; // a little confusing since I think of lists as pointers, but list is just an array var name here

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for(int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }

    printf("List2: \n");

    int size = 7;
    int *list2 = malloc(size * sizeof(int)); // int pointer is analogous to an int array - just grabbing a chunk of memory.
    // You can use pointers like arrays, just malloc for size intended or unintended output is likely.
    // You can add pointers to outside of the bounds, but then don't allocate another int* with malloc.

    for(int j = 0; j < size; j++)
    {
        list2[j] = j+1;
    }

    for(int i = 0; i < size; i++)
    {
        printf("%i\n", list2[i]);
    }

    /*
    list2[0] = 4; // *list1 = 4; // Can you index a pointer to search or assign a value.
    list2[1] = 5; // *(list+1) = 5;
    list2[2] = 6; // *(list2 + 2) = 6;
    list2[3] = 7;
    list2[4] = 8;
    list2[6] = 9;
    */

    // list2 = list; // This will compile, but will cause logic errors based on code below.
    // You can assign an array to a pointer, but not vice versa
    // printf("%i\n", list[4]); // index 4 is past end of array [declared with size 3]
    //printf("%i\n", list2[4]); // prints value at index 4 of the int ptr
    // which going to int ptr memory address and adding 4 blocks of int memory


    int *tmp = malloc(5 * sizeof(int));
    if(!tmp) {free(list2); return 1;}

    for(int i = 0; i < 3; i++)
    {
        tmp[i] = list2[i];
    }
    tmp[3] = 7;

    //free(list2);

    list2 = tmp; // This works because list and tmp are both just int *pointers.
                // Even though list memory allocation was only 3 and tmp is 4 - both are just pointers, not memory chunks
    // both tmp and list pointers are pointing to the malloc memory allocation in line 29.

    //free(list); // NOT free(tmp) - because this is the new chunk of memory

    printf("ADD 4th Value to TMP Pointer - reassign list2 pointer to point to tmp pointer - print List2 values.\n");

    for(int i = 0; i < 4; i++)
    {
        printf("%i\n", list2[i]);
    }

    //free(list2);


}