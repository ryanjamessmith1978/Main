#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) // echo $? to get return value in terminal
{
    if (argc != 2)
    {
        printf("Missing command-line argrament\n");
        return 1;
    }
    else
    {
        printf("hello, %s\n", argv[1]);
    }

    return 0;
}