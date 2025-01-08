// Queue.cpp 
//
// https://www.youtube.com/watch?v=jaK4pn1jXTo
// FIFO (First in First Out) : "first come first serve" | people waiting in line.
// Fair data structure

#include <iostream>
#include <queue>

void printQueue(std::queue<int> queue)
{
    while (!queue.empty())
    {
        std::cout << queue.front() << " ";
        queue.pop();
    }
}

int main()
{
    std::queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    std::cout << "Size is: " << myQueue.size() << std::endl;
    std::cout << "First Element is: " << myQueue.front() << std::endl;
    std::cout << "Last Element is: " << myQueue.back() << std::endl;

    std::cout << "My queue: " << std::endl;
    printQueue(myQueue);
    
    system("pause");
}

// When to use a Queue data structure?
// Execute elements of a data structure in exact order they were added,
// but the computer isn't fast enough to keep up.  | e.g  printer queue. | online orders | movie tickets
// How to access / manipulate element in Queue without using pop?  How to access without copying elements in a function.  
