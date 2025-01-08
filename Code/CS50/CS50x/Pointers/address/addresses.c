#include <stdio.h>
#include <cs50.h>

int main(void)
{
// string is really a pointer.
    // string s == char *s | a char pointer.
    // The value of s is 0x123.
    // string s is a pointer points to the first character in the string, aka 'H', aka 0x123.
    // TIP: printf is smart - Confusion can come in that printf("%s") prints the value of a string despite string s is a memory address,
    // printf function knows to look in the memory address of the string s, and print out char values until reaching /0 null character.
    string s = "HI!";

    printf("%s\n", s); // prints HI! - don't need *s (deference) because printf function walks through each character
    printf("%c\n", *s); // prints first character 'H'  // can't have %s here.
    printf("%c\n", s[0]); // prints out character of string at array index [0]
    printf("%p\n", s); // prints out memory value of the string - which is just the address of the first character in char* array.
    printf("%p\n", &s[0]); // specifices the memory address of the char* array at index 0.
    printf("\n");

    char *c = "HI!";
    printf("%c\n", c[0]);
    printf("%c\n", c[1]);
    printf("%c\n", c[2]);

    printf("%c\n", *c);
    printf("%c\n", *(c+1));
    printf("%c\n", *(c+2));
    // pointer arithmetic works on other data type arrays, because compile is smart enough to know byte size of each data type
    // pointer arithemetic adds the byte size of the data type to go to next element in array.

    printf("%p\n", &(*c));
    printf("%p\n", &(*(c+1)));
    printf("%p\n", &(*(c+2)));
    // H - 0x123
    // I - 0x124
    // ? - 0x125
    // \0 - 0x126
}