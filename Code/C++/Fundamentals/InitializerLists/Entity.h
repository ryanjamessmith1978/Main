#pragma once
#include <iostream>
#include <string>

class Example
{
public:
	Example() { std::cout << "Created Entity!" << std::endl; }
	Example(int x) { std::cout << "Created Entity with " << x << "!" << std::endl; }
};

class Entity
{
public:

	// *** Assignment Constructors ***
	Entity() // Default constructor
	{
		m_Name = std::string("Unknown"); 
		m_Example = Example(8); // CREATES 2 Example objects, 1 from private member list, and 1 here
		// Private member m_Example will get thrown away, but resources were wasted.
		// Applies to all objects that are being assigned in classic constructor (including strings!)
		m_Score = 0;
	}

	// *** Member Initializer Lists ***
	// Only 1 Example Object, USE THIS
	/*
	Entity() : m_Example(Example(8)) // CAN'T define default constructor ^^ and this list.
	{
		m_Name = std::string("Unknown");
		m_Score = 0;
	}
	*/

	// NOTE: Initializer List must match the member variable declaration order (will still compile)
	// NOTE: In this example, if you put m_Score(0) first, you'll run into data errors.
	// Entity() : m_Name("Ryan"), m_Score(0) {}  
	Entity(const std::string name, Example ex, int score) : m_Name(name), m_Example(ex), m_Score(score) {}
	
	// Get function
	const std::string& GetName() { return m_Name; }
	
private:
	std::string m_Name;
	Example m_Example; // Creates an Entity when running default constructor.
	int m_Score;
};

// Functional difference between assignment Constructors and Member Initializer Lists
// Applies to Classes specifically
// private data members automatically run their default constructors
// UNLESS those members are in an initializer list.
// Does NOT apply to primitive types, but it is best practice to use initializer lists for everything

// Reference members must be initialized using the Initializer List