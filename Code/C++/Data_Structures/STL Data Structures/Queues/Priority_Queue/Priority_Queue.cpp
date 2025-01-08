// Priority_Queue.cpp : https://www.youtube.com/watch?v=WhIcVlkZ19s
// Container adaptor
// O(1) lookup of largest element
// O(log*n) insertion and extraction.
// Need #include <queue>
// User-provided Compare CAN be supplied to change priority ordering.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{   
    // Greater | Priority_Queue defaults | Descending Order
    priority_queue<int> priority_Q;
    vector<int> myVec = { 8,1,6,4,0,7,2,9 };
    
    // insert elements into priority queue
    for (int x : myVec)
        priority_Q.push(x);

    while (!priority_Q.empty())
    {
        cout << priority_Q.top() << endl;
        priority_Q.pop();
    }

    //Priority Queue | add'l arguments | greater than Compare, Ascending Order
    priority_queue<int, vector<int>, std::greater<int>> priority_Q;
    vector<int> myVec = { 8,1,6,4,0,7,2,9 };
    // insert elements into priority queue
    for (int x : myVec)
        priority_Q.push(x);

    while (!priority_Q.empty())
    {
        cout << priority_Q.top() << endl;
        priority_Q.pop();
    }

    // Lamba for defining custom Compare function(), useful for custom classes.
    auto cmp = [](int a, int b) {
        return a < b;
        };

    priority_queue<int, vector<int>, decltype(cmp)> priority_Q(cmp);
    vector<int> myVec = { 8,1,6,4,0,7,2,9 };
    
    for (int x : myVec)
        priority_Q.push(x);

    while (!priority_Q.empty())
    {
        cout << priority_Q.top() << endl;
        priority_Q.pop();
    }

    system("pause");
}

// User-Provided Compare() function
//
// template <class T, class Container<T>, class Compare> class priority_queue;
// class T - type of data stored in the container.
// class Container is a vector by default, but can be a vector or an array, <T> being type of variable container is holding.
// Compare = std::less<typename Container::value_type> - function for ordering priority (can be user-defined).

// Container
// type of underlying container to use to store the elements
// must satisfy requirements of a sequence container
// iterators must satisfy the requirements of Random Access Iterator (can point to any element, bi-directional, in O(1) ).
// must provide the following functions, front(), push_back(), pop_back()
// std::vector, std::deque.  

// Compare function()
// Compare type providing a strict weak ordering
// Compare param is defined such that, 
// it returns true if it's first argument comes before it's second argument.

// Queue functions
// size(), =, top(), empty(), push(), pop()
// top() will return highest priority.