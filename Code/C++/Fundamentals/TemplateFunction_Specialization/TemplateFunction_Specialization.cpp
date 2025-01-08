// TemplateFunction_Specialization.cpp 
// Write a template function that works for most data types but not all (Top Template)

// However, sometimes, you need to write an additional template function that covers other
// data types (shown in the 2nd example below).  PrintType<int>(int iItem).


#include <iostream>

template <typename PData> // default function template
void PrintType(PData xItem)
{
    std::cout << "Unknown Type" << std::endl;
}

template <> // Function names need to be exactly the same for this to work.
void PrintType<>(int iItem) // version used for specific arguments.  
{
    std::cout << "int" << std::endl;
}


int main()
{
    using namespace std;

    int iInt = 0;
    double dDouble = 0.0;
    char cChar = 0;
    PrintType(iInt); // using int argument here calls specialized template function (2nd one).  
    PrintType(dDouble);
    PrintType(cChar);
}

