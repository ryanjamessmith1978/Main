// BubbleSort.cpp

#include <iostream>

template <typename PData>
void Swap(PData& xrItem1, PData& xrItem2) {
	PData xTemp = xrItem1;
	xrItem1 = xrItem2;
	xrItem2 = xTemp;
}

template <typename PData>
void PrintArray(PData xaArray[], int iLength) {
	using namespace std;
	for (int iIndex = 0; iIndex < iLength; ++iIndex) {
		cout << xaArray[iIndex] << "  ";
	}
	cout << endl;
}

// BubbleSort - Big O of n-squared O(n^2)
template <typename PData> // n-1 comparisons + n-2 comparison ... = n(n-1) - n/2 = O(n^2)    
void Bubblesort(PData xaArray[], int iLength) { // gets largest number to end of array 
	for (int iEnd = iLength - 1; iEnd > 0; --iEnd) { //  end = end - 1; per each inner pass
		for (int iIndex = 0; iIndex < iEnd; ++iIndex) { // starts comparing starting at beginning again
			if (xaArray[iIndex] > xaArray[iIndex + 1]) {
				Swap(xaArray[iIndex], xaArray[iIndex + 1]); // swaps if left value > right value
			}
		}
	}  
}

// int A[10];
// for i = (n-1) to 1 | start at the end, and change end to 1 less element per each inner pass
	// for j = 0 to (i-1) | start at the beginning, compare moving left to right
		// if A[j] < A[j+1] | push smaller values left as moving left to right
			// swap(A[j], A[j+1]) | swap values in the array

void main() {
	using namespace std;

	// First example
	double daArray[] = { 2.5, .7, 9.7, 6.5, 3.4, 1.8 };
	PrintArray(daArray, 6);
	Bubblesort(daArray, 6);
	PrintArray(daArray, 6);

	// Second example
	char caArray[] = "xoax.net";
	cout << caArray << endl;
	Bubblesort(caArray, 8);
	cout << caArray << endl;

	system("pause");
}