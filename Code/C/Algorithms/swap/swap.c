#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int a, int b);
void swappy(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
    swappy(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swappy(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//  **** Memory Stack
//
//  [[Machine Code]]
//     [[Globals]]
//     [[ Heap v]]
//
//
//
//     [[Stack ^]]