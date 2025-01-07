// Sort_Algorithms.cpp 
// Bubble Sort(), Selection Sort(), Merge Sort()
// Insertion Sort(), Quick Sort(), Counting Sort(), Heap Sort()

// IntroSort, QuickSort(), HeapSort(), then InsertionSort()
// IntroSort is implemented using hybrid of QuickSort, HeapSort and InsertionSort.By default, 
// it uses QuickSort but if QuickSort is doing unfair partitioning and taking more than N*logN time, 
// it switches to HeapSort and when the array size becomes really small, it switches to InsertionSort

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <utility>
#include <stdio.h>
using namespace std;

void SelectionSort();
void BubbleSort();
void mergeSort(int A[], int low, int high);
void merge(int A[], int low, int high, int mid);
void MergeSortExample();
void InsertionSortExample();
void insertion_sort(int a[], int size);
void QuickSortExample();
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
 int partition(int array[], int low, int high); 

void CountingSortExample();
void countingSort(int arr[], int n, int max);
void HeapSortExample();
void heapSort(vector<int>& heap);
void heapify(vector<int>& heap, int current, int size);
void printVector(std::vector<int>& v);

int main()
{
    // SelectionSort();
    // BubbleSort();
    // MergeSortExample();
    // InsertionSortExample();
    // QuickSortExample();
    // CountingSortExample();
    // HeapSortExample();    

    system("pause");
}

void SelectionSort()
{
    // Selecting the smallest element again and again, and putting them in appropriate place.
    // Take a pass for all element still unsorted, track smallest value, and put the smallest value at beginning of unsorted.
    // add 1 to sorted, subtract one from unsorted, start again at beginning of unsorted tracking min value again.

    // https://www.youtube.com/watch?v=4oqjcKenCH8
    // From 0 to size-1
    //  Find smallest number between numbers[i] and numbers[size-1] // outer array sorted
    //  Swap number with numbers[i] // inner array unsorted
    
    std::vector<int> numbers = { 1,5,2,3,7,4,6 };
    int min;
    int minIndex;

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        min = numbers[i];
        minIndex = i;

        for (int j = i; j < numbers.size(); j++) // Mistake: int j = 0, instead of j=i;
        {
            if (numbers[j] < min)
            {
                min = numbers[j];
                minIndex = j;
            }
        }

        swap(numbers[i], numbers[minIndex]); // Mistake: numbers[j] instead of numbers[minIndex]
    }    

    printVector(numbers); // 1,2,3,4,5,6,7  | 5,2,3,7,4,1,6
}

void BubbleSort()
{
    // https://www.youtube.com/watch?v=4oqjcKenCH8
    // Repeat n-1 times
    //  For i from 0 to n-2
    //      if numbers[i] and numbers[i+1] are out of order
    //          Swap numbers

    std::vector<int> numbers = { 1,5,2,3,7,4,6 };

    for (int i = 0; i < numbers.size() - 2; i++)
    {
        for (int j = i + 1; j < numbers.size() - 1; j++)
        {
            if (numbers[i] > numbers[j])
                swap(numbers[i], numbers[j]);
        }
    }

    printVector(numbers);
}

void MergeSortExample() 
{
    // https://www.youtube.com/watch?v=RZK6KVpaT3I&t=205s
    // O(n*log(n))
    // LIFO recursion
    // Divide and Conquer
    // High memory usage for faster sorting.
    // Continous divides and array into sub arrays recursively until only one element in each sub-Array.
    // Then, recursively merge arrays by sorting them until one array is left.
    // Keeps a low and high index to indentify what subArray values need sorted.

    const int arraySize = 4;
    int A[arraySize] = { 5,1,3,2 };

    int low = 0;                                                // [0:1] - merge(A, low, high, mid); m(A, 0, 1, 0); 
    int high = arraySize - 1;                                   // [1:1] - mS[1,1] - returns, both mS calls for [0:1] finishes, now merge[0:1]
                              // finishes previous call  -      // [0:1] - ms(mid+1, high) mS[0,1] 
                                                                // 
                                                                // [0:0] - ms(low, mid) mS[0,0] - returns, pops off
                                                                // [0:1] - ms(low, mid) mS[0,1] - push
                                                                // [0:3] - ms(low, mid) mS[0,3] - push
                                                                // [0:6] - mS(low, mid) mS[0,6] - pushes to bottom of call stack

    mergeSort(A, low, high); // // A[0:6] first entry 

    for (int i = 0; i < arraySize; i++)
    {
        std::cout << A[i] << ", ";
    }

    std::cout << "\n";
}

void mergeSort(int A[], int low, int high)
{
    if (low < high) // checks if only one element remains. if it does, the subarray that made this call is already sorted.
    {
        int mid;
        mid = (low + high) / 2;

        mergeSort(A, low, mid); // sorts left side
        mergeSort(A, mid + 1, high); // sorts right side

        // merges 2 sub-arrays.
        merge(A, low, high, mid); // last valid subArray values(low,mid,high) before returning on calls above.

        // [0:1] - merge(A, low, high, mid); m(A, 0, 1, 0);  mid is 0 because of int truncation: (0+1)/2 = 0.5 = 0
        // [1:1] - mS[1,1] - returns |  Both mergeSort calls for [0:1] low and high finish, now merge[0:1]
        // [0:1] - ms(mid+1, high) mS[0,1] 
        // 
        // [0:0] - ms(low, mid) mS[0,0] - returns, pops off
        // [0:1] - ms(low, mid) mS[0,1] - push (merge(0,1) left half, merge(0,1) right half)
        // [0:3] - ms(low, mid) mS[0,3] - push (merge(whole list, comparing 0,3).  
        // [0:6] - mS(low, mid) mS[0,6] - pushes to bottom of call stack
    }
}

void merge(int A[], int low, int high, int mid)
{
    // Looks at 2 pseudo sub-arrays |
    // defined with index variables passed in
    // merge combines 2 arrays in sorted order.

    int i, j, k;
    int c[50];
                        
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            c[k] = A[i];
            i++;
            k++;            
        }
        else
        {
            c[k] = A[j];
            j++;
            k++;            
        }
    }

    while (i <= mid)
    {
        c[k] = A[i];        
        i++;
        k++;
    }

    while (j <= high)
    {
        c[k] = A[j];        
        j++;
        k++;
    }

    for (i = low; i < k; i++)
    {
        A[i] = c[i];
    }
}

void InsertionSortExample()
{
    // https://www.youtube.com/watch?v=PEhwXHEPbmI&t=17s
    // builds sorted array one element at a time.  
    // building up a sorted array on left, and an unsorted right portion of the array.
    // first unsorted moves left checking if it's less than the value and keeps moving left until it's greater than left value.
    // opposite bubble sort, values sink to the begining of the array, then values to the right of current index gets shifted right. 

    /*int a[] = { 8, 2, 7, 4, 5, 1, 9, 3 };
    int length = sizeof(a) / sizeof(int);
    insertion_sort(a, length);*/

    int arr[] = { 8,1,7,6,5,0,11,13 };
    int size = sizeof(arr) / sizeof(int);
    insertion_sort(arr, size);

    for (int x : arr)
        std::cout << x << ", ";

    cout << std::endl;
    
}

void insertion_sort(int a[], int size)
{  
    // int arr[] = { 8,1,7,6,5,0,11,13 }; scanning left to right of unsorted, use a key value, find the index, shift everything right, insert
    // i is unsorted, j is sorted.  We are inserting key in the outer portion.  j is leftmost sorted, so, j+1 will be the index added to sorted.

    for (int i = 1; i < size; i++)
    {
        int key = a[i]; 
        int j = i - 1;

        while (j >= 0 && a[j] > key) // while index value of j is greater than current key, keep going.  stop, when a[j] < key.
        {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = key;
    }

    // a[] = {8,2,7,4,5,1,9,3};
    // i looks at each unsorted portion of the array.
    //for (int i = 1; i < size; i++)     
    //{               
    //    int key = a[i];  // key is the value in the outer loop that needs to be sorted.
    //    int j = i - 1;  // keeps track of position in the sorted portion of array as we shift values.   
    //    while (j >= 0 && a[j] > key) // until j gets to 0 and the array's value at j > current key value (a[i]). keep looping
    //    {
    //        a[j + 1] = a[j]; // shifts all values right.
    //        j = j - 1; // keeps track of the index in left hand sorted portion of array.  
    //    }               // j = -1 exits the inner loop, because it's reached the beginning of array.

    //    a[j + 1] = key; // key value inserted into correct position.
    //}
}

void QuickSortExample()
{
    // https://www.youtube.com/watch?v=vhSLT3a-t-A&t=811s

    int a[] = { 10, 11, 23, 44, 8, 15, 3, 9, 12, 45, 56, 45, 45 };
    int length = sizeof(a) / sizeof(int);

    quicksort(a, length);

    for (int i = 0; i < length; i++)
    {
        std::cout << a[i] << ", ";
    }

    std::cout << endl;
}

void quicksort(int array[], int length)
{
    // our quicksort algorithm randomly selects the pivot, so we seed the random 
    // number generator to ensure the randomization of our random numbers
    srand(time(NULL));

    quicksort_recursion(array, 0, length - 1);
}

void quicksort_recursion(int array[], int low, int high)
{
    // stop recursion when low >= high
    if (low < high)
    {
        // partition the array by a pivot, and return the pivot element's index
        int pivot_index = partition(array, low, high);

        // apply quicksort to the left side subarray
        quicksort_recursion(array, low, pivot_index - 1);

        // apply quicksort to the right side subarray
        quicksort_recursion(array, pivot_index + 1, high);
    }
}

int partition(int array[], int low, int high)
{
    // index of the pivot after partition. int return
    // https://www.youtube.com/watch?v=vhSLT3a-t-A&t=811s

    // randomly select a pivot value between low-high by randomly selecting an
    // index in the range low-high... we do this as opposed to just selecting 
    // the last element each time because it's technically possible that always 
    // selecting the same pivot will have poor performance if the array happens 
    // to contain values in a way that is suboptimal (e.g. if the array is sorted
    // already before quicksort is applied)
    int pivot_index = low + (rand() % (high - low + 1)); // int pivot_value = array[high]; int i = low; 


    // swap the element at the pivot_index with the element at index high (i.e. 
    // the last element in this portion of the array), doing so allows us to 
    // apply the below partitioning algorithm
    if (pivot_index != high)
    {
        swap(array[pivot_index], array[high]);
    }

    // the pivot value is now whatever is in the high index
    int pivot_value = array[high];

    // the partitioning algorithm will shift elements that are less than the pivot
    // value to the front portion of the low - high array indexes, with i keeping
    // track of where the elements that are greater than the pivot value begin
    int i = low;

    // increment j from low up until but not including the pivot value at high
    for (int j = low; j < high; j++)
    {
        // if the array value at j is less than the pivot value, perform a swap with
        // the value at the array at index i... this effectively moves this "less 
        // than the pivot values" to the front portion, and we increment i to 
        // reflect where the values that are greater than the pivot now begin
        if (array[j] <= pivot_value)
        {
            swap(array[i], array[j]);
            i++;
        }
    }

    // we now know that the value at index i is greater than or equal to the pivot
    // so we swap it with the pivot value to complete the partition 
    swap(array[i], array[high]);

    // index i now contains the pivot value, so return this so that the 
    // quicksort_recursion function knows where to split the array when applying 
    // the algorithm to the resulting subarrays
    return i;
}

void CountingSortExample()
{
    // O(n)
    // NOTE: Counting Sort is efficient sort if range(largest value) 
    // is similar to number of total element in initial array.
    // Analyze data before applying an algorithm to see which algorithm works best.
    // When will this algorithm be more efficient than a O(n*log(n))?

    https://www.youtube.com/watch?v=vhSLT3a-t-A&t=811s

    int i = 0;
    int max = 0;
    const int arrSize = 10;
    int arr[arrSize] = { 0 };
       
    for (int i = 0; i < arrSize; i++)
    {
        printf("Enter Element: ");
        if (scanf("%d", &arr[i])) // Needs an error check, while(not a bad value)...
        {
            if (arr[i] > max)
                max = arr[i];
        }
    }

    countingSort(arr, arrSize, max);
}

void countingSort(int arr[], int n, int max)
{
    // Increase the count by 1 for the value in the intial array to the corresponding index of the count array.
    // [3,0,2,7,2,1,4] initial array
    // [0,0,0,0,0,0,0,0] initial count array (size based on largest value)
    // [1,1,2,1,1,0,0,1] final count array // add a +1 to index 3 for the first element in intial array. 
    // sorted:[0,1,2,2,3,4,7] final sorted array | skip the 0s of counted array.
    
    // count array
    int count[50] = { 0 }; // dynamic setup here would be better code than magic number
    int i, j;

    for (i = 0; i < n; i++) // +1 value to the indexed location in count associated with value of initial array.
        count[arr[i]] = count[arr[i]] + 1;

    std::cout << "Elements: "; 

    for (i = 0; i <= max; ++i)
    {
        // prints final sorted values - but doesn't create sorted array
        for (j = 1; j <= count[i]; ++j) // non-zero element because if count array has a zero value for that index
        {                                // the final sorted array doesn't get that array index added.
            printf("%d, ", i);
        }
    }

    std::cout << std::endl;    
}

void HeapSortExample()
{
    // Heap sort is | https://www.youtube.com/watch?v=kU4KBD4NFtw
    
    std::vector<int> heap = { 9,6,8,2,1,4,3 };
    heapSort(heap);

    std::cout << "Heap in Ascending Order: \n";
    for (int i = 0; i < heap.size(); i++)
        std::cout << heap[i] << ", ";
    cout << "\n";

    system("pause");
}

void heapSort(vector<int>& heap)               
    
    // Time: O(nlog(n)), Space: O(log(n))
    // Build_Max_Heap
    // for (i = size()-1; i > 0; i++)
    //      Swap(a[0], a[i]);
    //      Max_Heapify(a, 0);
                                                                                            // 9
{                                                                                      //6       //8
    // Make a max heap from array - create a tree [9, 6, 8,                         //2  //1   //4 //3
    // Given max heap, sort elements in ascending order  
    // After copying last element to the root, the last edge to that last element is removed. reducing heap size by 1.
    
    // Extract max element, put it aside, max = 9;
    // last element in heap gets copied to the root 3 to arr[0]
    // last link to 3 from 9 is broken, reducing the heap size. 
    // Reduce heapsize each iteration before doing a max heapify.    

    // Builds Initial Max_Heap
    for (int i = (heap.size() / 2) - 1; i >= 0; i--) // if already a heap, skip.
    {
        heapify(heap, i, heap.size());
    }

    for (int i = heap.size() - 1; i > 0; --i)
    {
        int max = heap[0];  // store the max variable temporarily. 
        heap[0] = heap[i];  // swap heap root with last element
        heap[i] = max;

        heapify(heap, 0, i); // heapify root with heapsize = i;
    }   
}

void heapify(vector<int>& heap, int current, int size)
{
    // starts at root, checks bottom 2 below that
    // which is greater between those is swapped.
    // happens again only to the lower value that was swapped.  
    // repeats the process until bottom of tree.

    int largest = current;
    int left = (2 * current) + 1; // left child
    int right = (2 * current) + 2; // right child

    if (left < size && heap[left] > heap[largest]) // find the largest between parent and left child.
        largest = left;

    // finds the largest between parent and right child (largest could be updated to left child before this check).
    if (right < size && heap[right] > heap[largest]) // ultimately if the right child is largest, it will be swapped with parent.
        largest = right;

    if (largest != current) // recursively calls (like a while loop here) heapify until current root = largest.  
    {
        int temp = heap[current];
        heap[current] = heap[largest];
        heap[largest] = temp;

        heapify(heap, largest, size); // tree traversal recursively swapping.
    }
}

void printVector(std::vector<int>& v)
{
    for (int x : v)
        std::cout << x << ", ";

    std::cout << endl;
}

    
/* 

    MERGE SORT

    If only one number // How do you decide on odd # of elements?
    //  Quit
    // Else
    //  Sort Left half of numbers
    //  Sort Right half of numbers
    //  Merge Sorted Halves
    //
    // std::vector<int> numbers = { 1,5,2,3,7,4,6,0 };
    //
    // cut vector in half
    // if mid = 4, return;
    // else
    // Sort 1,5,2,3 to   {1,2,3,5}
    // Sort 3,7,4,6 to   {0,4,6,7}
    // Merge {1,2,3,5} & {0,4,6,7} = 
    // Compare 1:0, 1:4, 2:4, 3:4, 5:4, 5:6
    //          0 ,  1 ,  2,   3,   4,   5,  6,  7
    //
    //cut in half
    // {1,5}  : {2,3}
    // cut in half
    // {1} {5}
    // 1 is sorted cause only 1, right half is 5, and it's one, so done
    // merge, 1, 5 {1,5}
    // now the righ half, left half, then right half, then merge
    // merge {1,5} : {2,3}, 1 to 2 (1), 5 to 2(2), 5 to 3(3), 5 is last
    // {1,2,3,5}
 */