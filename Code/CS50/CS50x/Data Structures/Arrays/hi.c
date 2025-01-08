#include <stdio.h>
#include <cs50.h>

int main (void)
{
    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%s\n", words[0]);

    string s = "HI!";

    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);

    for (int i = 0; i < 4; i++)
    {
        printf("%i, ", words[1][i]);
    }
    printf("\n");

    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
    printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);
}