#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 74;

    // free(x)
}

// valgrind ./memory - run this command when running code to check for memory leaks