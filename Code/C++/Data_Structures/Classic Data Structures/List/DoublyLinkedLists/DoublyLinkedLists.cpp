// DoublyLinkedLists.cpp | https://www.youtube.com/watch?v=-StYr9wILqo&t=325s
// Three parts: value, next* ptr, previous* ptr.

// Advantage to SLL: adding and removing nodes is faster (ability to add before and after a node).
// Disadvantage to Singly Linked Lists (SLL): takes more memory.
// 
// Link List nodes use pointers because Linked Lists are dynamic, 
// thus need pointers to dynamically adjust size.  

#include <iostream>

class Node
{
public:
    int value;
    Node* next;
    Node* previous;
};

void printForward(Node* head)
{
    Node* iterator;
    iterator = head;

    while (iterator != nullptr)
    {
        std::cout << iterator->value << std::endl;
        iterator = iterator->next;
    }
}

void printBackward(Node* tail)
{
    Node* iterator;
    iterator = tail;

    while (iterator != nullptr)
    {
        std::cout << iterator->value << std::endl;
        iterator = iterator->previous;
    }
}

int main()
{
    // **** FIRST NODE (creating doubly linked list) ****
    // 1. Create head and tail nodes, set to nullptr.
    // 2. Create a new Node();
    // 3. Initialize new node ptrs to nullptr.
    // 4. Initialize new node's value to an int value.
    // 5. Set head and tail nodes to initial node.
    Node* head = nullptr;
    Node* tail = nullptr;

    Node* node = new Node();
    (*node).next = nullptr;
    (*node).previous = nullptr;
    (*node).value = 4;
    head = node; 
    tail = node; 

    // Adding 2nd NODE
    // 1. Create new Node()
    // 2. Set new Node() value to 5
    // 3. new Node()->next = nullptr
    // 4. new Node()-> previous = tail
    // 5. tail->next = node
    // 6. tail = node    
    node = new Node();
    node->value = 5;
    (*node).next = nullptr;
    (*node).previous = tail;
    (*tail).next = node;
    tail = node;

    // Adding 3rd NODE  
    node = new Node();
    node->value = 6;
    (*node).next = nullptr;
    (*node).previous = tail;
    (*tail).next = node;
    tail = node;

    // Adding 4th NODE  
    node = new Node();
    node->value = 7;
    (*node).next = nullptr;
    (*node).previous = tail;
    (*tail).next = node;
    tail = node;

    //printForward(head);
    printBackward(tail);

    system("pause");
}

// Questions about Double Ptrs and Singly Linked Lists:
// Wny can't I pass in the head pointer of a linked list into a function and modify it directly?
// Could I do this directly in main without calling a separate function?

// void AddNode(node* head, int value)
// int main()
// Node* head = new Node();
// AddNode(head, 5)

// NEED to keep track of the head of the list, but still be able to navigate, add, and remove elements.  
// Some implementations pass a pointer to pointer parameter to allow changing the head pointer directly 
// instead of returning the new one.

// Reference params vs. Pointer params vs Double pointer params ?? 
// Tab9 to auto fill.
