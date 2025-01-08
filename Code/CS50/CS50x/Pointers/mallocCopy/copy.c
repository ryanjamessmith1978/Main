#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    /*char *t = s;

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);

    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);*/

    char *t = malloc(strlen(s) + 1);

    // strcpy (t, s) - destination first - from s into t
    for (int i = 0; i < strlen(s) + 1; i++)
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

}