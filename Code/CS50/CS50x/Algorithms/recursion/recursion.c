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

void recursiveDraw(int h) // Last in First Out - Works like a stack - pushing onto top of stack - popping off the top of stack
{
    if (h <= 0)
    {
    // h(0) is called last, so it gets put on top of the stack with 5 recursiveDraws on stack (assuming height of 4)
    // but, immediately gets popped off the stack, after the initial if check.
        return;
    }
    recursiveDraw(h-1); // first call gets 4, second call gets 3, third call gets 2, 4th call gets 1, 5th call escapes

    // Stack then does last valid call first - 4th call - prints 1
    // 3rd call is next on the stack - so it prints 2
    //

    // The, recursiveDraw(1) is last prev func on stack (with 4 calls left on stack including itself)
    // With recursion, all the previous recursive function calls get added to the top of the stack - the stack doesn't execute until last call made
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