// PhoneQuestionTests.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <string>
#include <list>
#include <unordered_set>
#include <iostream>

using namespace std;

void FizzBuzz();
string ReverseString(string str);
std::list<int> RemoveDuplicates1(std::list<int>& originalNumList);
std::list<int> RemoveDuplicates2(std::list<int>& originalNumList);
void PrintList(std::list<int> printList);
bool NestedParentheses(std::string nestedStr);
int DivisibleByThreeAndSevenNotFour();
int DivisibleByFourAndSevenNotThree();

int main()
{
	//FizzBuzz();
	//ReverseString("norm");
	//std::list<int> numList = { 1, 2, 3, 3, 3, 4 };
	//numList = RemoveDuplicates2(numList);
	//NestedParentheses("((()()))");

	DivisibleByThreeAndSevenNotFour();

	return 0;
}

void FizzBuzz()
{
	for (int i = 1; i <= 100; ++i)
	{
		bool bIsFizz = (i % 3 == 0);
		bool bIsBuzz = (i % 5 == 0);

		if (bIsFizz && bIsBuzz) { std::cout << "FizzBuzz"; }
		else if (bIsBuzz) { std::cout << "Buzz"; }
		else if (bIsFizz) { std::cout << "Fizz"; }
		else
			std::cout << i;

		if (i != 100)
			std::cout << ", ";
	}

	std::cout << std::endl << std::endl;
}

string ReverseString(string str)
{
	string newStr = "";

	for (int i = str.length() - 1; i >= 0; --i)
	{
		//newStr += str[i];
		//newStr += str.at(i);
		newStr.append(1, str[i]);
		//newStr.append(1, str.at(i));
	}

	std::cout << "The new string reversed is: " << newStr << std::endl << std::endl;

	return newStr;
}

std::list<int> RemoveDuplicates1(std::list<int>& originalNumList)
{
	std::list<int> out;

	for (auto inval : originalNumList)
	{
		bool found = false;

		for (auto outval : out)
		{
			if (inval == outval)
			{
				found = true;
				break;
			}
		}

		if (!found) { out.push_back(inval); }
	}
	
	PrintList(out);
	return out;
}

std::list<int> RemoveDuplicates2(std::list<int>& originalNumList)
{
	std::unordered_set<int> newSet(originalNumList.begin(), originalNumList.end());
	std::list<int> newList(newSet.begin(), newSet.end());
	PrintList(newList);
	return newList;
}

void PrintList(std::list<int> printList)
{
	for (auto item : printList)
	{
		std::cout << item << ", ";
	}
}

bool NestedParentheses(std::string nestedStr)
{
	bool bIsNestedProperly = false;
	int leftParenCount = 0;
	int rightParenCount = 0;
	// count the number of left and right parentheses, make sure they match
	for (int i = 0; i < nestedStr.length(); ++i)
	{
		char ch = nestedStr.at(i);
		if (ch == '(')
			leftParenCount++;
		else if (ch == ')')
			rightParenCount++;

		if (rightParenCount > leftParenCount) { bIsNestedProperly = false; return bIsNestedProperly; }
	}

	if (rightParenCount == leftParenCount)
		bIsNestedProperly = true;
	else
		bIsNestedProperly = false;

	std::cout << "The Nested Parentheses are nested properly? " << bIsNestedProperly << std::endl;

	return bIsNestedProperly;
}

int DivisibleByThreeAndSevenNotFour()
{
	int numDivisibleByThreeAndSevenNotFour = 0;
	int numDivisibleByFourandSevenNotThree = 0;
	
	for (int i = 1; i <= 100000; ++i)
	{
		bool bDivisByThree = false;
		bool bDivisByFour = false;
		bool bDivisBySeven = false;

		if (i % 3 == 0) { bDivisByThree = true; }
		if (i % 4 == 0) { bDivisByFour = true; }
		if (i % 7 == 0) { bDivisBySeven = true; }

		if (bDivisByThree && bDivisBySeven && !bDivisByFour)
			numDivisibleByThreeAndSevenNotFour++;

		if (bDivisByFour && bDivisBySeven && !bDivisByThree)
			numDivisibleByFourandSevenNotThree++;
	}

	if (numDivisibleByThreeAndSevenNotFour > numDivisibleByFourandSevenNotThree)
		std::cout << "The numbers divisible by 3 and 7 and not 4 is greater than numbers divisible by 4 and 7 and not 3. Number: " << numDivisibleByThreeAndSevenNotFour << " > " << numDivisibleByFourandSevenNotThree << "\n";
	else if (numDivisibleByFourandSevenNotThree > numDivisibleByThreeAndSevenNotFour)
		std::cout << "The numbers divisible by 4 and 7 and not 3 is greater than numbers divisible by 3 and 7 and not 4. \n";
	else
		std::cout << "They are equal \n";

	return numDivisibleByThreeAndSevenNotFour;
}

int DivisibleByFourAndSevenNotThree()
{

	return 0;
}