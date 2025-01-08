// Unordered_Set.cpp | https://www.youtube.com/watch?v=g5RGA50LGCA
// Associative container which contains a set of unique objects of of type, 'Key'.
// Implemented as a Hash Table.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;

// for custom classes, need to create your own comparator.
class Student {
public:
    int id;
    string name;

    bool operator==(const Student& s) const {
        return  (this->id == s.id && this->name == s.name);
    }

    void print_student() const {
        cout << "id: " << id << ", name: " << name << endl;
    }
};

class StudentHashFunction {
public:
    size_t operator()(const Student& s) const {
        return (hash<int>{}(s.id) + hash<string>{}(s.name) );
    }
};

int main()
{
    //     ### HASHING ###
    size_t h1 = hash<string>{}("Hello");
    size_t h2 = hash<string>{}("World");
    cout << h1 << ", " << h2 << endl;
    cout << hash<int>{}(100) << endl;
    cout << hash<float>{}(100.5) << endl;

    unordered_set<int> us = { 5, 10, 4, 20, 5, 5, 15 };

    for (int x : us)
        cout << x << " "; // prints out in random order
    cout << endl;

    cout << "size: " << us.size() << endl;
    cout << "count of 5: " << us.count(5) << endl;
    cout << "Key 5 erased? " << us.erase(5) << endl;
    cout << boolalpha << "found 16 = " << (us.find(16) != us.end()) << endl;

    //// Load_factor() & Num_Buckets()
    cout << "number of buckets: " << us.bucket_count() << endl;
    cout << "load factor: " << us.load_factor() << endl;

    unordered_set<Student, StudentHashFunction> uss = { {50, "Simon"}, {20, "Thomas"} };

    for (auto& st : uss)
        st.print_student();

    system("pause");
}


/*
    UNORDERED_SET NOTES (#include <unordered_set>, #include <functional>)
    
    Unordered_set template definition:
    template< class Key, class Hash<Key>, class KeyEqual'<Key>, class Allocator<Key>> class unordered_set;
    class Hash = std::hash<Key>  :  default class Hash value | needs #include<functional>
    class KeyEqual' = std::equal_to<Key>  :  default class KeyEqual' value
    class Allocator = std::allocator<Key>  :  default class Allocator value
    Search, removal, and insertion times are constant.

    Standard Set Functions (available in unordered_set):
    size(), =, clear(), count(), find(), empty(), insert(key), insert(it1, it2), 
    insert(initializer_list), erase(it), erase(it1, it2), erase(key)

    Unordered_Set specific HashTable functions:
    bucket_count() - Maps to range 
    load_factor() - on average, each bucket includes how many elements


    * Know the difference of insert(key) for different Set types.
*/
