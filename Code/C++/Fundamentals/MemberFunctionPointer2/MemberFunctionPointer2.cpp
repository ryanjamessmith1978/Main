// MemberFunctionPointer2.cpp : 

#include <iostream>
#include <cstdlib>
#include "CMessage.h"
#include "CEmployee.h"

using namespace std;

void FunctionPointerArray();
void FunctionPointerEmployee();

int main()
{      
    // Example #2 - Function Pointer Array
    FunctionPointerArray();

    // Example #3 - Function Pointer with Employee Class
    FunctionPointerEmployee();

    system("pause");
    return 0;
}

void FunctionPointerArray()
{
    // Creating a function pointer array (member) from the CMessage class
    void (CMessage:: *fnArray[3])();

    // Assigning each index of the function pointer array an individual member function.
    fnArray[0] = &CMessage::Print1; 
    fnArray[1] = &CMessage::Print2;
    fnArray[2] = &CMessage::Print3;

    CMessage qMyMessage; 
    // How does this CMessage var acquire the function pointer array (*fnArray) created above ?
    // It doesn't acquire anything because it doesn't need to.
    // 
    // A function pointer is the same thing as a function itself
    // Those member functions (Print1, ect..) already exist, so whether you call the function 
    // in the traditional way, or you de-reference a local func pointer initialized to the class
    // function of the same name, the end result is the same.
    for (int i = 0; i < 3; i++)
    {
        (qMyMessage.*fnArray[i])(); // for i = 0, same as qMyMessage.Print1();
    }

    std::cout << std::endl;
}

void FunctionPointerEmployee()
{
    // the this-> pointer in CalcWage refers to our qEmployee object.
    CEmployee qEmployee; 
    // Function call to execute it's own function pointer. 
    cout << "Wage = " << qEmployee.CalculateWage(45.0) << endl; 
    qEmployee.MakeExperienced();
    cout << "Wage = " << qEmployee.CalculateWage(45.0) << endl << endl;
}
