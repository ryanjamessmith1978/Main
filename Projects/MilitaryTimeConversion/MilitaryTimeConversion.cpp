// MilitaryTimeConversion.cpp 
// Example of tokenizing strings

#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>

using namespace std;

string timeConversion(string s);

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));
    string s;
    getline(cin, s);

    string result = timeConversion(s);

    std::cout << result << "\n";

    // fout.close();

    return 0;
}

string timeConversion(string s)
{
    //std::string s = "05:25:26AM";
    std::string delimeter = ":";
    std::string token;
    std::string timeArr[4];
    size_t pos = 0;
    int currentPos = 0;

    while ( (pos = s.find(delimeter)) != std::string::npos ) 
    {
        token = s.substr(0, pos);
        timeArr[currentPos] = token;
        currentPos++;
        s.erase(0, pos + delimeter.length()); // ok, when destroying intial string is okay.
    }

    // substring the 3rd element into 2 elements

    string s1 = s.substr(0, 2);
    string s2 = s.substr(2, 2);
    timeArr[currentPos] = s1;
    currentPos++;
    timeArr[currentPos] = s2;

    string am = "AM";
    string convertedString;
    bool isAM = false;

    if (s2.find(am) != std::string::npos)
    {
        isAM = true;
    }

    if (isAM)
    {
        if (timeArr[0].find("12") != std::string::npos)
        {
            convertedString = "00";
        }
        else
        {
            convertedString = timeArr[0];
        }

        convertedString.append(":");
        convertedString.append(timeArr[1]);
        convertedString.append(":");
        convertedString.append(timeArr[2]);
    }
    else
    {
        if (timeArr[0].find("12") != std::string::npos)
        {
            convertedString = "12";
        }
        else
        {
            int myint1 = stoi(timeArr[0]);
            myint1 += 12;
            convertedString = to_string(myint1);
        }

        convertedString.append(":");
        convertedString.append(timeArr[1]);
        convertedString.append(":");
        convertedString.append(timeArr[2]);
    }

    return convertedString;
}

/*

***  TOKENIZE C-STRINGS *** 
void Tokenize()
{
    char caString[] = "Xoax.net,C++,Console,Lesson 44";
    char caDelim[] = ",";

    char* cpSub = strtok(caString, caDelim);

    while (cpSub)
    {
        cout << cpSub << endl;
        cpSub = strtok(NULL, caDelim);
    }
}

***  TOKENIZE STL STRINGS ***
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


*/