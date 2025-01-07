// STL-Algorithms.cpp : | https://www.youtube.com/watch?v=9OdKLDBOe-0

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <list>
#include <cstdlib>
#include <random>
#include <functional>
#include <algorithm>
#include "Student.h"
using namespace std;

void AverageHeap();
void BasicHeap();
void Copy();
void Count();
void Count_If();
void Find();
void ForEach();
void Generate();

void Lambdas();
void MaxMinSort();
void MergeSort();
void Mismatch();
void Move();
void NextPermutation();
void NextPermutationStr();
void Partition();
void PartitionPoint();
void PrintStudentArray(Student* sArr, int arrSize);
void PrintVector(std::vector<int> v);
void RandomGenerate();
void RandomShuffle_Algorithm();
void Reverse();
void Rotate();

void SetUnion();
void SetIntersection();
void SetSymmetricDifference();
void SetDifference();
void Sort();
void STL_BinarySearch();
void Swap();
void Swap_Ranges();
bool UserDefinedCondition(int a, int b);
void VectorMinMax();

// ### MAIN ###
int main()
{	
	// AverageHeap();
	// BasicHeap();
	// Copy();
	// Count();
	// Count_If();
	// Find();
	// ForEach();
	// Generate();

	// Lambdas();
	// MaxMinSort();
	// MergeSort();
	// Mismatch();
	// Move();
	// NextPermutation();
	// NextPermutationStr();
	// Partition();
	// PartitionPoint();
	
	// RandomGenerate();
	// RandomShuffle_Algorithm();
	// Reverse();
	// Rotate();

	// SetUnion();
	// SetIntersection();
	// SetSymmetricDifference();
	// SetDifference();
	// Sort();
	// STL_BinarySearch();
	// Swap();
	// Swap_Ranges();	
	// VectorMinMax();

	system("pause");
}


void AverageHeap()
{
	std::vector<int> heap = { 3,2,1,5,6 };

	auto fn = [](int& a, int& b) {return a > b; };

	make_heap(heap.begin(), heap.end(), fn);

	heap.push_back(9);
	push_heap(heap.begin(), heap.end(), fn);

	pop_heap(heap.begin(), heap.end(), fn);
	heap.pop_back();

	bool bIsHeap = is_heap(heap.begin(), heap.end(), fn);
	(bIsHeap) ? std::cout << "Is a Heap!\n" : std::cout << "Is NOT a Heap!\n";
	PrintVector(heap);
}

void BasicHeap()
{
	std::vector<int> heap = { 3, 2, 1, 5, 6 };
	//6
	// Max_heap tree. Left to right, top to bottom                  //5    //1
	// make_heap turns vector into a tree data structure (heap)  //3  //2
	make_heap(heap.begin(), heap.end());
	PrintVector(heap); // {6,5,1,3,2};                                            

	// Push
	heap.push_back(9);
	push_heap(heap.begin(), heap.end()); // add 9 to tree and shifts it.    
	PrintVector(heap); // {9,5,6,3,2,1};

	// Pop
	pop_heap(heap.begin(), heap.end());
	// printVector(heap); // {6,5,1,3,2,9};
	heap.pop_back(); // back to original
	PrintVector(heap); // {6,5,1,3,2};

	// Is this container a heap? is_heap
	(is_heap(heap.begin(), heap.end()))
		? std::cout << "This is a Heap!" : std::cout << "This is NOT a heap!";
	cout << "\n";

	heap.push_back(92);
	heap.push_back(11);
	heap.push_back(19);
	PrintVector(heap); // {6,5,1,3,2,92,11.19}
	std::vector<int>::iterator it = is_heap_until(heap.begin(), heap.end());
	std::cout << "Is Heap until => " << *it << endl;
}

void Copy()
{
	// Copy
	std::vector<int> vs = { 1, 2, 3, 4, 5, /* end(), end()+1 */ };
	std::vector<int> vs2;
	vs2.resize(6);  // copy: vs.end() is up to, but not including end(), as end is one past the bounds.
	copy(vs.begin(), vs.end() + 1, vs2.begin()); // copy needs to use same type of container.

	for (int x : vs2)
		cout << x << std::endl;

	cout << "\n--------------------------------------\n";

	// Copy_If
	std::vector<int> vs3;
	vs3.resize(6);
	copy_if(vs.begin(), vs.end(), vs3.begin(), [](int& x) {return x % 2 == 0; });

	for (int x : vs3)
		cout << x << endl;

	cout << endl;
}

void Count()
{
	std::vector<int> vs = { 1, 1, 1, 1, 2, 3, 12, 1, 4, 41, 1, 1 };

	// count(begin, end, value);
	std::cout << "Number of times the element value of 1 appears: "
		<< count(vs.begin(), vs.end(), 1) << std::endl;
}

void Count_If()
{
	// function<bool(int&)> cond = [](int& a) {return a < 20; }; // normal lambda declaration

	std::vector<int> vs = { 1, 1, 1, 1, 2, 3, 12, 1, 4, 41, 1, 1 };

	// count_if algorithm using lambda as an inline parameter                  
	cout << count_if(vs.begin(), vs.end(), [](const int& a) { return a < 10; }); // counts + 1 if value of a < 10
	// a is passed in as a vector element.
	cout << endl;
	// Lambda function can be aware of other things that exist in your function.
	// Use a '[]' as a capture list.
	int b = 4;
	int c = 5; // & captures b + c  and all v other variables outside of the lamba function
	cout << count_if(vs.begin(), vs.end(), [&](const int& a) {return a > b + c; }) << "\n";
}

void Find()
{
	/*
	The find() function in C++ returns the iterator to the first element matched based on value.
	If the value is not matched, then the function returns the iterator to the last element of the range.
	So, vector, list, ect have a default end() iterator associated with that container.
	The find() function will look for the value, and if not found, the end() iterator is returned.
	*/

	std::vector<int> vs = { 11, 41, 27, 52, 33 };

	// find() returns an iterator
	std::vector<int>::iterator it = find(vs.begin(), vs.end(), 11);  // Same as vs.begin();
	// std::cout << *it << std::endl;  Output: return 11;
	std::cout << *(++it) << std::endl; // Output: //return 41;

	if (find(vs.begin(), vs.end(), 34) == vs.end()) // end() is one-past last element, like '/O' of a string. 
		cout << "Not Found" << endl; // if after searching values, if left with end iterator, not found.
	else
		cout << "Found" << endl;
}

void ForEach()
{
	std::vector<int> vs = { 1, 2, 3, 4, 5 };

	for_each(vs.begin(), vs.end(), [](int& a) { cout << a * a << endl; }); // no return on this lamba

	// how to use an external predictors on this function (userDefinedCondition())?
}

void Generate()
{
	std::vector<int> data(10);

	generate(data.begin(), data.end(),
		[]() { return rand() % 100; });

	PrintVector(data);
}

void Lambdas()
{
	// Lambda Function | needs #include<functional>
	// Functions that are declared inline.  
	// Uses a function ptr variable to store the lambda function.
	// To declare a lambda function, the syntax starts with '[]' brackets, then params.

	// lambda function syntax: <return value (param) > 
	function<bool(int)> cond = [](int a) {return a < 20; };

	// Problem: Find a value that is less than 20?
	std::vector<int> vs = { 11, 41, 27, 52, 33 };

	if (find_if(vs.begin(), vs.end(), cond) == vs.end()) // if it gets to the end iterator, then its not found
		std::cout << "Not Found!" << std::endl;
	else
		std::cout << "Found!" << std::endl;
}

void MaxMinSort()
{
	function<bool(const Student, const Student)> SrtLowestGrade
		= [](Student s1, Student s2) { return s1.getGrade() < s2.getGrade(); };

	function<bool(const Student, const Student)> SrtGreatestGrade
		= [](Student s1, Student s2) { return s1.getGrade() > s2.getGrade(); };

	function<bool(const Student, const Student)> SrtByName
		= [](Student s1, Student s2) { return s1.getName() < s2.getName(); };

	const int size = 5;
	Student sArray[size];

	sArray[0] = { "John", 20, 'm', 9.0f };
	sArray[1] = { "Bob", 21, 'm', 8.0f };
	sArray[2] = { "Alice", 19, 'f', 9.2f };
	sArray[3] = { "Eve", 20, 'f', 8.5f };
	sArray[4] = { "Saldina", 22, 'f', 7.2f };

	// MAX_ELEMENT() & MIN_ELEMENT()
	// Max_Element & Min_Element need to have list sorted in ascending order, lowest first.    
	Student* maxGradeStudent = max_element(sArray, sArray + size, SrtGreatestGrade); // func passed in sorts.
	std::cout << "Best Student: " << maxGradeStudent->getName() << std::endl;

	Student* minGradeStudent = min_element(sArray, sArray + size, SrtLowestGrade);
	std::cout << "Worst Student: " << minGradeStudent->getName() << std::endl;

	for (int i = 0; i < size; i++)
	{
		if (sArray[i].getName() == "Alice")
			sArray[i].setGrade(10.0f);
	}

	// STUDENT SORTING

	std::sort(sArray, sArray + size, SrtLowestGrade); // passing in a func doesn't require '()'
	std::cout << "Sorting By Lowest Grade" << std::endl;
	PrintStudentArray(sArray, size);

	std::sort(sArray, sArray + size, SrtByName); // passing in a func doesn't require '()'
	std::cout << "Sorting By Name" << std::endl;
	PrintStudentArray(sArray, size);

	std::cout << "Sorting By Name In Reverse" << std::endl;
	std::reverse(sArray, sArray + 5);
	PrintStudentArray(sArray, size);
}

void MergeSort()
{
	// Requires that both vector's be pre-sorted or Exception Error!
	std::vector<int> a = { 1, 4, 6, 8, 9 };
	std::vector<int> b = { 1, 2, 3, 4, 5 };
	std::vector<int> c(20);

	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	for (int x : c)
		cout << x << endl;
}

void Mismatch()
{
	// Mismatch: using mismatch we can find the first mismatching elements from two containers.
	// mismatch(.,.,.,.) returns a pair<iterator, iterator> iterators.  
	std::vector<int> a = { 1, 2, 3, 4, 5 };
	std::vector<int> b = { 1, 2, 3, 6, 7 }; // {4:6} mismatch from a and b. Also true for 2nd mismatch().

	std::vector<int> c = { 1, 2, 3, 3, 7 }; // {5:7} 4>=3, so we skip index[4]. 5>=7 is false, so that's returned.
	std::vector<int> d(20);

	std::pair<vector<int>::iterator, vector<int>::iterator> pit;
	pit = mismatch(a.begin(), a.end(), b.begin(), b.end()); // Output: 4,6
	std::cout << *(pit.first) << "," << *(pit.second) << "\n---------------\n";

	pit = mismatch(a.begin(), a.end(), b.begin(), b.end(), [](int a, int b) {
		return a >= b; // a >= b considered match, so we skip.  Return pair on FALSE, not true.
		});  // Output: 5,7 : a < b is a mismatch, so we return first pair of mismatch.  First false condition we return.  

	std::cout << *(pit.first) << "," << *(pit.second) << std::endl;
}

void Move()
{
	/*
	std::move() is a function used to convert an lvalue reference into the rvalue reference.
	Used to move the resources from a source object for efficient transfer of resources.


	The Purpose of a move constructor is to steal or move as many resources
	as it can from the source (original) object, as fast as possible.
	The source does not need to have a meaningful value anymore,
	because it is going to be destroyed in a moment anyway.
	std::move avoids unnecessarily creating copies of an object

	// des = (string&&)str
	// cast str with a string&& rvalue forces move constructor to be called.
	*/

	std::vector<int> vs = { 1, 2, 3, 4, 5 };

	std::string apple = "Apple";
	std::string dest;

	std::cout << "Apple: " << apple << std::endl;
	std::cout << "Dest: " << dest << std::endl;

	std::cout << "Using std::move to move apple into dest: " << std::endl;

	dest = std::move(apple); // assignment operator casting rvalue ref
	std::cout << "Dest: " << dest << std::endl;
}

void Partition()
{
	std::vector<int> data(10);
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<unsigned int> dist(1, 100);
	generate(data.begin(), data.end(), [&]() {
		return dist(rng);
		});

	PrintVector(data);

	auto it = partition(data.begin(), data.end(), [](int x)
		{ return x % 2; });

	std::cout << "Partition Point: " << *it << std::endl;
	PrintVector(data);
}

void PartitionPoint()
{
	std::vector<int> data(10);
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<unsigned int> dist(1, 100);
	generate(data.begin(), data.end(), [&]() {
		return dist(rng);
		});

	auto it = partition(data.begin(), data.end(), [](int x)
		{ return x % 2; });

	vector<int>::iterator it2 = partition_point(data.begin(),
		data.end(), [](int x) { return x % 2; });

	PrintVector(data);
	std::cout << "Partition Point: " << *it2 << std::endl;
}

void NextPermutation()
{
	std::cout << "---Next Permutation---\n";
	std::vector<int> data = { 1,2,3,4,5,6 };

	for (int i = 0; i < 10; i++)
	{
		next_permutation(data.begin(), data.end());
		PrintVector(data);
	}

	std::cout << "---Prev Permutation---\n";

	for (int i = 0; i < 10; i++)
	{
		prev_permutation(data.begin(), data.end());
		PrintVector(data);
	}

	std::cout << "-------Reverse--------\n";

	for (int i = 0; i < 10; i++)
	{
		std::reverse(data.begin(), data.end());
		PrintVector(data);
	}
}

void NextPermutationStr()
{
	std::string str = "umbrella";
	std::string strCpy = str;
	for (int i = 0; i < str.length(); i++)
	{
		next_permutation(str.begin(), str.end());
		std::cout << str << endl;
	}
}

void PrintStudentArray(Student* sArr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
		std::cout << (*(sArr + i)).getName() << std::endl; // Need to put '*' after parentheses (*sArr).
	// cout << (sArr+i)->getName() << endl;

	std::cout << "----------\n";
}

void PrintVector(std::vector<int> v)
{
	for (int x : v)
	{
		std::cout << x << ", ";
	}
	std::cout << "\n";
}

void RandomShuffle_Algorithm()
{
	std::vector<int> vs = { 1, 2, 3, 4, 5 };

	random_shuffle(vs.begin(), vs.end());

	for (int x : vs)
		cout << x << endl;
}

void RandomGenerate()
{
	std::vector<int> data(10);
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<unsigned int> dist(1, 100);

	generate(data.begin(), data.end(), [&]() {
		return dist(rng);
		}
	);
	PrintVector(data);
}

void Reverse()
{
	std::vector<int> vs = { 1, 2, 3, 4, 5 };

	PrintVector(vs); // Outputs: 1,2,3,4,5
	std::reverse(vs.begin(), vs.end());
	PrintVector(vs); // Outputs: 5,4,3,2,1
	std::cout << "--------------\n";

	std::vector<int> u(5);
	PrintVector(u);
	reverse_copy(vs.begin(), vs.end(), u.begin()); // reverse the reversed.
	PrintVector(vs); // reversed original: 5,4,3,2,1
	PrintVector(u); // Outputs: 1,2,3,4,5
}

void Rotate()
{
	// std::rotate
	// template <typename FwdIt>
	// FwdIt rotate (FwdIt first, FwdIt middle, FwdIt last);
	// Time: O(n): shifts elements between first and last,
	// such that middle element is now first.
	std::vector<int> vs = { 1, 2, 3, 4, 5 };
	PrintVector(vs); // Outputs: 1,2,3,4,5
	rotate(vs.begin(), vs.begin() + 2, vs.end());
	PrintVector(vs); // Outputs: 3,4,5,1,2

	std::vector<int> u(5);
	PrintVector(u); // Outputs: 0,0,0,0
	rotate_copy(vs.begin(), vs.begin() + 2, vs.end(), u.begin());
	PrintVector(u); // Output: 5,1,2,3,4
}

void SetUnion()
{
	std::vector<int> a = { 1, 2, 3, 4, 5 };
	std::vector<int> b = { 1, 2, 3, 6, 7 };
	std::vector<int> c(10); // set union containers DOES NOT guarantee that duplicates won't be added to new container.

	set_union(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	for (int x : c)
		cout << x << endl;
}

void SetIntersection()
{
	std::vector<int> a = { 1, 2, 3, 4, 5 };
	std::vector<int> b = { 1, 2, 3, 6, 7 };
	std::vector<int> c(10); // set union containers DOES NOT guarantee that duplicates won't be added to new container.	

	set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	for (int x : c)
		cout << x << endl;
}

void SetSymmetricDifference()
{
	std::vector<int> a = { 1, 2, 3, 4, 5 };
	std::vector<int> b = { 1, 2, 3, 6, 7 };
	std::vector<int> c(10);

	// returns values NOT in a while in B && NOT in b while in a.  Not intersected values.
	set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), c.begin()); // different values of a, not in b. So, 4,5 but not 6,7 from b.
	for (int x : c)
		cout << x << endl;
}

void SetDifference()
{
	std::vector<int> a = { 1, 2, 3, 4, 5 };
	std::vector<int> b = { 1, 2, 3, 6, 7 };
	std::vector<int> c(10);

	set_difference(a.begin(), a.end(), b.begin(), b.end(), c.begin()); // different values of a, not in b. So, 4,5 but not 6,7 from b.
	for (int x : c)
		cout << x << endl;
}

void Sort()
{
	// TODO: std::sort(map.begin(), map.end());

	// std::sort = IntroSort()
	int arr[5] = { 1, 4, 2, 5, 3 };

	// sort(*begin, *end) // sorts in ascending order by default.
	std::sort(arr, arr + 5); // arr+5 is one past the last element in array arr[5]
	// arr + 5 == arr[5]

	for (int x : arr)
		std::cout << x << std::endl;

	////  VECTOR ////

	std::vector<int> myVec = { 1, 4, 2, 5, 3 };
	//std::sort(myVec.begin(), myVec.end());
	std::sort(begin(myVec), end(myVec)); // sort can be used with any 2 iterators on any DS.

	for (int x : myVec)
		std::cout << x << std::endl;
	cout << "\n";

	// greater, less, less_equal, greater_equal optional function ptr argument.
	std::sort(begin(myVec), end(myVec), greater<int>()); // greater = descending order, large first

	for (int x : myVec)
		std::cout << x << std::endl;
	cout << "\n";

	// Predictor: User-Defined Condition  
	// userDefinedCondition() predictor : condition sorts by first decimal place instead of overall
	std::vector<int> myVec2 = { 11, 44, 27, 52, 33 };
	std::sort(myVec2.begin(), myVec2.end(), UserDefinedCondition); // return a%10 < b%10

	for (int x : myVec2)
		std::cout << x << std::endl;
}

void STL_BinarySearch()
{
	std::vector<int> a = { 1, 2, 3, 4, 5 };

	bool isPresent = binary_search(a.begin(), a.end(), 22);

	std::cout << (isPresent ? "Found" : "Not Found") << std::endl;

}

void Swap()
{

	std::vector<int> a = { 1, 2, 3, 4, 5 };
	std::vector<int> b = { 1, 4, 6, 8, 9 };
	std::vector<int> c(20);

	swap(a, b);

	cout << "------- Printing A (used to vector B) ------- " << endl;
	for (int x : a)
		cout << x << endl;

	cout << "------- Printing B (used to vector A) ------- " << endl;

	for (int x : b)
		cout << x << endl;
}

void Swap_Ranges()
{
	std::vector<int> a = { 1, 2, 3, 4, 5 };
	std::vector<int> b = { 1, 2, 3, 6, 7 };
	std::vector<int> c(10);

	swap_ranges(a.begin(), a.begin() + 3, b.begin() + 2);

	cout << "------- Printing A (used to vector B) ------- " << endl;
	for (int x : a)
		cout << x << endl;

	cout << "------- Printing B (used to vector A) ------- " << endl;

	for (int x : b)
		cout << x << endl;
}

bool UserDefinedCondition(int a, int b)
{
	return (a % 10) < (b % 10); // while %10 of two number is lower, put lowest %10 first.
}

void VectorMinMax()
{
	// max, min, minmax return iterators, need to de-reference
	std::vector<int> myVec = { 1,2,3,4,5 };
	std::cout << "Vector: "; PrintVector(myVec);
	std::cout << "Vector Max: " << *(max(myVec.begin(), myVec.end() - 1)) << std::endl;
	std::cout << "Vector Min: " << *(min(myVec.begin(), myVec.end() - 1)) << std::endl;
	std::cout << "minmax first: " << *(minmax(myVec.begin(), myVec.end() - 1).first) << std::endl;
	std::cout << "minmax second: " << *(minmax(myVec.begin(), myVec.end() - 1).second) << std::endl;
	// minmax return a pair of iterators where first in min and second is max.
}