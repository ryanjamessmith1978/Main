// SearchAlgorithms.cpp | https://www.geeksforgeeks.org/searching-algorithms/
// Linear Search, Sentinetal-Linear, Binary Search, Ternary Search
// Meta Binary Search (one-sided), Interpolation Search, Jump Search
//
// OTHER Search algorithms NOT COVERED: exponential, fibonacci, & ubiquitous binary.

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <windows.h>

using namespace std;

void LinearSearch();
int search(int arr[], int N, int x);

void SentinelLinearSearch();
void sentinelSearch(int arr[], int n, int key);

void BinarySearch();
int binarySearch(int* arr, int low, int high, int key);
int binarySearchRecursion(int* arr, int low, int high, int key);

void TernarySearch();
int ternarySearch(int l, int r, int key, int ar[]);

void MetaBinary();
int bsearch(std::vector<int> A, int key_to_search);

void InterpolationSearch();
int interpolationSearch(int arr[], int lo, int hi, int x);

void JumpSearch();
int jumpSearch(int arr[], int x, int n);

// ### SEARCH EXAMPLES ###
int main()
{
    // LinearSearch();
    // SentinelLinearSearch();
    // BinarySearch();
    // TernarySearch();
    // MetaBinary();
    // InterpolationSearch();
    // JumpSearch();
    system("pause");
}

void LinearSearch()
{
    // Linear Search is defined as a sequential search algorithm that starts at one end 
    // and goes through each element of a list until the desired element is found, 
    // otherwise the search continues till the end of the data set.

    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    int result = search(arr, N, x);
    if (result == -1)
        std::cout << "Element is not present in array" << std::endl;
    else
        std::cout << "Element is present at index " << result << std::endl;
}

void SentinelLinearSearch()
{
    /*
    The basic idea of Sentinel Linear Search is to add an extra element at the end of the array 
    (i.e., the sentinel value) that matches the search key. By doing so, we can avoid the conditional check 
    for the end of the array in the loop and terminate the search early, as soon as we find the sentinel element. 
    This eliminates the need for a separate check for the end of the array, resulting in a slight improvement.
    
    When and Where:
    The sentinel linear search algorithm is useful for arrays with a large number of elements where the target 
    value may be located towards the end of the array.
    */

    int arr[] = { 10, 20, 180, 30, 60, 50, 110, 100, 70 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 180;

    sentinelSearch(arr, n, key);
}

void BinarySearch()
{
    // *** BINARY SEARCH NOTES ***
// Works on sorted array.  Data needs to be sorted before searching!
// Divide & Conquer - Each iteration divides array in half.
// 
// Steps
// 1. Find middle element of array and check if that is the value you are looking for
// 2. If yes, exit the algorithm and return value
// 3. If no, check if that middle element is larger than the value we want.
// 4. If element is bigger, we want to shrink array to the left half of current array
// 5. If element is smaller, we want to shrink array to the right half of current array
// 6. Repeat until value is found.
//
// Complexity
// Time: O(log2(n))
// Best Case: O(1)
// Average Case: O(log2(n))
// ### QUESTIONS ###
// If half'n an array with an even number of elements, which side do you select as mid?
//  How is that decided in code?
// How do you run Binary search on something other than int numbers?

    int arr[] = { 1, 2, 3, 5, 7, 8, 9, 10 };

    std::cout << binarySearch(arr, 0, 7, 2) << std::endl; // returns index 1
    std::cout << binarySearchRecursion(arr, 0, 7, 2) << std::endl; // returns index 1
    std::cout << binarySearch(arr, 0, 7, 6) << std::endl; // returns -1, NOT found
    std::cout << binarySearch(arr, 0, 7, 10) << std::endl; // returns index 7
}

void TernarySearch()
{
    /*
     TS principle of dividing the array into three parts instead of two, as in binary search.

     STEPS:
     Below are the step-by-step explanation of working of Ternary Search:

     Initialization:
     Begin with a sorted array.
     Set two pointers, left and right, initially pointing to the first and last elements of the array.

     Divide the Array:
     Calculate two midpoints, mid1 and mid2, dividing the current search space into three roughly equal parts:
     mid1 = left + (right – left) / 3
     mid2 = right – (right – left) / 3
     The array is now effectively divided into [left, mid1], (mid1, mid2), and [mid2, right].
     
     Comparison with Target:.
     If the target is equal to the element at mid1 or mid2, the search is successful, and the index is returned
     If the target is less than the element at mid1, update the right pointer to mid1 – 1.
     If the target is greater than the element at mid2, update the left pointer to mid2 + 1.
     If the target is between the elements at mid1 and mid2, update the left pointer to mid1 + 1 
     and the right pointer to mid2 – 1.
     
     Repeat or Conclude:
     Repeat the process with the reduced search space until the target is found or the search space becomes empty.
     If the search space is empty and the target is not found, return a value indicating that the target 
     is not present in the array.

     WHEN AND WHERE:
     Sorted Array.
     When you have a large ordered array or list and need to find the position of a specific value.
     When you need to find the maximum or minimum value of a function.
     Ternary search can find maxima/minima for unimodal functions, where binary search is not applicable.
     Time:  O(2 * log3n)

     DISADVANTAGES:
    Ternary Search takes more time to find maxima/minima of monotonic functions as compared to Binary Search.

    */

    int l, r, p, key;

    // Get the array
    // Sort the array if not sorted
    int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Starting index
    l = 0;

    // end element index
    r = 9;

    // Checking for 5

    // Key to be searched in the array
    key = 5;

    // Search the key using ternarySearch
    p = ternarySearch(l, r, key, ar);

    // Print the result
    std::cout << "Index of " << key
        << " is " << p << std::endl;

    // Checking for 50

    // Key to be searched in the array
    key = 50;

    // Search the key using ternarySearch
    p = ternarySearch(l, r, key, ar);

    // Print the result
    std::cout << "Index of " << key
        << " is " << p << std::endl;
}

void MetaBinary() //  incrementally constructs the index of the target value in the array
{
    /*
    The Meta Binary (One-Sided) algorithm uses a heuristic to determine the size of the next interval. 
    It computes the difference between the value of the middle element and the value of the target element, 
    and divides the difference by a predetermined constant, usually 2. 
    This result is then used as the size of the new interval. 
    The algorithm continues until it finds the target element or determines that it is not in the list.

    WHEN AND WHERE:
    The advantage of Meta Binary Search over binary search is that it can perform fewer comparisons in some cases, 
    particularly when the target element is close to the beginning of the list.
    
    Time: O(log n)
    */

    std::vector<int> A = { -2, 10, 100, 250, 32315 };
    std::cout << bsearch(A, 10) << std::endl;
}

void InterpolationSearch()
{
    /*  INTERPOLATION SEARCH
    .   Interpolation constructs new data points within the range of a discrete set 
        of known data points. Binary Search always goes to the middle element to check. 
        On the other hand, interpolation search may go to different locations 
        according to the value of the key being searched.    
    */

    // Array of items on which search will    
    int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21,
                  22, 23, 24, 33, 35, 42, 47 };

    int n = sizeof(arr) / sizeof(arr[0]);

    // Element to be searched
    int x = 18;
    int index = interpolationSearch(arr, 0, n - 1, x);

    // If element was found
    if (index != -1)
        std::cout << "Element found at index " << index;
    else
        std::cout << "Element not found.";

    std::cout << "\n";
}

void JumpSearch()
{
    /*
    Jump Search is an algorithm for finding a specific value in a sorted array by jumping 
    through certain steps in the array. The steps are determined by the sqrt of the length of the array. 
    */

    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                34, 55, 89, 144, 233, 377, 610 };
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the index of 'x' using Jump Search
    int index = jumpSearch(arr, x, n);

    // Print the index where 'x' is located
    std::cout << "\nNumber " << x << " is at index " << index << std::endl;
}


// ### SEARCH FUNCTIONS ###
int search(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void sentinelSearch(int arr[], int n, int key)
{
    // Last element of the array
    int last = arr[n - 1];

    // Element to be searched is
    // placed at the last index
    arr[n - 1] = key;
    int i = 0;

    while (arr[i] != key)
        i++;

    // Put the last element back
    arr[n - 1] = last;

    if ((i < n - 1) || (arr[n - 1] == key))
        std::cout << key << " is present at index " << i << std::endl;
    else
        std::cout << "Element Not found" << std::endl;
}

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

int bsearch(std::vector<int> A, int key_to_search)
{
    int n = (int)A.size();
    // Set number of bits to represent largest array index
    int lg = log2(n - 1) + 1;

    //while ((1 << lg) < n - 1)
        //lg += 1;

    int pos = 0;
    for (int i = lg; i >= 0; i--) {
        if (A[pos] == key_to_search)
            return pos;

        // Incrementally construct the
        // index of the target value
        int new_pos = pos | (1 << i);

        // find the element in one
        // direction and update position
        if ((new_pos < n) && (A[new_pos] <= key_to_search))
            pos = new_pos;
    }

    // if element found return pos otherwise -1
    return ((A[pos] == key_to_search) ? pos : -1);

    /* META BINARY SEARCH PSEUDOCODE
    function meta_binary_search(A, target):
    n = length(A)
    interval_size = n
    while interval_size > 0:
        index = min(n - 1, interval_size / 2)
        mid = A[index]
        if mid == target:
            return index
        elif mid < target:
            interval_size = (n - index) / 2
        else:
            interval_size = index / 2
    return -1
    
    */
}

int ternarySearch(int l, int r, int key, int ar[])
{
    if (r >= l) {

        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Check if key is present at any mid
        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }

        // Since key is not present at mid,
        // check in which region it is present
        // then repeat the Search operation
        // in that region
        if (key < ar[mid1]) {

            // The key lies in between l and mid1
            return ternarySearch(l, mid1 - 1, key, ar);
        }
        else if (key > ar[mid2]) {

            // The key lies in between mid2 and r
            return ternarySearch(mid2 + 1, r, key, ar);
        }
        else {

            // The key lies in between mid1 and mid2
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
        }
    }

    // Key not found
    return -1;
}

int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;

    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {

        // Probing the position with keeping
        // uniform distribution in mind.
        pos = lo
            + (((double)(hi - lo) / (arr[hi] - arr[lo]))
                * (x - arr[lo]));

        // Condition of target found
        if (arr[pos] == x)
            return pos;

        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);

        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}

int jumpSearch(int arr[], int x, int n)
{
    // Finding block size to be jumped
    int step = sqrt(n);

    // Finding the block where element is
    // present (if it is present)
    int prev = 0;
    while (arr[min(step, n) - 1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    // Doing a linear search for x in block
    // beginning with prev.
    while (arr[prev] < x)
    {
        prev++;

        // If we reached next block or end of
        // array, element is not present.
        if (prev == min(step, n))
            return -1;
    }
    // If element is found
    if (arr[prev] == x)
        return prev;

    return -1;
}