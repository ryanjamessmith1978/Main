#pragma once
#include <iostream>
#include <string>

template<typename T>
class Vector
{
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

		m_Data[m_Size] = std::move(value); // move is actually a cast, casts an rvalue reference to (value)
		m_Size++;
	}

	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		if (m_Size >= m_Capacity)
		{
			ReAlloc(m_Capacity + m_Capacity / 2);
		}

		new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
		// m_Data[m_Size] = T(std::forward<Args>(args)...);
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
		for(size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();

		m_Size = 0;
	}

	const T& operator[](size_t index) const 
	{		
		return m_Data[index]; 	// add assert for debug mode.
	} 

	T& operator[](size_t index)
	{ 
		return m_Data[index]; // add asserts in full version, checking size
	} 

	size_t Size() const { return m_Size; }

private:
	void ReAlloc(size_t newCapacity) // Don't use smart pointers when you are this low level
	{
		// 1. allocate a new block of memory.
		// 2. copy all existing elements into new block of memory (try to move them).  
		// 3. Delete old block of memory

		T* newBlock = new T[newCapacity];

		// checks to see if we are shrinking Vector
		if(newCapacity < m_Size) // change the size of the vector if size is smaller 
			m_Size = newCapacity;  // *Note: Not typically implemented in the ReAlloc function.

		for (size_t i = 0; i < m_Size; i++) // if check above accounts for shrinking vector.
		{
			newBlock[i] = std::move(m_Data[i]);
		}

		delete [] m_Data;
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

private:
	T* m_Data = nullptr;

	size_t m_Size = 0; // num of elements currently in Vector
	size_t m_Capacity = 0; // num of elements total that could be stored, total memory allocated

};
