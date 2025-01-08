// PreFix_and_PostFix.cpp
// Inline increment operator in a lot of legacy code.

#include <iostream>

void Prefix();
void Postfix();
void PreAndPost();

int main()
{    
    //PreAndPost();
    Prefix();

    system("pause");
    return 0;
}

void Prefix()
{
    // int index = 0;
    // Prefix Increment is ++index
    // Prefix Decrement is --index
    int index = 0;

    // Pre
    while (index < 5)
    {
        // Increment, then use the variable.  If prefix is in call, perform operation, then output
        std::cout << ++index << std::endl;
    }

}

void Postfix()
{
    // int index = 0;
    // Postfix Increment is index++
    // Postfix Decrement is index--
    int index = 0;

    // Pre
    while (index < 5)
    {
        // Use the variable, then increment.
        std::cout << index++ << std::endl;
    }
}

void PreAndPost()
{
    // Both incremental/decremental types yield the same result
    int index = 0;

    // Pre
    while (index < 5)
    {
        std::cout << index << std::endl;
        ++index; // index = index + 1; index += 1;
    }

    std::cout << std::endl;

    index = 0;
    // Post
    while (index < 5)
    {
        std::cout << index << std::endl;
        index++; // index = index + 1; index += 1;
    }
}