// TreeDataStructures.cpp : https://www.youtube.com/watch?v=UHxtjVsOTHc
// Tree is a hierarchial data structure which stores the information in form of hierarchy.
// Tree is a non-linear data structures, unlike arrays, LLs, stacks, and queues.
// Tree is a series of nodes connected by edges (lines between nodes).
// Tree Data Structures used primarily in sorting and searching algorithms.
// Singular entity (element) of a tree is a NODE.
 
// ROOT Node - The one Top Node of the tree w/o parent.
// LEAF Node - The Bottom Nodes w/o children.
// Child nodes cannot be interconnected!  

// Binary Tree - Each parent node cannot have more than 2 child nodes. 
// Binary Search Tree (BST) - is a type of binary tree where 
// left child is less than the parent's node and right child is greater.
// AVL Trees
// Red-Black Trees
// Heaps

// Advantages:
// Reflects structural relationships in the data
// Represents hiearchies
// Efficient insertion and searching
// Flexibility.  Subtrees can be moved at minimum performance cost.

#include <iostream>

// 1. Data 
// 2. Left child ptr
// 3. Right child ptr
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Create new node and populate members.  Return reference to Node added.
Node* createNode(int data)
{
    Node* newNode = new Node();
    (*newNode).data = data;
    (*newNode).left = nullptr;
    (*newNode).right = nullptr;
    return newNode;
}

int main()
{
    Node* rootNode = createNode(1);
    (*rootNode).left = createNode(2);    
    (*rootNode).left->left = createNode(4);
    (*rootNode).left->right = createNode(5);
    (*rootNode).left->right->left = createNode(9);

    (*rootNode).right = createNode(3);
    (*(*rootNode).right).right = createNode(7); // rootNode->right->right = createNode(7);
    (*(*rootNode).right).left = createNode(6); // rootNode->right->left = createNode(6);
    (*(*(*rootNode).right).right).left = createNode(15); // rootNode->right->right->left = createNode(15);

    system("pause");
}