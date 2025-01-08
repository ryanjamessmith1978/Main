#pragma once

#include <iostream>

class Singleton
{
public:
	// DON'T want a constructor, so people can't instantiate it outside of this class.  
	Singleton(const Singleton&) = delete; 

	// provides a way to access this class staticly. 
	// needs to return a reference or a pointer of this particular type. 
	static Singleton& Get()
	{		
		return s_Instance;
	}
	
	float Function() { return m_Member; }

	static float singletonFloat;

private:

	float m_Member = 0.0f;

	// This member and the private constructor, allows this Singleton object/entity to exist.	
	Singleton() {}

	// because it's static, it needs to be defined somewhere where's its being referenced, (the top of a cpp file).
	// static members need to be defined in the file they are being applied to.
	static Singleton s_Instance; // this is NOT a Singleton member variable, because it's static
								// it's a static variable that exists in the Singleton class namespace
								// it's a static variable of Singleton type named s_Instance.
	

	// It is stored in a static variable because its scope has to be the class itself 
	// and not a particular instance

};

// Why doesn't this singleton pattern not require a definition of the statics in Singleton at top?

// STATIC MEMBER VARIABLES:
// If Static Member variables of a class/namespace need to be used outside of that class, they need to be 
// defined (initialization not required), before the code block that needs to use them.
// 
// To define a static member variable, you need their: 
// variable type, Class/NameSpace, scope operator, static variable name.
// float Singleton::singletonFloat;
// It does not matter if the member variable is public or private, if it's a static member variable, 
// it needs to be defined.
// Public Static variables of a namespace(.h included) can be accessed directly with scope operator,
// if defined before code block it's used.  float Singleton::singletonFloat; Singleton::singletonFloat = 0.f;

// STATIC MEMBER FUNCTIONS:
// DO NOT need to be defined above code block they are used in, just need the header file included in file.
// Static member functions (public) can be accessed directly using scope operator.  Singleton::Get();
// Private Static member functions don't need to be defined but are NOT available with scope operator.
// Singleton::Singleton() | Nope Singleton() constructor is a private member function.

// SINGLETONS, non lazy
// In Order to make a proper singleton:
// You need a private static Singleton member variable: m_Instance;
// You need a private Singleton() constructor
// You need a public static function that returns a reference to m_Instance. ::Get()
// 
// MOST IMPORTANTLY, you need to define the m_Instance at the top of the file you are using it in.
// Reason: the only way to use a single instance of a singleton pattern class, is to
// make a private static member variable of the same type and a public static Get() function to get it.
// Because, Get returns that private static member as a reference after being created inside the class,
// that private member variable needs to be defined before it can be accessed.  

/*
static Singleton& Get()
{
	static Singleton _instance;
	return _instance;
	//return s_Instance;
}*/  // Works but breaks Singleton pattern.