
// ****************** FUNCTION OVERLOADING | lvalues and rvalues params ******************** //

// Useful for move semantics optimization
// If we know we are taking in a temporary object (rvalue), don't worry about keeping it alive or copy it.
// Steal resources tied to that specific object and use them somewhere else because we know it's temporary.

#include <iostream>
#include <string>

// lvalue reference param
void PrintName(std::string& name) // function overload that allows compiler to use one name to accept both value types
{
    std::cout << "lvalue: " << name << std::endl;
}

// rvalue reference param
void PrintName(std::string&& name) // function overload that allows compiler to use one name to accept both value types
{
    std::cout << "rvalue: " << name << std::endl;
}

int main()
{
    std::string firstName = "Ryan";
    std::string lastName = "Smith";
    std::string fullName = firstName + lastName;

    // ********************************* //
    // Function overload to accept both value types, rvalue and lvalue.
    // Compiler knows which version of overloaded function to use based on argument type passed in.
    PrintName(fullName); // lvalue
    PrintName(firstName + lastName); // rvalue

    system("pause");
}

