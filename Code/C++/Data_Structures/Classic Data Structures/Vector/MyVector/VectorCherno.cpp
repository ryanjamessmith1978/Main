// VectorCherno.cpp : Custom Vector class
//

#include <iostream>
#include "Array.h"
#include "Vector.h"

using namespace std;


struct Vector3
{
    float x = 0.0f, y = 0.0f, z = 0.0f;

    Vector3() {}
    Vector3(float scalar) : x(scalar), y(scalar), z(scalar) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    //Vector3(Vector3&& other) {};
    Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Copy\n";
    }

    Vector3(Vector3&& other) : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Move\n";
    }

    ~Vector3()
    {
        std::cout << "Destroy\n";
    }

    Vector3& operator=(const Vector3& other)
    {
        std::cout << "Copy\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vector3& operator=(Vector3&& other)
    {
        std::cout << "Move\n";
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;    
    }
};

template<typename T>
void PrintVector(const Vector<T>& vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
    {
        std::cout << vector[i] << std::endl;
    }

    std::cout << "---------------------------\n";
}

template<>
void PrintVector(const Vector<Vector3>& vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
    {
        std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
    }

    std::cout << "---------------------------\n";
}

int main()
{        
    /*Vector<std::string> vector;
    vector.PushBack("Cherno");
    vector.PushBack("C++");
    vector.PushBack("Vector");   
    PrintVector(vector);*/  
    
    Vector<Vector3> vector;   
    vector.PushBack(Vector3(1.0f));
    vector.PushBack(Vector3(2, 3, 4));
    vector.PushBack(Vector3());
    vector.PushBack(Vector3());
    vector.PopBack();
    PrintVector(vector);

    /*Vector<Vector3> vector;
    vector.EmplaceBack(Vector3(1.0f));
    vector.EmplaceBack(Vector3(2, 3, 4));
    vector.EmplaceBack(Vector3());
    PrintVector(vector);*/


    system("pause");
}