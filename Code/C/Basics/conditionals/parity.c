#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("num: ");

    if(n % 2 == 0)
    {
        printf("Number is even\n");
    }
    else
    {
        printf("Number is odd\n");
    }

}