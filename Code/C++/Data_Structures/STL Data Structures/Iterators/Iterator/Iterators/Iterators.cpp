// Iterators.cpp : An Iterator is a 'gang of four' behavioral design pattern.  
// https://www.youtube.com/watch?v=SgcHcbQ0RCQ
// 
// Iterators are objects used for iterating over data structures.
// Iterator objects are instantiated from derived iterator classes of a base class template.  
// Iterators function like ptrs to access elements, but are NOT ptrs.  
// Iterator types: Output, Input, Forward, Bidirectional, & Random Access.
// Each container type has its own iterator implementation.
// Depending on implementation, iterators can contain ptr variables

#include <iostream>
#include <vector>
#include <unordered_map>

void IteratorsAndVectors();
void IteratorsAndMaps();

int main()
{
    system("pause");
}

// Basic usage of iterators, not recommended for vectors.  
void IteratorsAndVectors()
{
    std::vector<int> values = { 1, 2, 3, 4, 5 };

    // Standard for loop - indexing a vector
    for (int i = 0; i < values.size(); i++)
    {
         std::cout << values[i] << std::endl;
    }
    
     // Range based for loop for iterating a vector
     for (int value : values)
     {
         std::cout << value << std::endl;
     }

     // vector iterator declaration, iterators are not ptrs, nor implemented as one.
    std::vector<int>::iterator it;

    // vector iterators contain a ptr member.  
    // Iterator assignment operator gets an address that is passed into ptr member variable.    
    it = values.begin(); // vector initialization.

    for (it; it != values.end(); it++) // how to get value at that iterator?
    {
        // How do we get a value at that position?  You have to de-reference it, as if it was a ptr.
        // dereference function implemented inside the vector iterator class
        std::cout << *it << std::endl;
    }

    // Preferred iterator syntax
    for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    // What makes the range based loops work on vectors? .begin() and .end() 
}

void IteratorsAndMaps()
{
    // Need know the keys of the entries to get the values from an unordered map, unless iterator.
    std::unordered_map<std::string, int> map;
    map["Cherno"] = 5;
    map["C++"] = 2;

    for (std::unordered_map<std::string, int>::const_iterator it = map.begin();
        it != map.end(); it++)
    {
        auto& key = it->first;
        auto& value = it->second;

        std::cout << key << " = " << value << std::endl;
    }

    std::cout << "\n";

    // range based for loops still use iterator begin() and end() function in iterator class.
    for (auto kv : map)
    {
        auto& key = kv.first;
        auto& value = kv.second;

        std::cout << key << " = " << value << std::endl;
    }

    std::cout << "\n";

    // C++ 17 range based loop using structural bindings
    for (auto [key, value] : map)
        std::cout << key << " = " << value << std::endl;
}
