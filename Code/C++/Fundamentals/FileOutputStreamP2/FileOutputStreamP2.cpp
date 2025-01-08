// FiltStreamOutputP2.cpp : This file contains 
// the 'main' function. Program execution begins 
// and ends there.

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;

    ofstream qFile("XoaX.txt", ios_base::app); // append mode allows you to add to whatever is already there in file

    // Quote from Atlas Shrugged novel
    string qLine1("There are two sides to every issue:");
    string qLine2("one side is right and the other is wrong,");
    string qLine3("but the middle is always evil.");

    qFile << endl;
    qFile << qLine1 << endl;
    qFile << qLine2 << endl;
    qFile << qLine3 << endl;

    qFile.close();

    return 0;
}