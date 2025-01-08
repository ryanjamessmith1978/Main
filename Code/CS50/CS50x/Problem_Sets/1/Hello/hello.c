// Modify this program in such a way that it first prompts the user for their name and then prints hello, <name>

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main(void)
{
    string name = get_string("What is your name? ");

    printf("Hello, %s\n", name);

}