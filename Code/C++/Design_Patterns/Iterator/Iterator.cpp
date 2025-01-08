// Iterator.cpp | https://www.youtube.com/watch?v=f-icHMaFIp8&list=PLalVdRk2RC6otl3oBU2cn-P6DWi1y1PS3&index=19

#include <iostream>
#include <string>
#include <vector>

// T = type we are iterating through, U = container class
template <typename T, typename U>
class Iterator 
{
public:                                     // it_type = iterator variable name.
    typedef typename std::vector<T>::iterator it_type; // needs to be defined based on these type names. 

    // iterator only holds weak references of things - so it doesn't need to manually delete any data.
    
    Iterator(U* container) : _data_ref(container) { // member initializer to store member container ptr. during construction.
        _it = _data_ref->_data.begin(); // constructor member assignment for the iterator of the member container ptr.
    }

    void First() {
        _it = _data_ref->_data.begin();
    }

    void Next() {
        _it++;
    }

    bool AtEnd() {
        return (_it == _data_ref->_data.end());
    }

    it_type Current() {
        return _it;
    }

private:
    U* _data_ref; // Iterator doesn't need to hold all the data, just the current data that it's at.
    it_type _it; // iterator variable typenamed above as a vector<T> iterator
};

template <typename T>
class Container { // bags or storage class are other names for container class
    
    friend class Iterator<T, Container>; // friend class defined in Container class for the custom iterator class above.
    // As long as you instantiate the iterator custom class, this container class, 
    // the iterator class will be able to access private members of this container.  Only the iterator can access data.

public:
    void Add(T new_data) {
        _data.push_back(new_data);
    }
    // 'this' is a pointer to this container when creating an Iterator of this custom iterator type, the constructor requires a container ptr.
    Iterator<T, Container>* CreateIterator() {
        return new Iterator<T, Container>(this);
    }

    // TODO: Create a proper to destructor for iterator.

private:
    std::vector<T> _data; // data of the container class needs to match iterator parameters.  
};

int main() {

    // iterator pattern shines here because no way to get to normally get data from our container template.
    // other than to create an iterator. The iterator is generic.  All it needs is the right type and the right container.
    // But how the iterator is designed, is totally up to the programmer.
    // Works great because you can create new iterators based on how you want to specifically sort things for example
    // if loads of people online are spamming sort button, instead of trying to use existing iterator, just create a new one.
    Container<int> our_data_bag;
    for (int i = 0; i < 10; i++) {
        our_data_bag.Add(i);
    }
    
    // it's a container of ints and each iterator is also an int.
    Iterator<int, Container<int>>* our_iterator = our_data_bag.CreateIterator();
    // auto* our_iterator = our_data_bag.CreateIterator();

    for (our_iterator->First(); !our_iterator->AtEnd(); our_iterator->Next()) {
        std::cout << *our_iterator->Current() << std::endl;
    }

    system("pause");
}

// iterator : allows you to traverse through a data structure without client knowing type of data structure
// iterator works like an interface to work with any sort of data type.
// Iterators can change the iterator dynamically to allow the iterator to traverse through the data by a different method.
// 
// ### Iterator Pattern ###
// Design custom iterators based on the classes they are going to work around.