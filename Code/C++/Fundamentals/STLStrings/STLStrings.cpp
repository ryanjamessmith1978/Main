// STLStrings.cpp : C++ v14
// Objects instead of just char arrays.
// BasicString class is a template (built on char variables)
// STL string is a template specialization of the BasicString class

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

void UsingString();
void StringInputAnySize();
void GetStringLength();
void StringCopy();
void StringAppend();
void StringCompare();
void StringTokenize();
void Substring();
void PlayingWithSTLStrings();

int main()
{
    //UsingString();
    //StringInputAnySize();
    //GetStringLength();
    //StringCopy();
    //StringAppend();
    //StringCompare();
    //StringTokenize();
    //Substring();
    PlayingWithSTLStrings();

    system("pause");
    return 0;
}

void UsingString()
{
    string qNameChar("XoaX.net");
    cout << "string: " << qNameChar << endl;
}

void StringInputAnySize()
{
    string name; 
    cout << "What is your name? " << endl;
    cin >> name; // Don't need cin.getline() , STL string objects can be any size.
    cout << "Your name is " << name << endl;
}

void GetStringLength()
{
    string qNameChar("XoaX.net");
    cout << "string: " << qNameChar << endl;
    cout << "string length: " << qNameChar.length() << endl;
}

void StringCopy()
{
    string qName("XoaX.net");
    string qCopy;

    qCopy = qName;

    cout << "Name = " << qName << endl;
    cout << "Copied Name = " << qCopy << endl;
}

void StringAppend()
{
    string qName("XoaX.net");
    string qLesson("Lesson 46");

    qName.append(" ");
    qName.append(qLesson);

    cout << "Concatentation = " << qName << endl;
}

void StringCompare()
{
    string qName("XoaX.net");
    string qLesson("Lesson 46");

    if (qName.compare(qLesson) == 0)
    {
        cout << "Strings are the same" << endl;
    }
    else
    {
        cout << "Strings are different" << endl;
    }
}

void StringTokenize()
{
    string qTokenize("XoaX.net,C++,Console,Lesson 46");
    string qDelim(",");

    // size_type are integers of some type
    string::size_type qStart(0); // start and end index for string to extract
    string::size_type qEnd;
    qEnd = qTokenize.find_first_of(qDelim, qStart);

    while (qEnd != string::npos)
    {
        cout << qTokenize.substr(qStart, qEnd - qStart) << endl; // Calculate start and end and use that to extract substring
        qStart = qEnd + 1;
        qEnd = qTokenize.find_first_of(qDelim, qStart);
    }

    cout << qTokenize.substr(qStart) << endl;
}

void Substring()
{
    string qName("Ryan J Smith");    
    string Name = qName.substr(0, 4);
    if (qName.find(Name) != string::npos)
    {
        cout << "The initial string is " << qName << endl;
        cout << "Substring of 4 characters starting at index 0 is: " << Name << endl;
    }
}

void PlayingWithSTLStrings()
{


}
