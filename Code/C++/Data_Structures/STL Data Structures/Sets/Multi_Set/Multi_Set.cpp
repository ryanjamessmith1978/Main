// Multi_Set.cpp | https://www.youtube.com/watch?v=iJCnqHrkPq8
// 
// Associative container that contains a sorted set of unique objects of type, 'Key'.
// Multiple elements consisting of the same value can exist more than once.  

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
void STL_Set_example();
void STL_Multi_Set_example();

class Student {
public:

    int id;
    string name;

    void print_Student() const {
        cout << "[ name = " << name << ", id = " << id << "]" << endl;
    }

    // user-defined comparator
    bool operator < (const Student& other) const
    {
        return (this->id < other.id); // ascending order |  return (this->id > other.id); // descending order
    }
};

int main()
{
	// STL_Set_example();
	STL_Multi_Set_example();

    system("pause");
}

void STL_Set_example()
{
	set<int> s = { 10, 20, 5, 10, 15, 20, 4 };
	cout << "Size: " << s.size() << endl;

	s.insert(100);
	s.insert(10);
	cout << "Size: " << s.size() << endl;

	for (auto& element : s)
		cout << element << " ";
	cout << endl;

	//set<int>::iterator it = s.erase(s.find(10));
	//cout << *it << endl;

	int num_erased = s.erase(10);
	cout << "number erased: " << num_erased << endl;

	auto ub = s.upper_bound(15);
	auto lb = s.lower_bound(15);
	cout << "upper bound of 15: " << *ub << endl;
	cout << "lower bound of 15: " << *lb << endl;

	s.insert({ -10, -30, -20 });
	for (auto& element : s)
		cout << element << " ";
	cout << endl;

	vector<int> v = { 10, 20, 15, 5, 4 };
	s.insert(v.begin(), v.end());

	for (auto& element : s)
		cout << element << " ";
	cout << endl;

	set<Student> stdSet = { {50, "Simon"}, {20, "Thomas"} };
	for (auto& st : stdSet)
		st.print_Student();
}

void STL_Multi_Set_example()
{
	multiset<int> s = { 10, 20, 5, 10, 15, 20, 4 };
	cout << "Size: " << s.size() << endl;

	s.insert(100);
	s.insert(10);
	cout << "Size: " << s.size() << endl;

	for (auto& element : s)
		cout << element << " ";
	cout << endl;

	//set<int>::iterator it = s.erase(s.find(10));
	//cout << *it << endl;

	int num_erased = s.erase(10);
	cout << "number erased: " << num_erased << endl;

	auto ub = s.upper_bound(15);
	auto lb = s.lower_bound(15);
	cout << "upper bound of 15: " << *ub << endl;
	cout << "lower bound of 15: " << *lb << endl;

	s.insert({ -10, -30, -20 });
	for (auto& element : s)
		cout << element << " ";
	cout << endl;

	vector<int> v = { 10, 20, 15, 5, 4 };
	s.insert(v.begin(), v.end());

	for (auto& element : s)
		cout << element << " ";
	cout << endl;

	multiset<Student> stdSet = { {50, "Simon"}, {20, "Thomas"}, {50, "Simon_jr"} };
	for (auto& st : stdSet)
		st.print_Student();
}


/*
	MULTISET NOTES:
	#include <set>
	User-Provided Compare() can be supplied to change ordering (sorting).
	Search, removal, and insertion are logarithmic time. O(log*n)
	Implemented as Red-Black trees
	Definiton template: template<class Key, class Compare<Key>, class Allocator<Key>> class multiset.
	Compare default = std::less<Key>
	Allocator default = std::allocator<Key>
	size(), =, clear(), count(), find(), empty(), insert(key), insert(it1, it2), insert(initializer_list),
		erase(it), erase(it1, it2), erase(key), upper_bound(key), lower_bound(key)

	insert(key) - inserts key (if already present, inserts at upper_bound and RETURNS iterator to inserted element)
	insert(it1, it2) - inserts element in range [it1, it2) of a vector or other linearly ordered container.
	insert(initializer_list) - insert( {1,2,3} ).
	erase(key) - removes all element with key provided.
	erase(iterator pos) - removes element at position pos
	erase(iterator pos1, iterator pos2) - removes all element in range [pos1, pos2) - pos2 is up to but not including
	bool contains(key) - C++v20 - returns true or false if key exists in multiset.

*/