// MoveSemantics.cpp : Using std::move and move operator with custom String class
// 
// std::move | Move one object into another.
// Move assignment operator.  An operator that is used to move an object into an existing objectl

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
    // Need this to copy String to Entity class's m_Name String.
    String(const String& other) // will still be called if std::move cast isn't added to the move constructor in Entity class.
    {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size]; // To copy a string we need to allocate memory on the heap
        memcpy(m_Data, other.m_Data, m_Size);
    }

    // Move constuctor with an rvalue reference (temporary), need entity to also have move constructor.
    String(String&& other) noexcept
    {
        printf("Moved!\n");
        m_Size = other.m_Size; 
        // Instead of allocating a new buffer to copy, we are assigning the ptr.
        // Taking the ptr to m_Data (existing buffer from original string), pointing to same block of data as old string
        m_Data = other.m_Data; // shallow copy by re-wiring old string.
        
        // 2 string instances because you are stealing data from m_Data
        other.m_Size = 0;
        other.m_Data = nullptr; // hollow object in an empty state
    }

    ~String()
    {
        printf("Destroyed!\n"); // Temporary destroyed in example below.
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
    Entity(const String& name) : m_Name(name) {} // m_Name(name) needs a copy constuctor in String to use String.

    // Above constructor will still be called unless std::move is added as a cast
    // Instead of allocating in main and allocating in this class (above), move string directly with rvalue reference.
    Entity(String&& name) : m_Name(std::move(name)) {} // adding rvalue ref param isn't enough, need std::move cast.    

    void PrintName()
    {
        m_Name.Print();
    }

private:
    String m_Name;
};

int main()
{
    // Construct1: Creating entity in main, 
    // Running Entity constructor in Entity class, copies name string into member variable. *If move constructor didn't exist*
    Entity entity("Cherno"); 
    entity.PrintName();

    system("pause");
}
