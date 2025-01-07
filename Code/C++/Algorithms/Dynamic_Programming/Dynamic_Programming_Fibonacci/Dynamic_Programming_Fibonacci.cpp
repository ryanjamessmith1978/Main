// Dynamic_Programming_Fibonacci.cpp | https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
// YouTube search Dynamic Programming and watch explanation
// C++ program for Fibonacci Series
// using Dynamic Programming


#include <windows.h>
#include <iostream>

using namespace std;

class GFG {

public:
    int* fib(int n)
    {
        // Declare an array to store
        // Fibonacci numbers.
        // 1 extra to handle
        // case, n = 0
        int* f = new int[n + 2];
        int i;

        // 0th and 1st number of the
        // series are 0 and 1
        *f = 0;
        *(f+1) = 1;

        for (i = 2; i <= n; i++) {

            // Add the previous 2 numbers
            // in the series and store it
            *(f+i) = *(f + i - 1) + *(f + i - 2);
        }
        
        return f;
    }
};

// Driver code
int main()
{
    GFG g;
    int n = 9;
    int* fiba = g.fib(n);

    std::cout << *(fiba+n) << std::endl;  // memory leak.        
    system("pause");

    delete[] fiba;
    return 0;
}