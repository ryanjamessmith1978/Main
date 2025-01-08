#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int intArr[3]; // puts the int array on the stack
    intArr[0] = 2;
    intArr[1] = 4;
    intArr[2] = 6;

    for (int i = 0; i < 3; i++)
    {
        printf("Index %i is %i\n", i, intArr[i]);
    }
}