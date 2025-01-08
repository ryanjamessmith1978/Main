// HashTable.cpp | https://www.youtube.com/watch?v=2_3fR-k-LzI&std::list=PLm0fFUL4gEt9QZ5gGl63ty4qSwrmzVvH_&index=13
//

#include <iostream>
#include <list>
#include <string>


class HashTable  // Hashtable phonebook | Array of Lists[10]
{
private:
    static const int hashGroups = 10; // # of hashed indexes, buckets, or lists.  
    std::list <std::pair<int, std::string>> table[hashGroups]; // each list has 0 or more pairs

public:    
    int hashFunction(int key);

    bool isEmpty() const;
    void insertItem(int key, std::string value);
    void removeItem(int key);
    std::string searchTable(int key);
    void printTable();    
};


void CheckEmpty(HashTable hash)
{
    if (hash.isEmpty())
        std::cout << "Is Empty." << std::endl;
    else
        std::cout << "Not Empty" << std::endl;
}

int main()
{    
    HashTable ht;
    CheckEmpty(ht);

    ht.insertItem(905, "Jim");
    ht.insertItem(201, "Tom");
    ht.insertItem(332, "Bob");
    ht.insertItem(124, "Sally");
    ht.insertItem(107, "Sandy");
    ht.insertItem(929, "Barb");
    ht.insertItem(928, "Rob");
    ht.insertItem(928, "Rick");

    ht.printTable();

    ht.removeItem(332);
    ht.removeItem(100);

    CheckEmpty(ht);
    
	system("pause");
}


bool HashTable::isEmpty() const
{
    int sum = 0;
    for (int i = 0; i < hashGroups; i++)
    {
        sum += table[i].size(); // Check the size of each list, bucket
    }
    if (!sum) // if sum is still 0. return true for empty.
        return true;

    return false;
}

// Since only 10 buckets, we want to return a value between 0-9.
int HashTable::hashFunction(int key)
{
    return key % hashGroups; // Key: 905, in return, this function will spit out 5 (5th index).
}

void HashTable::insertItem(int key, std::string value)
{
    int hashValue = hashFunction(key); // which list index this key-value pair needs to go into.
    std::list<std::pair<int, std::string>>& cell = table[hashValue]; // table at a given index
    // auto& cell = table[hashValue]; 
     
    bool keyExists = false; // Why are we iterating, why not just push? Need to know if key exists.
    for (auto bItr = begin(cell); bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr->second = value;
            std::cout << "Warning: Key exists.  Value replaced." << std::endl;
            break;
        }
    }

    if (!keyExists)
    {
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key)
{
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    
    bool keyExists = false;
    for (auto bItr = begin(cell); bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr = cell.erase(bItr); // reuse old iterator after removing key, value pair.  
            std::cout << "Warning: Item Removed." << std::endl;
            break;
        }
    }

    if (!keyExists)
    {
        std::cout << "Item Not Found" << std::endl;
    }

    return;
}

std::string HashTable::searchTable(int key)
{


    return std::string();
}

void HashTable::printTable()
{
    for (int i = 0; i < hashGroups; i++)
    {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++)
        {
            std::cout << "Key: " << bItr->first << " Value: " << bItr->second << std::endl;
        }
    }
    return;
}

// Hash Table is a 'key' => 'value' lookup. 
// Hash Tables require a HASH FUNCTION
// O(1). Getting and Setting.

// ## Example ## - Store people objects in an array
// key ("std::string") => value[Person object] 
// How do we go from a std::string to an index in an array? Hash function
     // A function that passes in a std::string and returns some integer.
     // Remaps an integer into an index of that array | key -> to hashcode -> array index.
     
// Array that stores data might be much smaller than all potential hash codes.  Kind of like a 2D array
// After re-mapping to array indexes, each index will contain the original "name" std::string key and object value.
// So each index in the remapped array will contain at least one map element {"name", Person()}.  

// Two std::strings could have same hash code, infinite # of std::strings, finite # of hash codes.
// Two std::strings with two different hash codes could wind up with same index.  COLLISION.  
// When COLLISION happens, use CHAINING, store them in a LinkedList.
// Chaining v Open Addressing : 2 ways to deal with COLLISION.

/*
class Hastable
{
    linkedstd::list[] data;

    boolean put(std::string key, Person value)
    {
        int hashcode = getHashCode(key)
        int index = convertToIndex(hashcode)
        linkedstd::list std::list = data[index]
        std::list.insert(key, value);
    }
}
*/


// ###  QUESTIONS  ###
// HashTable v HashMap v std::map v std::unordered_map v std::set?  When, why, how?
// Do you use HashTable and std::unordered_maps together in C++?
// Do you use HashTables with a LL, typically?  
// How are hashtables different in C++ v other languages?
// What is reflection?  How is it used?

// When you don't use linked std::lists as the values in hash table, would it be a single map or multiple maps?
// When you do use a linked std::list as the values in hash table, how does the stl map work there?
// When to use static and when not to use static?
// pairs v maps?
