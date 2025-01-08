// Singleton_Pattern.cpp | https://www.youtube.com/watch?v=PPup1yeU45I
//

#include <iostream>
#include "Singleton.cpp"
#include "RandomNumber.cpp"
//#include "tea.h"

// s_Instance is static, therefor, it needs to be defined somewhere where it's been used.
//  v Singleton is the type of variable being defined!  
//            v this second Singleton is the namespace in which the s_Instance static variable exists.
// this defines the static variable s_Instance of a Singleton type that is part of the Singleton namespace.

Singleton Singleton::s_Instance; // if we want to access static variable in a namespace, we need to tell the class using it, what type it is and what the namespace scope it's from.
// s_Instance is static private in the Singleton:: scope and it's of type Singleton.  The type itself forces the Singleton class to call it's default constructor.
// In calling the default Singleton constructor, all the member variable get initialized, which constructs the an instance of the singleton and assigns it to s_Instance.
// s_Instance is private, thus, not available, but Get() is public and is available to use
// Now that s_Instance has been defined as a static member of type Singleton in the Singleton namespace, any public members or functions part of the Singleton namespace are also available.

float Singleton::singletonFloat; // public variable defined in singleton namespace.

//Tea Tea::m_Tea; // even though m_Tea is a private static member that already exists in tea.h, 
// defining it in this file, declares/initializes the static member type automatically (as a global type variable).
// And, because m_Tea is a class type variable (not a ptr), initializing m_Tea means a constructor needs to be called for it
// to be a valid object in memory.  
// Doesn't matter if this is private or public, or the constructor is private or public.  
// Making a static member variable of a class type available in another file, means it's constructor is called to make it an object.   


int main()
{
    // this function call returns s_Instance, which is why it needs to be defined up top.
    // allowing this local reference of s_Instance to be used indirectly as a static Singleton.  
    Singleton& instance = Singleton::Get();
    
    Singleton::singletonFloat = 3.f;
    //instance.Function();
       

    system("pause");
}

// SINGLETONS
// Single instance of a class.  A single set of data.  Don't need multiple instances.  
// Singletons are a way to organize a set of global variables and static functions.
// Static functionality.
// 
// WHEN to use Singleton?  
// When we have functionality we want to use for a global set of data.
// 
// Example: Random_Number_Generator() class{};
// Example2: Renderer() class{}; 
// 
// Singletons can be used as NAMESPACES.
// In C++, Singletons do not need to be classes, they can be namespaces.  
// In C++ (unlike Java), files do NOT need to be class files, 
// C++ files can be just headers(.h) or source(.cpp) files with a set of data and/or functions not bound to a class.
// 
// Wny do I need a class to make a Singleton? 
// You don't. Singletons aren't classes, they are patterns.
// Singletons can be implemented as classes or 
// Singletons can just be a .cpp or .h files with static functions and data global to all other classes who can see it.

