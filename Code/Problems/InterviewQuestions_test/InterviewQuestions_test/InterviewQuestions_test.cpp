// InterviewQuestions_test.cpp 

#include "stdafx.h"
#include "Node.h"
#include <cstring>
#include <string>
#include <list>
#include <unordered_set>
#include <iostream>

using namespace std;

void PrintFizzBuzz();
list<int> RemoveDuplicates(const list<int> in); // Don't understand why you want to pass in const list and why it's passed by reference
void PrintRevisedList(list<int>& in);
string ReverseString(string& initString);
bool CorrectlyNested(string& paren);

int main()
{	
	// PrintFizzBuzz();

	list<int> inList = { 1, 2, 2, 3, 3, 4, 4, 5, 5 };
	inList = RemoveDuplicates(inList);
	PrintRevisedList(inList);	

	// string myString = "EachDay";
	// cout << ReverseString(myString) << endl;

	//string nestings = "( (  (  ) ) ) )";
	//cout << "Is it nested correct? : " << CorrectlyNested(nestings) << endl;

	Node rightChild = Node(nullptr, nullptr, 7);
	Node leftChild = Node(nullptr, nullptr, 3);
	Node rootNode = Node(nullptr, nullptr, 5);

	system("pause");
	return 0;
}

void PrintFizzBuzz()
{
	cout << "The result of FizzBuzz are: " << endl;

	for (int i = 1; i <= 100; ++i)
	{
		bool bIsDivisibleByThree = (i % 3 == 0);
		bool bIsDivisibleByFive = (i % 5 == 0);

		if (bIsDivisibleByThree && bIsDivisibleByFive) { cout << "FizzBuzz"; }
		else if (bIsDivisibleByFive) { cout << "Buzz"; }
		else if (bIsDivisibleByThree) { cout << "Fizz"; }
		else { cout << i; }

		if (i != 100)
			cout << ", ";
		else
			cout << endl << endl;
	}
}

list<int> RemoveDuplicates(const list<int> in)
{
	unordered_set<int> unSet(in.begin(), in.end());
	list<int> out(unSet.begin(), unSet.end());
	return out;
}

void PrintRevisedList(list<int>& in)
{
	cout << "The value of the modified list is: ";
	for (list<int>::iterator it = in.begin(); it != in.end(); ++it)
	{
		if (*it == in.back())
		{
			cout << *it << endl;
			continue;
		}
		cout << *it << ", ";
	}
}

string ReverseString(string& initString)
{
	// char* y = new char[initString.length() + 1];
	string reversedString = "";

	for (int i = initString.length() - 1; i >= 0; --i)
	{
		reversedString += initString.at(i);
	}

	return reversedString;
}

bool CorrectlyNested(string& paren)
{
	int numOfLeftParens = 0;
	int numOfRightParens = 0;

	for (unsigned int i = 0; i < paren.length(); ++i)
	{
		if (paren.at(i) == (char&)("("))
			numOfLeftParens++;

		if (paren.at(i) == (char&)(")"))
			numOfRightParens++;

		if (numOfRightParens > numOfLeftParens) { return false; }
	}

	if (numOfLeftParens != numOfRightParens) { return false; }

	return true;
}