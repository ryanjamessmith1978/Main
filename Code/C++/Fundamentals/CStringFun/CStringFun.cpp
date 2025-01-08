// CStringFun.cpp - char arrays : C++ v14
// _CRT_SECURE_NO_WARNINGS (to ignore non-safe warnings)
// needed in Project->Properties->Preprocessor directives


#include <iostream>
#include <string.h> // strlen, strcat, strcpy, strncat, strncpy, strcmp, strstr
#include <cstdio>

using namespace std;

void EnterName();
void CStringLength();
void CStringConcatentate();
void CStringCopy();
void CStringCompare();
void CStringTokenize();
void DynamicArrayOfChars();

void CStringPracticeAllowed();
void CStringPracticeNOTAllowed();

void OverloadOne(int one);
void OverloadOne(int one, int two);
 
template <class T>
class className {
private:
    T var;
    //... .. ... 
public:
    T functionName(T arg);
    //... .. ...
};

// char* - cast ptrs to char ptrs for pointer arithmetic for iterating
int main()
{    
    // EnterName();
    // CStringLength();
    // CStringConcatentate();
    // CStringCopy();
    // CStringCompare();
     CStringTokenize();
    
    // CStringPracticeAllowed();
    // CStringPracticeNOTAllowed();
       

    system("pause");
    return 0;
}

void EnterName()
{
    const int MAX = 12;
    char cName[MAX];
    cout << "What is your name? " << endl;
    // cin >> cName; // Need to keep track of number of chars manually.  9+ /0.  
    cin.getline(cName, MAX); // restricts input to 10 total characters including /0 - so 9 inputted chars
    cout << "Your name is " << cName << endl;
}

// ****  STRLEN(), SIZEOF(), SIZE(), .LENGTH()  **** //
void CStringLength() 
{
    // ### STRLEN() ### 
    // Works: string literal, const char*, char*, char array[] (initialized to string literal)
    // Does NOT work: STL strings, char arrays with comma separated lists, int arrays
    // DOES NOT count NULL Terminator.
    // strlen("myString") ==> predefined function of CStrings (not STL strings)
    // strlen("myString") ==> returns number of bytes NOT including '/0'.     
    // strlen("myString") ==> char arrays must be initialized to a string literal (not comma sep lists)
    // strlen("myString") ==> requires a '/0' character in string to work.
   
    // char myString2[7]; myString2[0] = 'H'; myString2[6] = '/0';
    // cout << "Uninitialized char array: " << strlen(myString2) << endl; // undefined, strlen needs str literal
    char myCharArray[] = "Hello";
    char* myCharPtr = myCharArray;

    // can pass in string literal, char array, or char* (not STL string)
    int size1 = strlen("Hello");
    int size2 = strlen(myCharArray);
    int size3 = strlen(myCharPtr);    
    // cout << "C String length using strlen() of Hello: " << size1 << endl;
    // cout << "C String length using strlen() of char Array: " << size2 << endl;
    // cout << "C String length using strlen() of myCharPtr: " << size3 << endl;

    // ### SIZEOF() ###
    // Works: string literal, char array[], int arrays (need to divide by sizeof(int))
    // Does NOT work: STL strings, pointers.
    // DOES count NULL terminator '/0'
    // Adds '/0' to string literals, but not comma separated lists
    // sizeof("myString") ==> Urnary Operator works for any array - NOT pointers, NOT STL Strings
    // sizeof("myString") ==> Compile Time calculation | returns size of allocated data in bytes
    // sizeof("myString") ==> Counts the '/0' character when counting number of bytes. Adds '/0' to string literals
    // sizeof("myString") ==> Can be used on char arrays with comma separated lists.  Doesn't auto add '/0'.  
    // sizeof(somePtr) ==> sizeof can't determine number of elements with just a pointer (1rst element only)

    char myCharArray2[] = { 'H', 'e', 'l', 'l', 'o'}; // NO '/0' added to comma separated lists.
    char myCharArray9[] = "Hello";
    char* myCharPtr2 = myCharArray2; char* myCharPtr3 = NULL; // char* ptrs are always 8 bytes    
    int myIntArr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // int arrays don't use '/0'
    //int size6 = strlen(myIntArr);
        
    cout << "Using SizeOf() for myCharArray, length: " << sizeof("Hello") << endl;
    cout << "Using SizeOf() for myCharArray2 list, length: " << size(myCharArray2) << endl;
    cout << "Using SizeOf() for myCharArray9, length: " << sizeof(myCharArray9) << endl;
    cout << "Using SizeOf() for myIntArr with 0-9 values, the size is: " << sizeof(myIntArr) << endl;
    cout << "IntArr number of elements using SizeOf() by dividing by sizeof(int): " << sizeof(myIntArr) / sizeof(int) << endl;
    cout << "Using SizeOf() for myCharPtr2 size is: " << sizeof(myCharPtr3) << endl; // 8 bytes

    // ### SIZE() ###
    // Works: string literal, char array[], int arrays (NO divide by sizeof(int)), STL strings
    // Does NOT work: Pointers.
    // DOES count NULL terminator '/0'
    // Adds NULL terminator '/0' to string literals, but not comma separated lists
    // size("myString") ==> member function of STL string
    // size("myString") ==> returns number of characters of a string
    // size(somePtr) ==> SIZE() does NOT work with pointers.  

    std::string stlString = "Geek";
    char myCharArray4[15] = "GeekCharArray"; // size() defaults to declared size[15] (even though only 14 bytes used)
    
    const char* myConstCharPtr = myCharArray4;
    int ssize = size("Ryan");

    int myIntArr2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // int arrays don't use '/0'
    int intSize = size(myIntArr2);    
    cout << "Int Array's number of elements using Size() is: " << intSize << endl;
    
    std::cout << "Length of STL String, 'Geek' is: " << size(stlString) / sizeof(string) << endl; // NO!
    std::cout << "Length of STL String using SIZE() for 'Geek' is: " << size(stlString) << endl;  // YESSS!
    std::cout << "Length of myCharArray4 using SIZE() is: " << size(myCharArray4) << endl; // Works for Char Arrays       
    //std::cout << "Length of myCharPtr4 is: " << size(myCharPtr4) << endl;      // NO!
    //std::cout << "Length of myConstCharPtr: " << size(*myConstCharPtr) << endl; // NO!      


    // ### .LENGTH() ###
    // myString.length() ==> member function of STL string - STL strings only.
    // myString.length() ==> returns number of bytes for string's length  

    std::cout << "Length of STL String using .length() for 'Geek' is: " << stlString.length() << endl;  // YESSS!
    // std::cout << "Length of myCharArray3 using .length() is: " << myCharArray4.length() << endl; // NO!
    // int intSize2 = myIntArr2.length(); // .length() only works on strings
    
}

void CStringConcatentate() // combines the source to the end of the destination string
{
    //char dest[5] = "Hello";  Need at least 6 bytes for this char array '/0'
    char dest[55] = "Hello";
    char src[] = " World!";
    printf("%s \n", dest);

    strcat(dest, src);
    printf("%s \n", dest);

    char dest2[55] = "Hello MY";
    char src2[] = " World!";
    int concatStrSize = strlen(dest2) + strlen(src2) + 1;

    strncat(dest2, src2, concatStrSize);
    printf("%s \n", dest2);
}

void CStringCopy() // strcpy --> overwrites one cstring to another.
{
    char dest[65] = "Hello";    
    //strcpy(dest, "Overwriting original Hello char array with another string literal");
    // ^^^ This will lead to buffer overrun, not enough space reserved, 65.
    strcpy(dest, "Overwriting original Hello char array with this string literal");
    printf("%s \n", dest);

    const char* dest2 = "Hello2";
    strcpy(dest, dest2);
    printf("%s \n", dest);

    char src[] = "World";
    strncpy(dest, src, 1); // replaces destination with source, but only first character.
    printf("%s \n", dest);
}

void CStringCompare() // strcmp - compares 2 strings, returns 0 if they are equal.
{
    char a[5] = "Hank"; // this creates a memory address ptr and mem block of 5 char 
    char b[] = "Hank";
    // a[0] = 'G'; 
    // a = "Gank"; NO - can't re-assign an entire char array a new string

    printf("a: %s\n", a);
    printf("b: %s\n", b);

    if (strcmp(a, b) == 0)
    {
        printf("a and b are equal.\n");
    }
    else
    {
        printf("a and b are NOT equal.\n");
    }

    const char* c = "Gank";
    int sizeA = sizeof(a) / sizeof(char);
    strncpy(a, c, sizeA);
    

    for (int i = 0; i < sizeA; i++)
    {
        cout << a[i] << endl;
    }

    printf("a: %s\n", a);
    printf("c: %s\n", c);

    if (strcmp(a, c) == 0)
    {
        printf("a and b are equal.\n");
    }
    else
    {
        printf("a and b are NOT equal.\n");
    }

    const int MAX = 15;       
    char szDest[MAX];
    const char *szSource= "Hello, World!";

    strncpy(szDest, szSource, MAX - 1);
    szDest[MAX - 1] = 0;
    
    cout << "Size of string is: " << strlen(szDest) << endl;

    strncpy_s(szDest, sizeof(szDest), szSource, strlen(szSource)); // string safe copy
}

void CStringTokenize()
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

    const int MAX = 20;
    char caName[MAX];
    cin.getline(caName, MAX);

}

void CStringPracticeAllowed()
{
    // Literal string "String" declared as an array of characters.
    char cstring[] = "char array"; // copies that value of string literal into char array.    
    int size = strlen(cstring);
    cout << size << endl;
    char* cstringPtr = new char[size]; // size is 10
    // memcpy(cstringPtr, cstring, size); // undefined behavior, need to add '/0' size+1.
    for (int i = 0; i < size + 1; i++)
    {
        char newValue = cstring[i]; // when you index into something, it's an implicit deref
        //cstringPtr = &newValue; // can't modify a char*'s index address, only initial address
        printf("Address: %p\n", &newValue+i);
        // &(*cstringPtr+i) = &newValue + i; // can't do this - can't modify a pointer's pointee's value address.
    }

    //cout << strlen(cstringPtr) << endl;
   // cout << cstringPtr << endl;

    /*
    for (int i = 0; i < size; i++)
    {
        printf("%d: %c\n", i, cstringPtr[i]);
    }

    *(&cstringPtr[0]) = 'z';
    cstringPtr[1] = 'a';
    int length = strlen(cstringPtr) - 1;
    cstringPtr[length] = '/0';
    printf("%s \n", cstringPtr);

    const char* ccstringPtr = "constant char pointer";
    //printf("%s \n", ccstringPtr);
    int size2 = strlen(ccstringPtr);
    //printf("%i \n", size2);

    ccstringPtr = "const char pointer updated";
    //printf("%s \n", ccstringPtr);

    

    //puts(ccstringPtr);

    */
}

void CStringPracticeNOTAllowed()
{
    cout << endl;

    char A[] = "Viky"; // char arrays can only be initialized with stirngs, need loops to modify
    char B[] = "Ryan";
    
    // A = "Sam";
    // A = B; // Trying to store memory location of B into the value of A.  CAN'T
    // A is a memory address that points to a memory block storing "Viky".
    // The value that A points to can change, but not the memory address of A itself.



}

void OverloadOne(int one)
{
}

void OverloadOne(int one, int two)
{
}


/*
void StringLen_Concat()
{
    char caName[] = "Xoax.net";
    char caLesson[] = "Lesson 44";

    int iLength = strlen(caName) + strlen(caLesson);

    char* cpFullName = new char[iLength + 2]; // +2 for 'space' and /0

    strcpy(cpFullName, caName);
    cout << "After Copy: " << cpFullName << endl;

    strcat(cpFullName, " "); // append might be the better option
    strcat(cpFullName, caLesson);
    cout << "After Concatentation: " << cpFullName << endl;

    delete [] cpFullName;
}
*/