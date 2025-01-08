#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        // using the ASCII Binary Chart || each character has a binary value
        // checking if the character is lower case and if it is -32 will give the uppercase equivalent
        // can also use islower and toupper to fix.
        if(s[i] >= 'a' && s[i] <= 'z') //islower(s[i])
        {
            printf("%c", s[i] - 32); // toupper(s[i])
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}