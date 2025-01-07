// BinarySearch.cpp : 

#include <iostream>
#include <algorithm>

int binarySearch(int* arr, int low, int high, int key) // returns the index
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < key) // top half, change low
            low = mid + 1;
        else if (arr[mid] > key) // bottom half, change high
            high = mid - 1;
        else
            return mid;
    }

    return -1; 
}

int binarySearchRecursion(int* arr, int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        high = mid - 1;
    else
        low = mid + 1;

    binarySearchRecursion(arr, low, high, key);
}

int main()
{
    int arr[] = { 1, 2, 3, 5, 7, 8, 9, 10 };

    std::cout << binarySearch(arr, 0, 7, 2) << std::endl; // returns index 1
    std::cout << binarySearchRecursion(arr, 0, 7, 2) << std::endl; // returns index 1
    std::cout << binarySearch(arr, 0, 7, 6) << std::endl; // returns -1, NOT found
    std::cout << binarySearch(arr, 0, 7, 10) << std::endl; // returns index 7
    

    system("pause");
}

// *** BINARY SEARCH NOTES ***
// Works on sorted array.  Data needs to be sorted before searching!
// Divide & Conquer - Each iteration divides array in half.

// Steps
// 1. Find middle element of array and check if that is the value you are looking for
// 2. If yes, exit the algorithm and return value
// 3. If no, check if that middle element is larger than the value we want.
// 4. If element is bigger, we want to shrink array to the left half of current array
// 5. If element is smaller, we want to shrink array to the right half of current array
// 6. Repeat until value is found.

// Complexity
// Time: O(log2(n))
// Best Case: O(1)
// Average Case: O(log2(n))

// ### QUESTIONS ###
// If half'n an array with an even number of elements, which side do you select as mid?
//  How is that decided in code?
// How do you run Binary search on something other than int numbers?
