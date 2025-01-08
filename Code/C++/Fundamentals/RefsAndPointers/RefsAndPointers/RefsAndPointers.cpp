
#include <iostream>
#include <stdlib.h> // stdlib needs the .h

void usingRefs();
void usingPtrs();

int main()
{
    using namespace std;
    //usingRefs();
    //cout << endl;
    //usingPtrs();
        
    system("pause");
}

// Refs must be initialized at declaration
// Refs CANNOT be reassigned.
void usingRefs()
{
    using namespace std;

    int a = 8;
    int& b = a;
    // Reference is an alias - alternative name
    // Reference b contains the memory address of the variable a
    // From the program's perspective, the reference contains the variable's value

    cout << a << endl;
    cout << b << endl;

    b = 5;

    cout << a << endl;
    cout << b << endl;

    a = 31;

    cout << a << endl;
    cout << b << endl;
}

// Ptrs contain memory address of a variable
// Ptrs can be reassigned, has to be the same variable type
void usingPtrs()
{    
    using namespace std;

    int* myIntPtr = NULL; // int* myIntPtr = 0;    
    int myInt = 10;
    int myInt2 = 20;

    myIntPtr = &myInt;  // assigns memory address of myInt to myIntPtr
    cout << *myIntPtr << endl; // 10
    myIntPtr = &myInt2; // re-assigns the ptrs value a different memory address (myInt2)
    cout << *myIntPtr << endl; // 20

    *myIntPtr = myInt; // *myIntPtr = 10;  Sets the value directly to the pointers pointee(myInt2) with *dereference operator.
                        // Since myIntPtr is still pointing to int2 - the value of int2 gets changed
    cout << myInt2 << endl; // 10
    cout << *myIntPtr << endl; // 10

    char* myCharPtr = new char[8]; // new char of size 8, asking for a block of 8 bytes of memory
    memset(myCharPtr, 0, 8); // memset() fills a block of memory with data we specify
    // Fills in the value of 0 starting at memory address myCharPtr for 8 bytes. {0,0,0,0,0,0,0,0}

    int a = 8;
    int* b = &a; // address-of operator, extract mem address of variable    
    // pointer variable 'b' gets the memory address of int variable a;
        
}
