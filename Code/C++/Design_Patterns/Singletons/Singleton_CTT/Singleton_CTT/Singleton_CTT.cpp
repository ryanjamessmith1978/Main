// Singleton_CTT.cpp 
// Single copy of your class, or a single instance'd object for a Singleton class. 
// Master Manager, Renderer,

#include "singleton.h"

// Don't get access to Singleton::Get() function until we instantiate Singleton
// Singleton Singleton::m_Instance;
float Singleton::singletonFloat;

int main()
{
    Singleton::singletonFloat = 2.3f;   
    
    // You can hold references to Singleton, holding a reference to it doesn't make it a copy.
    Singleton* singleton = nullptr;    
    singleton = Singleton::GetInstance();
    Singleton::singletonFloat = 2.1f;
    
    Tea mytea("shit Tea", 1, 2, 3);    
    // even when mytea leaves scope, the Singleton will retain a copy of that Tea object.
    // Singleton::GetInstance()->Add(mytea);

    system("pause");
}


