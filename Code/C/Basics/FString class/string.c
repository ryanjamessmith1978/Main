#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: ");
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        printf("%c", s[i]);
    }

    printf("\n");
}