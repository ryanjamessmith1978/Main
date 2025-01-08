// VectorOptimization.cpp : KNOW YOUR ENVIRONMENT
// // https://youtu.be/PocJ5jXv8No?si=Kce9Co3YTV_1ydOi

// Copy operation occurs: the compiler creates a new block of memory with the old data and a new element
// then the old location in memory where the original vector was is deleted.

// THE Goal is to reduce the number of times we resize our vector.
// In this environment (know your environment) we are strictly dealing with objects, not ptrs.
// Know when copies happen and why they happen?

#include <vector>
#include <iostream>
#include <stdlib.h>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z) {}

    // Add a copy constructor to Vertex to find out how many copies are being created.

    Vertex(const Vertex& vertex)
        : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "Copied!" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) // adds index access to Vertex struct
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

int main()
{
    // vector and Vertex are NOT the same, Vertex struct created up top.
    //std::vector<Vertex> vertices; // not storing Vertex pointers, just storing vertexe objects.
    //vertices.reserve(3); // different from resizing 
    //vertices.push_back({1, 2, 3}); // no constructor but member initializer list works.  
   //vertices.push_back({4, 5, 6}); // 3 copies on second Vertex added
    //vertices.push_back(Vertex(7, 8, 9));  // 6 copies with third Vertex added (if no reserve call).

    std::vector<Vertex> vertices2;
    vertices2.reserve(3);
    vertices2.emplace_back(1, 2, 3);
    vertices2.emplace_back(4, 5, 6);

    // Each time we constuct an object, we are creating the object on the current stack frame in Main()
    // After that we need to put that object into the vector.  Copy from main function into the vector.
    // WHAT IF we could construct that Vertex directly into the actual vector, vertices?

    // Each time the vector adds additional objects, it needs to be resized, which adds a 2nd copy.
    // So, for the 2nd element, copy gets called moving from main to vector, then another when resizing.
    // Resizing each element adds n copies to the previous amount (1...3...6...10....15).. n-1 resizes + main copy

    /*
    // Ranged based or foreach loop, add the '&' ampersand to avoid copying vertices.
    for (Vertex& v : vertices)
        std::cout << v << std::endl;

    // vertices.erase(1); ERROR!  Can't index directly in vector to erase, need to use iterator.
    vertices.erase(vertices.begin() + 1);

    // Empty or clear the vertices
    vertices.clear();
    */

    system("pause");
}

/*
void PassVectorByReference(const std::vector<Vertex>& vertices)
{
    // '&' after vector<datatype> allows the function to pass vector by reference
}
*/