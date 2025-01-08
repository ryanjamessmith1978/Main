// LinkedList.cpp | https://www.youtube.com/watch?v=RNMIDj62o_o&t=571s 
//
// Linked List is a data structure containing a non-contigous collection of elements
// Linked List elements contain a value and a ptr variable to the next element in the list.
// Last element in the linked list has a null ptr. 
// 
// Linked Lists are better than arrays: No fixed size, dynamic data structure.  
// Linked Lists are worse than arrays: No random access of elements, non-contigous, slow access.
// Linked Lists are worse than arrays: Uses more memory.  Each element also has a ptr.  
// 
// Linked Lists are used when you are frequently adding and removing elements.
// Linked Lists are NOT used when you are frequently accessing elements.  

// Advantage to SLL: adding and removing nodes is faster (ability to add before and after a node).
// Disadvantage to Singly Linked Lists (SLL): takes more memory.
// 
// Link List nodes use pointers because Linked Lists are dynamic, 
// thus need pointers to dynamically adjust size.  

#include<list>

// Node represents one element of a Linked List.
class Node
{
public:
    int value;
    Node* next;
};

// Doubly Linked-List Node, same as LL, but can move backward and forward, take up more memory.
class Double_Node
{
public:
    int value;
    Node* next;
    Node* previous;
};

Node* createNode();

void addNodeFront(Node** head, int val); // How do ptr of ptrs work?
void addNodeBack(Node** head, int val);
void addNodeMiddle(Node* previous, int val);
void printList(Node* n);
void basic_LL_Example();
void creatingAndAddingNodes_Example();

#include <iostream>
#include <string>
#include <list>

int main()
{   
    basic_LL_Example();
    creatingAndAddingNodes_Example();

    // User-defined LL (above) vs an STL List 
    std::list<int> myList;
    std::list<int> myList2{ 1,2,3,4,5 };    
    
    system("pause");
}

Node* createNode()
{
    Node* head = nullptr;
    head = new Node;
    Node* second = new Node();
    Node* third = new Node();

    (*head).value = 1;  // head->value = 1;
    (*second).value = 2; // second->value = 2;
    (*third).value = 3;   // third->value = 3;
    (*head).next = second; // head->next = second;
    (*second).next = third; // second->next = third;
    (*third).next = nullptr; // third->next = nullptr;

    return head;
}

// ADDNODE: Pass Address of the head node variable, which is also a pointer, 
// so, you need a pointer to a pointer, or a double pointer in order to modify the LL outside of main scope.
// Passing in head without a reference address, will only modify local pointer's pointee, which doesn't save after it leaves 
// function scope
void addNodeFront(Node** head, int val)
{
    // Prepare New Node()
    Node* newNode = new Node();
    (*newNode).value = val;

    // Put New Node in front of current Node | put new node in front of current head first.  passing in current head's address to newNode next.
    // De-reference head, which is passed in as a double pointer, so function dereferences a double ptr(**) leaves just a ptr. (head pointer)
    newNode->next = *head;  // newNode's ptr is pointing to current head of Linked List.    

    // Move head of the list to point to the newNode | second, redefine where the head of LL resides, which is new Node's address.  
    *head = newNode;
}

void addNodeBack(Node** head, int val)
{
    // 1. Prepare a new Node
    Node* n = new Node();
    (*n).value = val;
    (*n).next = nullptr;
    
    // 2. If Linked list is empty, the new Node* n will be the head node
    if (*head == nullptr)
    {
        *head = n;
        return;
    }

    // 3. Find the last node (How do I create an iterator for a LL in this case Node**?)
    Node* last = *head; // allows you to navigate list without touching the head of LL.
    while (last->next != nullptr)
    {
        last = last->next;
    }
    // for (std::list<Node*>::iterator it = (*head).begin();

    // 4. Insert new Node after the last node (at the end of the list)
    last->next = n;
}

void addNodeMiddle(Node* previous, int val)
{
    // 1. Check if previous node is NULL
    if (previous == nullptr)
    {
        std::cout << "Previous cannot be NULL\n";
        return;
    }
    
    // 2. Prepare new Node()
    Node* newNode = new Node();
    newNode->value = val;
    // cannot assign ptr at this point.

    // 3. Insert newNode after previous
    newNode->next = previous->next;
    previous->next = newNode;
}

void printList(Node* n)
{
    while (n != nullptr)
    {
        std::cout << n->value << std::endl;
        n = n->next;
    }
}

void basic_LL_Example()
{
    // First node of Linked List.
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;

    printList(head);

}

void creatingAndAddingNodes_Example()
{
    // First node of a Linked List.
    Node* head = createNode();

    addNodeFront(&head, -1);
    addNodeFront(&head, -2);
    addNodeBack(&head, 4);
    addNodeBack(&head, 5);
    addNodeMiddle(head, -1);
    addNodeMiddle(head->next->next, -3);

    printList(head);
}

// Linked List Notes:
// Each element (or Node) of a linked list contains 2 parts: value of element, ptr to next element.
// LLs CAN NOT represent an element value of linked list with a built-in data type.
// LINKED List element values HAVE to be a user-defined data type (struct or class).

// Is there a purpose to pass a pointer by reference?
// You would want to pass a pointer by reference if you have a need to modify the pointer rather than the object that the pointer is pointing to.
// This is similar to why double pointers are used; using a reference to a pointer is slightly safer than using pointers.
// Deleting a ptr and null'n it out in local scope would only affect local pointer, not the one out of scope.
// Linked Lists v Maps?  When you would use a LL over a Map?