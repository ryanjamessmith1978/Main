// Deques are expandable arrays like Vectors (both bad at removing stuff in the middle of an array) FIFO container.

// Difference between Deques and Vectors are:
// Deques - can push things back starting at the beginning of the array container, as well as at the end.  Double ended queue.
// Deques have multiple little blocks of memory that aren't sequential in memory.
// Deques have pointers for each individual block of memory.  

// Vectors - can remove elements from the end (or adding a single element on the back) 
// Vectors have a single sequential block of memory that when elements added to the end, it's the next block of memory available.

#include <iostream>
#include <deque>

using std::deque;
using std::cout;
using std::endl;

int main()
{
	deque<int> myDeque(5, 0); // {0, 0, 0, 0, 0}

	for (int i = 0; i < myDeque.size(); i++)
	{
		cout << "# " << i << ": " << myDeque[i] << endl;
	}

	// puts element with value of 10 at the back of the container, adding an index to the container.
	myDeque.push_back(10);

	// puts element with value of 10 at the front of the container, adding an index to the container.
	myDeque.push_front(10);

	// removes first element of array
	myDeque.pop_front();

	// removes last element of array
	myDeque.pop_back();

	return 0;
}