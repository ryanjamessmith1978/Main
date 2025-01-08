#include <cs50.h>
#include <stdio.h>

void draw (int h);
void recursiveDraw(int h);

int main(void)
{

    int height = get_int("Height: ");

    //draw(height);
    recursiveDraw(height);
}

void draw (int h)
{
    for(int i = 0; i < h; i++)
    {
        for (int j = h-i; j > 0; j--)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
}

void recursiveDraw(int h)
{
    if (h <= 0)
    {
    // h(0) is called last, so it gets put on top of the stack with 5 recursiveDraws on stack (assuming height of 4)
    // but, immediately gets popped off the stack, after the initial if check.
        return;
    }
    recursiveDraw(h-1);

    // The, recursiveDraw(h1) is last prev func on stack (with 4 calls left on stack including itself)
    // With recursion, all the previous recursive function calls get added to the top of the stack
    // before continuing with all the code underneath it.
    // The code underneath gets run LIFO with height value argument

    // Once the initial if check returns 0, the program no longer goes through the function, but
    // the previous recursive calls have already queue'd up on the stack for the bottom half of the
    // recursive function code (the code after the recursive call)
    // Therefor, all that code still need to run despite already exiting the function at h(0).

    for (int i = 0; i < h; i++)
    {
        printf("#");
    }

    printf("\n");
}