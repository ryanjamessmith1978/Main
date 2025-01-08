#include <stdio.h>

int main(void)
{
    int score1 = 72;
    int score2 = 73;
    int score3 = 33;

    printf("Average: %i\n", (score1 + score2 + score3) / 3); // int will truncate
    printf("Average: %f\n", (float)(score1 + score2 + score3) / 3); // cast will guarantee float gets decimal accuracy
}