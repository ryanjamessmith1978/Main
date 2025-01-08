#include <stdio.h>
#include <cs50.h>

// Binary Search - O(log(n))


int main(void) // Searching for 50 in this example
{
    // If no doors left to search
        // Return false - value isn't present in search
    // If 50 is behind middle door
        // Return true - value found
    // Else if (middle door > 50)
        // Search left half (doors[0] through doors[middle-1])
    // Else if (middle door < 50)
        // Search right half (doors[middle+1] through doors[end of right list - 1])  // minus 1 because of index 0


    return 0;
}
// Best case - lower bound - O(1)

// Binary Search algorithm - keeps halving the possible solution each iteration
// Binary Search assumes data is already sorted.

