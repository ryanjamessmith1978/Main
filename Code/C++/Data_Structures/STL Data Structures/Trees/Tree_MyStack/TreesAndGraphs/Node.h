#pragma once

class Node
{

public:

	Node();
	Node(Node* l, Node* r, int v);
	~Node();

	Node* getLeft() const { return left; }
	Node* getRight() const { return right; }	

 	int getValue() const { return value; } 
	int getTreeHeight(Node* n);
	void preOrderTraversal(Node* root);
	void inOrderTraversal(Node* root);
	void postOrderTraversal(Node* root);
	void printValue(int value);

	Node* findNode(Node* root, int value);
	Node findLowestCommonAncestor(Node* root, int value1, int value2);

	Node* heapifyBinaryTree(Node* root);
	int traverse(Node* node, int count, Node* arr[]);

	Node* rotateRight();


private:

	Node*	left;
	Node*	right;
	int		value;

};

