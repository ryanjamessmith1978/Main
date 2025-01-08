#include<cs50.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
    // s is a variable of type string
    // string variable is actually just a pointer
    // string points to address of the first char in the string
    string s = "HI!";  // H(0x123), I(0x124), !(0x125), \0(0x126) | String value in memory
    printf("%p\n", s); //
    printf("%p\n", &s[0]);

    // string s == char *s
    // string variable and a char pointer array are the same thing.
    char *ss = s; // Assigns string variable contents (its pointer address) to a char pointer array contents (pointer address).
    printf("%p\n", ss);
    // char array is not the same as a char *
}
