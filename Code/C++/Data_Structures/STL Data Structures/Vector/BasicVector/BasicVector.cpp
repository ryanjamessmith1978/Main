// BasicVector.cpp 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVec(std::vector<string>& myVec);
 
int main()
{
	vector<string> strVec;
	vector<string>::iterator it;
	strVec.push_back("Ryan"); // push_back("");
	strVec.push_back("James");
	strVec.push_back("Smith");

	// empty()
	if (!strVec.empty()) 
		printVec(strVec); // Ryan James Smith

	// size() and capacity()
	cout << "\n" << "Current Size: " << strVec.size() << endl; // 3	
	strVec.reserve(10);  cout << "Reserving capacity for 10 elements \n"; // reserve(i)
	cout << "Current Size: " << strVec.size() << endl; // 3
	cout << "Current Capacity: " << strVec.capacity() << endl; // 10

	strVec.pop_back(); // pop_back()
	printVec(strVec); // Ryan James

	strVec.emplace_back("Smith"); // emplace_back("")
	printVec(strVec); // Ryan James Smith
	
	strVec.insert(strVec.begin() + 3, "Tyler"); 
	printVec(strVec); // Ryan James Smith Tyler

	// resize allows indexing, initializes empty strings, reserve does not.
	strVec.resize(10); // strVec.size() now equals 10.
	
	strVec[4] = "Robert"; // strVec[4] was initialized with resize(), can index now.
	printVec(strVec); // Ryan James Smith Tyler Robert
	
	strVec.erase(strVec.begin() + 3, strVec.begin() + 5);
	printVec(strVec); // Ryan James Smith	

	system("pause");	
}

void printVec(std::vector<string>& myVec)
{
	std::vector<std::string>::iterator it;
	it = myVec.begin();

	for (it; it != myVec.end(); it++)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}