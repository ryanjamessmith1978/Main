// STL_set.cpp | https://www.youtube.com/watch?v=2OEnAdl1eLc
// 
// std::set - associative container that contains a sorted set of unique objects of type, 'key'.
// user-provided Compare() can be supplied for ordering
// search, removal, insertion are logarithmic

// template <class Key, class Compare = std::less<Key>, 
//    class Allocator = std::allocator<Key>> class set;

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

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
        return (this->id < other.id); // ascending order
    }
};

int main()
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
    
    system("pause");
}

// implemented as Red-Black trees, balanced binary search trees, 
//   root black, children: red or black, red nodes cannot have red child nodes
//   all leaves will have same black depth.  black nodes to root, are same number number of levels
//   even if there are red nodes in between. 
// maintains balanced search property.
// black depth is known as closest depth, max depth is the total depth including red nodes.

// insert(Key key) - returns pair consisting of iterator inserted element (or present element), 
//   returns a bool depending on if insertion took place or not.

// insert(iterator pos1, iterator pos2) | great for inserting range of vector elements into a set
// INSERTS ELEMENTS IN RANGE [pos1, pos2)
// returns nothing (void)

// insert(initializer_list l)
// inserts element from initializer list
// returns void

// erase(iterator pos)
// erase(iterator pos1, iterator pos2) | removes elements in range [pos1, pos2)
// erase(key)
