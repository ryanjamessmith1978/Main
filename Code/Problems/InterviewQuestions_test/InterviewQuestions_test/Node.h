#pragma once
class Node
{

public:

	Node(Node* left, Node* right, int value);
	
	~Node();

	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	int getValue() { return value; }

private:

	Node* left;
	Node* right;
	int value;

};

