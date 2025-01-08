// FunctionTemplateAdvanced.cpp
//

#include <iostream>

template <typename PData, const int kiSize> // template params
void PrintArray(PData xaArray[])            // template function params
{
    for (int iIndex = 0; iIndex < kiSize; iIndex++)
    {
        std::cout << xaArray[iIndex] << std::endl;
    }
}

int main()
{
    using namespace std;
    
    int iaArray[] = { 3.3, 2, 4, 1};
    // specify template parameters, array size can't be automatically determined
    PrintArray<int, 4>(iaArray);
    cout << endl;
    double daArray[] = { 3.7, 2.8, 4.3, 0.6 };
    PrintArray<double, 3>(daArray);

    system("pause");
}

// Example showing how arrays can be passed in a template function
// W/O having to specify template params - <type, size> into the function call

/*
template <typename PData>         *** Doesn't use a 2nd data type as part of the template
void PrintArray(PData xaArray[7]) *** Template data type array size set to a constant 7.
{    
    // Do NOT need to specify PrintArray<type, size>(iaArray) type,size template params
    // into template function if array size is set (7 in this case).
}

int main()
{
    using namespace std;
    // PrintArray<int, 4>(iaArray); ***Previous example

    int iaArray[] = { 3.3, 2, 4, 1, 5, 6 };
    // specify template parameters, array size can't be automatically determined

    PrintArray(iaArray); *** Only passes in array, no cast before passing in param
    cout << endl;
    double daArray[] = { 3.7, 2.8, 4.3, 0.6 };
    //PrintArray(daArray);

    system("pause");
}
*/

/*
// You can also set a size in function params
// instead of the template params

template <typename PData> 
void PrintArray(PData xaArray[], int size) 
{       
    // int iaArray[] = { 3.3, 2, 4, 1, 5, 6 };
    // PrintArray<int, 4>(iaArray); ***Previous example
    // PrintArray(iaArray, 4);
}
* /