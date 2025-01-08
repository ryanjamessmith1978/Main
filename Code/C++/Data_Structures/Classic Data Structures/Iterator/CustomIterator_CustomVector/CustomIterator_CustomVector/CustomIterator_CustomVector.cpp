// CustomIterator.cpp // https://www.youtube.com/watch?v=F9eDv-YIOQ0
// An Iterator is a 'gang of four' behavioral design pattern.  
// Iterators are objects used for iterating over data structures.
// 
//  Create Iterator class, define begin and end in custom Vector class, start constructor, adding ValueType to Vector and Vector Iterator class.
//  look up original vector class, look at Valuetype, use using to define Valuetype specifying Vector, 
//  and create PointerType and RefType based off that value type, 
//  finish constructor with PointerType, define a member variable of PointerType, fill out rest of itr functions.
//  Prefix, postfix, == operator, != operator, index operator, dereference operator, -> operator functions. 

// Technically don't need to make a custom iterator class for a vector because you can index into a vector,
// but this iterator concept translates to any data structure.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//  ##### VERTEX STRUCT #####
struct Vertex
{
    float x = 0.0f, y = 0.0f, z = 0.0f;

    Vertex() {}
    Vertex(float scalar) : x(scalar), y(scalar), z(scalar) {}
    Vertex(float x, float y, float z) : x(x), y(y), z(z) {}

    //Vertex(Vertex&& other) {};
    Vertex(const Vertex& other) : x(other.x), y(other.y), z(other.z)
    {
        cout << "Copy\n";
    }

    Vertex (Vertex&& other) noexcept : x(other.x), y(other.y), z(other.z) 
    {
        cout << "Move\n";
    }

    ~Vertex()
    {
        cout << "Destroy\n";
    }

    Vertex& operator=(const Vertex& other)
    {
        cout << "Copy\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vertex& operator=(Vertex&& other) noexcept
    {
        cout << "Move\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};

//  ##### CUSTOM ITERATOR #####
template<typename Vector>
class VectorIterator
{
public:
	// ValueType isn't it's own thing in Iterator class, it's an alias, or a
	// reference to the actual Valuetype variable in the custom Vector DS. 
	// You use the same variable name, Valuetype in iterator and actual Vector class to reference
	// the template primitive variable type that is passed in, T, during construction.    
	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	// needs to take in some kind of ptr.
	VectorIterator(PointerType ptr) : m_Ptr(ptr) {}

	VectorIterator& operator++()
	{
		m_Ptr++;
		return *this; // vector iterator reference.
	}

	VectorIterator operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this); // calls the operator++() above
		return iterator;
	}

	VectorIterator& operator--()
	{
		m_Ptr--;
		return *this; // vector iterator reference.
	}

	VectorIterator operator--(int)
	{
		VectorIterator iterator = *this;
		--(*this); // calls the operator--() directly above
		return iterator;
	}

	ReferenceType operator[](int index)
	{
		return *(m_Ptr + index);
	}

	PointerType operator->()
	{
		return m_Ptr;
	}

	ReferenceType operator*()
	{
		return *m_Ptr;
	}

	bool operator==(const VectorIterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	bool operator!=(const VectorIterator& other) const
	{
		return !(*this == other);
	}

private:
	// PointerType was defined as the ValueType* above 
	PointerType m_Ptr;
};

//  ##### CUSTOM VECTOR CLASS #####
template<typename T>
class Vector
{ 
public:
	// What is a ValueType?  Variable name substitution?  
	// ValueType is a variable that represents the type of primitive variable, T, passed in when creating a Vector data structure.
	
	// Using is an alias that introduces a name that is defined elsewhere into the declarative region where this using-declaration appears.
	// Brings a specific member from the namespace into the current scope.
	 
	using ValueType = T; 
	// aliasing class name to smaller name, Iterator, and adding an iterator to the vector class for use.
	// don't have to use name VectorIterator everywhere throughout out code.
	using Iterator = VectorIterator<Vector<ValueType>>; // Iterator is the type we created in this class.
	// VectorIterator<Vector<ValueType>> Iterator; // why not?

public:
	Vector()
	{ // allocate memory to store 2 elements
		ReAlloc(2);
	}

	~Vector()
	{
		// delete[] m_Data; Problem
	}

	void PushBack(const T& value)
	{
		if (m_Size >= m_Capacity)
		{
			ReAlloc(m_Capacity + m_Capacity / 2);
		}

		m_Data[m_Size] = value;
		m_Size++;
	}

	void PushBack(T&& value) // What does && mean? this is an lvalue
	{
		if (m_Size >= m_Capacity)
		{
			ReAlloc(m_Capacity + m_Capacity / 2);
		}

		m_Data[m_Size] = move(value); // move is actually a cast, casts an rvalue reference to (value)
		m_Size++;
	}

	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		if (m_Size >= m_Capacity)
		{
			ReAlloc(m_Capacity + m_Capacity / 2);
		}

		new(&m_Data[m_Size]) T(forward<Args>(args)...);
		// m_Data[m_Size] = T(forward<Args>(args)...);
		return m_Data[m_Size++];
	}

	void PopBack()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T();
		}
	}

	void Clear()
	{
		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();

		m_Size = 0;
	}

	const T& operator[](size_t index) const
	{
		return m_Data[index];
	}

	T& operator[](size_t index)
	{
		return m_Data[index]; // add asserts in full version, checking size
	}

	size_t Size() const { return m_Size; }

	Iterator begin()
	{
		// Need to take in a vector iterator over this current Vector class, copy the std library for std::vector.
		return Iterator(m_Data);
	}

	Iterator end()
	{
		return Iterator(m_Data + m_Size);
	}

private:
	void ReAlloc(size_t newCapacity) // Don't use smart pointers when you are this low level
	{
		// 1. allocate a new block of memory.
		// 2. copy all existing elements into new block of memory (try to move them).  
		// 3. Delete old block of memory

		T* newBlock = new T[newCapacity];

		// checks to see if we are shrinking Vector
		if (newCapacity < m_Size) // change the size of the vector if size is smaller
			m_Size = newCapacity;  // *Note: Not typically implemented in the ReAlloc function.

		for (size_t i = 0; i < m_Size; i++) // if check above accounts for shrinking vector.
		{
			newBlock[i] = move(m_Data[i]);
		}

		delete[] m_Data;
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

private:
	T* m_Data = nullptr;

	size_t m_Size = 0; // num of elements currently in Vector
	size_t m_Capacity = 0; // num of elements total that could be stored, total memory allocated

};

//  PRINT FUNCTIONS EXTERNAL TO CUSTOM VECTOR CLASS
template<typename T>
void PrintVector(const Vector<T>& vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
    {
        cout << vector[i] << endl;
    }

    cout << "---------------------------\n";
}

template<>
void PrintVector(const Vector<Vertex>& vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
    {
        cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << endl;
    }

    cout << "---------------------------\n";
}

int main()
{
	Vector<int> values;
    values.EmplaceBack(1);
    values.EmplaceBack(2);
    values.EmplaceBack(3);
    values.EmplaceBack(4);
    values.EmplaceBack(5);   
    
    // Not using iterators - index operator defined in our custom "Vector" class. 
    cout << "Std index based operators:\n";
    for (int i = 0; i < values.Size(); i++)
    {
        cout << values[i] << endl;
    }

    // Range-Based
    cout << "\nRange-based for loop:\n";
    for (int value : values) // begin() and end() added to Vector class
    {
        cout << value << endl;
    }

    cout << "\nIterator Implementation:\n";
    for (Vector<int>::Iterator it = values.begin(); it != values.end(); it++)
        cout << *it << endl;

    cout << "\n";
    system("pause");
}
