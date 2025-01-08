#include <cs50.h>
#include <stdio.h>

void recursiveDraw(int h);

int main(void)
{
    int height = get_int("Height: ");
    recursiveDraw(height);
}

void recursiveDraw(int h)
{
    // base case exit
    if(h <= 0)
    {
        return;
    }

    // keep calling function subtracting 1 call each time (1 less call for each time we called the function) - call it until height is 0, no more blocks
    recursiveDraw(h-1);

    // do the thing you want - fill out the row per column
    for(int i = 0; i < h; i++)
    {
        printf("# ");
    }

    printf("\n");

    // stack - last in first out - higher amounts get called first, but executed last



}