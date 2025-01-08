// TreeDataStructures.cpp : https://www.youtube.com/watch?v=UHxtjVsOTHc
//
// Tree Data Structures used primarily in sorting and searching algorithms.
// Singular entity (element) of a tree is a NODE.
 
// ROOT Node - The one Top Node of the tree w/o parent.
// LEAF Node - The Bottom Nodes w/o children.
// 
// Child nodes cannot be interconnected!  
// The line between Nodes are edges.

// Binary Tree - Each parent node cannot have more than 2 child nodes. 
// Bindary Search Tree (BST) - Tree with data sorted in a specific way.  Left edge values less than, right value more.
// BST facilitates the search

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