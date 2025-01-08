#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "tea.h"

// Singleton has it's own instance to be controlled by itself
// Single point of access to a manager class, no one else can make additional managers
// Singleton can very carefully control an inventory, the only way to add/remove is 
// through this single manager instance, that call these specific functions.
// Making this static allows outside classes to get access to it, 
// without needing to instantiate the Singleton externally.

class Singleton // When declaring a class, there are no '()' after the name, just '{}' brackets!!!
{
public:
	
	static float singletonFloat;	
		
	// A static member function is independent of any object of the class.
	// A static member function can be called even if no objects of the class exist.
	// A static member function can also be accessed using the class name through 
	// the scope resolution operator.
	static Singleton* GetInstance() // 'Lazy' Initialization
	{
		// static makes it so, the Singleton instance isn't recreated everytime Init is called.
		static Singleton* instance = nullptr;
		if (!instance)
			instance = new Singleton();

		return instance; // you could look at the memory and change the memory
	}	

	void Add(Tea tea) 
	{
		teas.push_back(tea);
	}

	void RemoveTea(Tea tea) 
	{
		std::vector<Tea>::iterator it = teas.begin();

		for (it; it < teas.end(); it++)
		{
			if (tea.strength == 2)
			{
				teas.erase(it);
			}
		}
	}

private:
	
	Singleton() {}	

	std::vector<Tea> teas;	
};