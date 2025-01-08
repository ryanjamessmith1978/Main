// MultiMap.cpp | https://www.youtube.com/watch?v=jOJSdEwldwk
// Syntax: std::multimap<key, value> obj;

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

void MultiMap(std::multimap<char, int>& multimap);
void iterateMultiMap(std::multimap<char, int>& multimap);
void getPairsWithKey(std::multimap<char, int>& multimap, char c);
void countMultiMap(std::multimap<char, int>& multimap);
void findMultiMap(std::multimap<char, int>& multimap);
void upperLowerBoundsMultiMap(std::multimap<char, int>& multimap);

int main()
{
    //std::multimap<char, int> multiMap;
    //MultiMap(multiMap);
    //iterateMultiMap(multiMap);
    //getPairsWithKey(multiMap, 'a');
    //countMultiMap(multiMap);
    //findMultiMap(multiMap);
    //upperLowerBoundsMultiMap(multiMap);
    
   /* std::unordered_multimap<int, char> myUMap;
    myUMap.insert({ 1, 'c' });
    myUMap.insert({ 5, 'd' });
    myUMap.insert(std::pair<int, char>(2, 'b'));
    myUMap.insert(std::make_pair(3, 'c'));
    myUMap.insert(std::make_pair(3, 'c'));
    myUMap.insert(std::pair<int, char>(1, 'b'));
    myUMap.insert(std::pair<int, char>(2, 'a'));
    myUMap.insert({ 1, 'a' });

    for (auto& elem : myUMap)
        std::cout << elem.first << " -> " << elem.second << std::endl;*/


    system("pause");
}

void MultiMap(std::multimap<char, int>& multimap)
{    
    // std::map<char, int> multiMap;
    multimap.insert(std::make_pair('a', 5));
    multimap.insert(std::pair<char, int>('a', 1));
    multimap.insert(std::make_pair('a', 2));
    multimap.insert(std::make_pair('a', 3));
    multimap.insert(std::make_pair('b', 3));
    multimap.insert(std::make_pair('b', 2));
    multimap.insert(std::make_pair('c', 2));
}

void iterateMultiMap(std::multimap<char, int>& multimap)
{
    // Iterate Multimap | .first .second
    for (auto& elm : multimap)
    {
        std::cout << elm.first << " -> " << elm.second << std::endl;
    }
}

void getPairsWithKey(std::multimap<char, int>& multimap, char c)
{
    // Get all the pairs of a given key | equal_range('a') 
    std::pair<std::multimap<char, int>::iterator, std::multimap<char, int>::iterator> // pair of iterators
        range = multimap.equal_range('a'); // auto range = multiMap.equal_range('a'); 

    for (auto it = range.first; it != range.second; it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void countMultiMap(std::multimap<char, int>& multimap)
{
    // COUNT | # of values for the key 'a' | count('a') 
    std::cout << "\n" << "Size of 'a': " << multimap.count('a') << std::endl;
}

void findMultiMap(std::multimap<char, int>& multimap)
{
    //FIND   
    std::multimap<char, int>::iterator it = multimap.find('c'); // doesn't guarantee which value 
    if (it != multimap.end())
        std::cout << "Key Found!" << std::endl;
    else
        std::cout << "Key NOT Found!" << std::endl;
}

void upperLowerBoundsMultiMap(std::multimap<char, int>& multimap)
{
    // LOWER_BOUND
    auto lowerBound = multimap.lower_bound('a'); // first key-value pair with ('a') key added to map.
    std::cout << lowerBound->first << " " << lowerBound->second << std::endl;

    // UPPER_BOUND
    auto upperBound = multimap.upper_bound('a');// last key-value pair + 1 with ('a') key added to map.

    std::cout << upperBound->first << " " << upperBound->second << std::endl;
}


// Multimap Notes:
// Multimap is a container specific to std namespace (included std stl functions) 
// All containers are also considered Data Structures.  Multimap is both a DS and a container.
// Data structures are also custom classes or patterns that use containers to implement collection of data.   
// Red-Black tree are an example of a custom data structure that is commonly used but not a container in the stl itself.
// Red-Black trees are comprised of other containers or stl data structures when implemented.
// Multimap containers are often used in Red-Black tree data structures to employ the R-B tree.

// Multimap is an associative container of sorted key-value pairs.
// Unlike std::maps, multimaps allow the same key to be added multiple times to the container.  
// Multimap are sorted by the key (either in ascending or descending order).
// 
// multimap<char, int, std::less<>> multiMap; Ascending (third param) [default].
// multimap<char, int, std::greater<>> multiMap; Descending (third param)
// 
// Cannot [index] operator or use at() function in Multimap(non-unique keys).  
// 
// QUESTIONS
// How do you add or manipulate values a std::map's key-value pair after value has been assigned to key?

// UNORDERED MULTIMAP NOTES
// Unordered associative container that can have the same key multiple times.
// Search, insert, remove O(1) - average
// Elements organized into buckets.
// Hashing to insert elements into buckets.
// Same as unordered_map but can have multiple elements of the container with the same key.

// Why unordered_multimap?  
// Maintain collection of duplicate {key:value} pairs with fast insertion/removal.
// Benefits of multimap with duplicate keys and unordered map for O(1) lookup, insert, remove.