#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) // argc is the count of arguments (length of string array) // argv[] - string array
{

    //string name = get_string("What's your name? ");
    printf("hello, %s\n", argv[0]); // argv[0] - is the name of the program (./greet)

    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}