// STL_list.cpp : list container as part of the Standard Template Library
// https://www.youtube.com/watch?v=je7zlYfJf7Q&t=7s 
// Sequence container, optimized for rapid insert and remove
// Non-contiguous, doesn't support random-access.

#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

void printList(list<int>& myList);

int main()
{
    list<int> num;
    list<int> nums = { 1,2,3,4,5 }; // C++11 - initializer list    
    list<int> nums2 = nums;

    printList(nums);
    cout << "Size: " << nums.size() << endl;
    
    // .front(), .back(), // .begin(), .rbegin() 
    cout << "front: " << nums.front() << ", back: " << nums.back() << endl;
    cout << "front: " << *nums.begin() << ", back: " << *nums.rbegin() << endl;

    // Inserting into a Vector v List.
    vector<int> vec = { 1,2,3,4,5 };
    vec.insert(vec.begin() + 2, 100); 
    // nums.insert(nums.begin() + 2, 100); // ERROR! list non-contigous, no ptr arithmetic.
    cout << "Vector element 3: " << vec[2] << endl;

    // INSERTING in a LIST     
    // Example: Insert based on value of list element, 
    // find the node that has the value of 3, and insert 100 before that
    list<int>::iterator it = nums.begin();
    while (*it != 3 && it != nums.end()) 
        it++; // keep iterating until the list element value is 3. // 3 is at element 3. 
    
    // Insert() - Needs a memory address - iterator address still points to previous 3rd element.
    nums.insert(it, 100);
    printList(nums);
    nums.erase(it); // iterator address is still tied to value of 3, not 3rd element.
    printList(nums);

    nums.remove(4); // removes by value
    printList(nums);

    nums.clear();
    cout << "Is NumsList cleared afer running nums.clear()? " << std::boolalpha << nums.empty() << endl;
    printList(nums2);

    nums2.push_back(6);
    nums2.push_front(0);
    printList(nums2);

    nums2.pop_back();
    nums2.pop_front();
    printList(nums2);

    system("pause");
}

// size(), =, front(), back(), empty(), begin(), end(), rbegin(), rend(),
// insert(), erase(), remove(), clear(), push_back(), push_front(), 
// pop_back(), pop_front()
// If you want to insert into a LIST by position, you need to keep a separate counter variable



void printList(list<int>& myList)
{    
    list<int>::iterator it = myList.begin();

    for (it; it != myList.end(); it++)
        cout << *it << " ";  

    // for (auto& i : myList) // for each loop works as well.
    //    cout << i << " ";

    cout << "\n";
}
