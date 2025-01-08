// FileInputStream.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void testForValidFile();

int main()
{
    ifstream qFile("XoaX.txt"); // input file stream - read from this file.
    // ifstream qFile2("XoaX.txt");
    string qLine;

    while (!qFile.eof()) // read data until getting to end of file
    {
        getline(qFile, qLine);
        cout << qLine << endl;
    }

    qFile.close();  
    
    // Need to close and re-open streamed file (after being read from)
    // or create a 2nd ifstream variable pointing to same txt file.
    qFile.open("XoaX.txt");
    string qWord;    

    while (!qFile.eof()) // 2nd read through
    {
        qFile >> qWord;
        cout << qWord << endl;
    }

    qFile.close(); // closed a 2nd time after second read

    testForValidFile();

    system("pause");

    return 0;
}

void testForValidFile()
{
    ifstream qFile2("C:\\Users\\RySmi\\Documents\\Code\\VisualStudios\\CPlusPlus\\FileInputStream\\XoaX.txt");

    string qWord;

    if (!qFile2.good())
    {
        cout << "Could not open file!" << endl;
        return;
    }

    while (!qFile2.eof())
    {
        qFile2 >> qWord;
        cout << qWord << ", ";
        cout << endl;
    }

    qFile2.close();

    return;
}