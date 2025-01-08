#pragma once

#include<iostream>
#include<string>

template<typename T, size_t S>
class Array
{
public:

	constexpr size_t Size() { return S; }

	// index into array
	T& operator[](size_t index) { return m_Data[index]; }

	const T& operator[](size_t index) const { return m_Data[index]; }

	T* Data() { return m_Data; }
	const T* Data() const { return m_Data; }

private:
	T m_Data[S];

};

