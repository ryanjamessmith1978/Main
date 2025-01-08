#include <cs50.h>
#include <stdio.h>
#include <string.h>

// A pointer is a variable that stores an address
// & - 'address of' operator - function for returning address value
// <var type> *<var name> - an asterik before a var name and after a var type declares a pointer variable.

int main(void)
{
    int n = 50;

    // int pointer p variable being declared.c
    // int pointer p variable being assigned the address value of n.
     int *p = &n;

    printf("%p\n",&n); // yes
    printf("%p\n", p); // yes
    printf("%i\n", n); // yes

    // printf("%i\n", &n); // no, even though memory address is numeric value, it can't be stored as an int
    // printf("%i\n", p); // no, memory addresses are there own data types, C rules prevents them from being interchanged.
}