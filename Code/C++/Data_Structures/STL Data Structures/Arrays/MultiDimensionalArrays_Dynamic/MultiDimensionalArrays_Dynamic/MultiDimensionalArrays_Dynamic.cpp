// MultiDimensionalArrays_Dynamic.cpp :
// https://www.youtube.com/watch?v=zsw0moDcZm4

#include <iostream>
#include <strsafe.h>

using namespace std;

void OneDimensionalHeapArray();
void TwoDimensionalHeapArray();
void DynamicArrayOfChars();

int main()
{
    int arr[] = { 11, 22, 33, 44 };

    // Define a pointer 
    int* ptr = arr;

    // Printing address of the arrary using array name 
    cout << "Memory address of arr: " << &arr << endl;  // don't need '&' in front of arr.
    cout << "Memory address of int* ptr: " << ptr << endl;

    // Print elements of an array 
    cout << "first element: " << *arr << endl;
    cout << "Second element: " << *(arr + 1) << endl;
    cout << "Third element: " << *(ptr + 2) << endl;
    cout << "fourth element: " << arr[3] << endl;

    system("pause");
}


/*
int main()
{
    //OneDimensionalHeapArray();
    //TwoDimensionalHeapArray();
    //DynamicArrayOfChars();
    
    system("pause");
    return 0;
}*/

void OneDimensionalHeapArray()
{
    // pointer is NOT dynamically allocated, (ptr variable is on the stack)
    // memory block created that the pointer points to is dynamically allocated on the heap.
    int* ipArray = new int[3]; 

    for (int i = 0; i < 3; i++)
    {
        ipArray[i] = i;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << ipArray[i] << " ";
    }

    cout << endl;

    delete[] ipArray;

}

void TwoDimensionalHeapArray()
{
    int** ippArray = new int* [3]; // initializes int ptr array to which contain 3 ptr elements, each ptr element points to something on the heap

    // initializes each pointer element to allocate an integer array of 2 elements, also on the heap.  
    // { {1,2}, {3,4}, {5,6} } | each array element in the array is also considered a pointer.
    for (int i = 0; i < 3; i++)
    {
        ippArray[i] = new int[2];
    }

    // Populates the 3 outer elements with an array that holds 2 integer elements in the inner array.  
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ippArray[i][j] = i + j;
        }
    }

    // Prints out the element one outer element at a time, printing 2 inner elements for each outer element.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << ippArray[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        delete[] ippArray[i];
    }

    delete[] ippArray;

}

void DynamicArrayOfChars()
{
    // char* arrays can have chars with varying sizes.
    char** cppStrings = new char* [3]; 
    cppStrings[0] = new char[9];
    cppStrings[1] = new char[13];
    cppStrings[2] = new char[4];

    strcpy(cppStrings[0], "XoaX.net");
    strcpy(cppStrings[1], "Michael Hall");
    strcpy(cppStrings[2], "C++");

    for (int i = 0; i < 3; i++)
    {
        cout << cppStrings[i] << endl;
    }

    cout << endl;
}
