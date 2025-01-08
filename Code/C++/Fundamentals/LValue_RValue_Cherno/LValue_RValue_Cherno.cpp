// LValue_RValue_Cherno.cpp 

// l-value is something that is on the left side of the equal sign, variables with some type of storage backing them.
// l-value references can only take in l-values, UNLESS they are const.
// r-value is something that is on the right side of the equal sign, temporary values.
// r-value references can only take in temporary rvalues (designated as && in function params).
// modifiable meaning non-const

#include <iostream>
#include <string>

int GetValue()
{
    return 10;
}

int& GetLValue_Ref()
{
    static int value = 10;  // need to provide storage for my value.
    return value; // returning an lvalue reference.
}

void SetValue(int value) // Can be called with an lvalue or an rvalue.
{}

void SetValueRef(int& value) // l-value reference parameter
{}

void SetValueConstRef(const int& value) // l-value reference parameter
{}

void PrintNameLValue(std::string& name)
{
    std::cout << name << std::endl;
}

void PrintNameRValue(std::string&& name)
{
    std::cout << name << std::endl;
}

void PrintNameConst(const std::string& name)
{
    std::cout << name << std::endl;
}

int main()
{
    int i = 10;
    //GetValue() = 5; // ERRoR! GetValue() is an r-value, expression must be a modifiable lvalue.
    GetLValue_Ref() = 5; // lvalue reference.

    SetValue(i); // setting with an lvalue.
    SetValue(10); // setting SetValue with an rvalue (temporary value). rvalue used to set lvalue when func. called.
    
    // NOTE: CANNOT accept rvalue(10) as an lvalue reference argument.
    //SetValueRef(10); // ERRoR!
    SetValueRef(i);

    SetValueConstRef(10); // Setting parameter to a const lvalue reference allows both value types, rvalue(10) and lvalue(i). 
    SetValueConstRef(i);

    // lvalue reference variables: Const vs. non-const
    //int& a = 10;  // ERRoR! reference variable value needs to be an lvalue.   

    // Work around for ref variables assign rvalues, add a const keyword.
    // Underneath the hood, compiler will create a temp variable equal to 10.
    const int& a = 10; 
    // int temp = 10;
    // const int& a = temp;

    std::string firstName = "Ryan";
    std::string lastName = "Smith";
    std::string fullName = firstName + lastName; // temporary expression interpreted as lvalues making an rvalue.

    // void PrintNameLValue(std::string& name)
    // PrintNameLValue(fullName);  // GOOD! 
    // PrintNameLValue(firstName + lastName); // NOT GOOD! rvalues NOT allowed for non-const reference parameters.

    // void PrintNameRValue(std::string&& name) // string&& is an rvalue reference (accepts temporary objects)
    // PrintNameRValue(fullName); // NOT GOOD! string&& is an rvalue reference, thus cannot accept lvalues.
    // PrintNameRValue(firstName + lastName); // GOOD! rvalue or rvalue reference

    // void PrintNameConst(const std::string& name)
    // PrintNameConst(fullName);  // GOOD!
    // PrintNameConst(firstName + lastName); // GOOD! Using const& allows for lvalues and rvalues.

    system("pause");
}