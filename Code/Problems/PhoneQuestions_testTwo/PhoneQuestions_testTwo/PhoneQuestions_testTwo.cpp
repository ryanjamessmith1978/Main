// PhoneQuestions_testTwo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <unordered_set>
#include <list>

void fizzBuzz(int num);
std::string reverseString(std::string str);
std::list<int> removeDuplicates(std::list<int>& inList);
void printList(std::list<int>& inList);
bool isCorrectlyNested(std::string nesting);
bool isCorrectlyNested2(std::string nesting);
int compareToMax(int arr[], int n);
int compareToAll(int arr[], int n);

int main()
{
	//fizzBuzz(100);
	std::cout << reverseString("little") << "\n\n";
	//std::list<int> myList = { 1, 1, 2, 2, 3, 4, 5, 5, 6 }; myList = removeDuplicates(myList); printList(myList);
	//std::cout << "Is this correctly nested? " << isCorrectlyNested2("((())))") << "\n\n";
	int arr[] = { 1, 1, 2, 2, 3, 4, 5, 5, 6 };
	int num = (sizeof(arr) / sizeof(int));
	int numMax = compareToMax(arr, num);
	std::cout << "The max number is the array is: " << numMax << "\n\n";

	system("pause");
    return 0;
}

void fizzBuzz(int num)
{
	for (int i = 1; i <= num; ++i)
	{
		bool bIsFizz = false;
		bool bIsBuzz = false;

		if (i % 5 == 0) { bIsBuzz = true; }
		if (i % 3 == 0) { bIsFizz = true; }

		if (bIsBuzz && bIsFizz) { std::cout << "FizzBuzz, "; }
		else if (bIsBuzz) { std::cout << "Buzz, "; }
		else if (bIsFizz) { std::cout << "Fizz, "; }
		else { std::cout << i << ", "; }
	}

}

std::string reverseString(std::string str)
{
	std::string newString = "";

	for (int i = str.length() - 1; i >= 0; --i)
	{
		char newch = str.at(i);
		newString += newch;
		newString += "aa";
	}

	return newString;
}

std::list<int> removeDuplicates(std::list<int>& inList)
{
	std::unordered_set<int> newSet(inList.begin(), inList.end());
	std::list<int> outList(newSet.begin(), newSet.end());

	return outList;
}

void printList(std::list<int>& inList)
{
	//for (std::list<int>::iterator it = inList.begin(); it != inList.end(); ++it) { std::cout << *it << ", "; }
	for (auto item : inList) { std::cout << item << ", "; }
}

bool isCorrectlyNested(std::string nesting)
{
	int rightParens = 0;
	int leftParens = 0;

	for (auto cha : nesting)
	{
		if (cha == ')') { rightParens++; }
		if (cha == '(') { leftParens++; }

		if (rightParens > leftParens) { return false; }
	}

	if (leftParens == rightParens) { return true; }
	else { return false; }
}

bool isCorrectlyNested2(std::string nesting)
{
	int count = 0;

	for (unsigned int i = 0; i < nesting.length(); ++i)
	{
		if (nesting.at(i) == '(')
			count++;
		else if (nesting.at(i) == ')')
			count--;

		if (count < 0) return false;
	}

	if (count == 0) { return true; }

	return false;
}

int compareToMax(int arr[], int n)
{
	int curMax = 0;
	int i = 0;

	if (n <= 0)	return -1;

	curMax = arr[0];

	for (i = 1; i < n; i++)
	{
		if (arr[i] > curMax)
			curMax = arr[i];
	}

	return curMax;
}

int compareToAll(int arr[], int n)
{
	// int arr[] = { 1, 1, 2, 2, 3, 4, 5, 5, 6 };
	int i, j;
	bool bIsMax = false;

	if (n <= 0) { return -1; }

	for (i = 0; i < n; i++)
	{
		bIsMax = true;
		for (j = 0; j < n; j++)
		{
			if (arr[j] > arr[i])
			{
				bIsMax = false;
				break;
			}
		}
		if (bIsMax) break;
	}

	return arr[i];
}
