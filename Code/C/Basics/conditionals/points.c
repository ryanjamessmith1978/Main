#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int myPoints = 3;
    int points = get_int("How many points did you lose? ");

    if (points < myPoints)
    {
        printf("You lose fewer points than me.\n");
    }
    else if (points > myPoints)
    {
        printf("You lost more points than me.\n");
    }
    else
    {
        printf("You lose the same amount of points than me.\n");
    }

}