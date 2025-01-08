#include <cs50.h> //#include<cs50.h
#include <stdio.h> //#include<stdio.h>

// String compare isn't available in C natively using ==
int main(void)
{
    char c = get_char("Do you agree? "); // char c = get_char("do you agree?\n);

    if (c == 'y' || c == 'Y')
    {
        printf("You do agree\n");
    }
    else
    {
        printf("You don't agree\n");
    }
}