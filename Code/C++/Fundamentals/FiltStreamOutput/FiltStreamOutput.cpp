// FiltStreamOutput.cpp : This file contains 
// the 'main' function. Program execution begins 
// and ends there.

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;

    // ofstream qFile("XoaX.txt"); - output file stream default - overrides what is already there!
    ofstream qFile("XoaX.txt", ios_base::app); // This adds append mode 

    // Quote from Atlas Shrugged novel
    string qLine1("Those who grant sympathy to guilt,");
    string qLine2("grant none to innocence.");

    qFile << qLine1 << endl; // << insertion operator
    qFile << qLine2 << endl; // << sends string to next open newline.

    qFile.close();

    return 0;
}
