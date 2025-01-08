#include <cs50.h>
#include <stdio.h>

// Use an asterick (*) before a pointer variable to dereference it.
int main(void)
{
    int n = 50;
    int *p = &n; // pointer p declared && pointer p assigned the value of the memory address of int variable n.

    printf("\n");
    printf("Memory address of pointer p: %p\n", p); // displays the memory address because it references the variable (p) directly.
    printf("Deference pointer p (*p) to get value associate'd with p's address. \n");

    // De-reference a pointer to get the value stored at the pointer's address (using * before pointer notation).
    // When a pointer isn't proceeded by a variable type, you can assume it's being dereferenced (in using * notation).
    printf("Value of variable stored at p's address: %i\n", *p);
}