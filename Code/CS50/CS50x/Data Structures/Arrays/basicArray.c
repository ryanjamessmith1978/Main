

#include<cs50.h> // where do .h files exist?  /usr/include
#include<stdio.h>

const int N = 3;

int main(void)
{
    //int arrTwo[]; // ERROR - need to declare size -or- initialize a set of values with {} curly braces
    // int n = 3;
    // int intArr[n];  // ERROR - n has to be a const or a hard coded value in the brackets.
    int intArr[N]; // declares size of array - puts the int array on the stack with 3 elements - N has to be a constant
    int intArr2[] = {2, 4, 6}; // size is inferred by the initialized values.

    // Array always need the [x], where x is an int value, indicating how many elements in array
    intArr[0] = 3;
    intArr[1] = 5;
    intArr[2] = 7;

    // intArr[] = intArr2[]; // FAIL
    // No space is set aside for any pointers in an array
    // There is no pointer object intArr or intArr2 that separate from the array elements themselves.
    // For Arrays, you can change there right hand values via individual indexes, but not lvalue (left hand value)
    // The array variable is not pointing to the 0 index element, it is one in the same.


    printf("Array1: \n");
    for (int i = 0; i < N; i++) // arrays in C, programmer needs to remember size of array.  No .size() function in C.
    {
        printf("Index %i is %i\n", i, intArr[i]); // %s %i - are format codes
    }
    printf("\n");
    printf("Array2: \n");

    for (int i = 0; i < 3; i++)
    {
        printf("Index %i is %i\n", i, intArr2[i]);
    }
}