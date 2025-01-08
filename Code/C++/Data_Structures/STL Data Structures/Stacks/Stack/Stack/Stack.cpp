// Stack.cpp | https://www.youtube.com/watch?v=GBST5uQ_yos&list=PLm0fFUL4gEt9QZ5gGl63ty4qSwrmzVvH_&index=11&t=9s
//
// Data Structure that uses LIFO technique - LIFO (Last In First Out)

#include <iostream>
#include <stack>

void printStack(std::stack<int> myStack)
{
    while (!myStack.empty())
    {
        std::cout << myStack.top() << std::endl;
        myStack.pop();
    }
}

int main()
{
    // LIFO - Last In First Out        
    std::stack<int> numbersStack;

    // Push - insert element into Stack
    numbersStack.push(1);
    numbersStack.push(2);
    numbersStack.push(3);

    // Stack size
    std::cout << "Stack Size: " << numbersStack.size() << std::endl;

    //// Is Empty?
    //if (numbersStack.empty())
    //    std::cout << "Stack is Empty!" << std::endl;
    //else
    //    std::cout << "Stack is not Empty" << std::endl;    

    printStack(numbersStack);    

    // Pop - removes first element from top of stack
    numbersStack.pop();

    std::cout << "Pop from top of stack" << std::endl;
        
    printStack(numbersStack);

    system("pause");
}

// When is it appropriate to use Stack?  Stack use pointers or primitives (like an array) or objects.
// Difference between Vector and Stack?  