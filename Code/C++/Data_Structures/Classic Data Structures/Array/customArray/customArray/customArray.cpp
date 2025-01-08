// customArray.cpp : https://www.youtube.com/watch?v=TzB5ZeKQIHM
// Stack Allocated custom array class - not dynamic
// STD::array class uses a template.

#include <iostream>
#include <string>
using namespace std;

//template<size_t S> | cArray<5> data;
template<typename T, size_t S>
class cArray
{
public:
	// no storage for the size, no additional storage optimization
	// adding constexpr means this function can be evaluated at compile time.
	// Generally better to use size_t instead of ints for Array types
	constexpr int Size() const { return S; }

	// Simple index operator overload:
	// T operator[](int index) { return m_Data[index]; }
	
	// Passes by value - makes a copy - inefficient
	// Also, because it makes a copy, and returns by value, you can't use assignment:
	//   - data[i] = 2 won't compile;  data[i] isn't modifiable lvalue
	//   - returning a brand new copy, nothing to assign to, no storage.

	// implement the index operator to return specific array elements.	
	// by returning by reference, we can assign into that index.
	T& operator[](int index) { return m_Data[index]; } //read-only reference.

	// adding this 2nd overloaded operator function,
	// we can use this custom array class as a const array, allowing class
	// to read data and not write it.  First operator func doesn't
	// return a const value, thus using first operator function won't read from 
	// const array using this customArray class.
	const T& operator[](int index) const { return m_Data[index]; }

	// this allows you to use memset to set all elements to a value.
	T* Data() { return m_Data; }
	const T* Data() const { return m_Data; }


private:
	T m_Data[S];
};

int main()
{
    cArray<int, 5> data{};
    memset(data.Data(), 0, data.Size() * sizeof(int));

    data[0] = 3;
    data[1] = 6;

    cout << "Custom Array Size: " << data.Size() << endl;
    
    // Size needs to have the constexpr keyword added to return 
    // to have 'static_assert' be able to be evaluated at compile time.
    static_assert(data.Size() < 10, "Size is too large!");

    // since Size() is a constexpr, it can be evaluated at compile time.
    cArray<string, data.Size()> newArray;

    for (int i = 0; i < data.Size(); i++)
    {
        cout << data[i] << endl;
    }

    system("pause");
}