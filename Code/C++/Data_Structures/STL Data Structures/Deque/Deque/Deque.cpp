// Deque.cpp : 
// Sequence container that supports push/pop from both ends.
// Supports random access d[2] - indexing
// Non-contiguous
// implemented as a sequence of indivudally allocated fixed-size arrays w/ add'l bookkeeping.
// when size of deque is filled, a new fixed array is created and 
// a pointer connects from last element in queue to first element in new fixed array

#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int>& d)
{
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    deque<int> numDeque = { 1,2,3,4,5 };
    cout << "Size: " << numDeque.size() << endl;

    cout << "Third element: " << numDeque[2] << endl;
    cout << "Front element: " << numDeque.front() << endl;
    cout << "Last element: " << numDeque.back() << endl;
    printDeque(numDeque);

    /*for (deque<int>::reverse_iterator it = numDeque.rbegin(); it != numDeque.rend(); it++)
        cout << *it << " ";
    cout << endl;*/    

    numDeque.push_back(6);
    numDeque.push_back(7);
    numDeque.push_front(0);
    numDeque.push_front(-1);    
    printDeque(numDeque);
    
    numDeque.pop_back();
    numDeque.pop_front();
    printDeque(numDeque);

    numDeque.clear();

    system("pause");
}

