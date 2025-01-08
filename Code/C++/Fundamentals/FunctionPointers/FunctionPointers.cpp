// FunctionPointers.cpp
// Function ptrs used a lot in Xoax.net OpenGL videos
// Function pointers are just pointers that point to functions instead of a variable.

#include <iostream>

using namespace std;

void Function1()
{
    std::cout << "Function1" << std::endl;
}

void Function2()
{
    std::cout << "Function2" << std::endl;
}

int main()
{
    // Declare a function ptr
    // Func ptrs are typed based on the argument type they take in and return type.
    // This func ptr can point to function that take no args and returns nothing.
    void (*fnPrintName)(); 


    // Set ptr to function1 - the function itself doesn't use parentheses after ()
    fnPrintName = Function1;

    // Call Function1 through the ptr - calling the function with a function pointer does use parentheses ()
    fnPrintName();

    // Set ptr to Function2
    fnPrintName = Function2;
    // fnPrintName = &Function2;

    //fnPrintName();
    (*fnPrintName)();

    system("pause");
}
