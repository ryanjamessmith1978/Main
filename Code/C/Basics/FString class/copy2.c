#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    string s = get_string("s: ");
    char *t = malloc(strlen(s) + 1);

    for(int i = 0, n = strlen(s) + 1; i < n; i++)
    {
       t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
}