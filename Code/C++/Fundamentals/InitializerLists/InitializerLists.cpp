// InitializerLists.cpp 

#include <iostream>
#include "InitializerListExample.h"
#include "Entity.h"

void BasicInitializerList();


int main()
{
    // Simple initializer List example
    // BasicInitializerList();

    // Functional Difference between initializer lists and assignment constructors
    Entity myEntity;


    system("pause");
}

void BasicInitializerList()
{
    //InitializerListExample ex = InitializerListExample(7, 8); // either syntax
    InitializerListExample ex(7, 8);

    std::cout << "My Int1 is: " << ex.GetMyInt1() << std::endl;
    std::cout << "My Int2 is: " << ex.GetMyInt2() << std::endl;
}
