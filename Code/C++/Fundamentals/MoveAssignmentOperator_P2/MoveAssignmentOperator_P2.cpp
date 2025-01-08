// MoveAssignmentOperator_P2.cpp : 
// Upgrade from Move Semantics - CUSTOM String class - adding Move Assignment Operators
// Rule of 5th's 

#include <iostream>

class String
{
public:
    String() = default;

    String(const char* string)
    {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    // Copy constructor    
    String(const String& other) 
    {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size]; 
        memcpy(m_Data, other.m_Data, m_Size);
    }

    // Move constuctor with an rvalue reference (temporary)
    String(String&& other) noexcept
    {
        printf("Moved!\n");
        m_Size = other.m_Size;        
        m_Data = other.m_Data; 

        other.m_Size = 0;
        other.m_Data = nullptr; 
    }

    // Not actually creating a new object here.
    // We are moving an existing object into ourselves (this current object).
    // Need to overwrite current object, current object might have some memory already allocated.
    String& operator=(String&& other) noexcept
    {
        printf("Moved!\n");

        if (this != &other)
        {
            delete[] m_Data; // Needs this added or will create a memory leak.

            m_Size = other.m_Size;
            m_Data = other.m_Data; // creates a memory leak because no way to delete old data.

            other.m_Size = 0;
            other.m_Data = nullptr;
        }

        return *this;        
    }

    ~String()
    {
        printf("Destroyed!\n"); 
        delete m_Data;
    }

    void Print()
    {
        for (uint32_t i = 0; i < m_Size; i++)
        {
            printf("%c", m_Data[i]);
        }

        printf("\n");
    }

private:
    char* m_Data;
    uint32_t m_Size;
};

class Entity // Entity class a dummy class to demonstate absorbing a string.
{
public:
    Entity(const String& name) : m_Name(name) {}
    
    Entity(String&& name) : m_Name(std::move(name)) {}    

    void PrintName()
    {
        m_Name.Print();
    }

private:
    String m_Name;
};

int main()
{   
    /*
    String string = "Hello";
    String dest = string;  // Hard copies string into destination (copied by value).  

    // How to move 'string' into 'dest' without hard copying it?
    // * Make string into a temporary variable | String move constructor takes an rvalue.  Need to use move constructor.
    String str = "Hello";
    String des = (String&&)str; // cast str with a String&& rvalue to force the String class move constuctor to be called.
    String des2( std::move(str) ); // std::move is the same as casting an rvalue reference, forces move constructor.

    // Assignment operator only gets called when we assign a variable to an existing variable.
    // If different objects but the data is the same, you still need to do the move
    */

    String apple = "Apple";
    String dest;

    std::cout << "Apple: ";
    apple.Print();
    std::cout << "Dest: ";
    dest.Print();

    dest = std::move(apple); // assignment operator.
    // dest.operator=(std::move(apple)); // assignment operator.
    // String dest = std::move(apple); // move constructor.

    std::cout << "Apple: ";
    apple.Print();
    std::cout << "Dest: ";
    dest.Print();



    system("pause");
}

