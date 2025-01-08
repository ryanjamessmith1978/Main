#include "stdafx.h"
#include "Node.h"


Node::Node(Node* left, Node* right, int value)
{
	this->left = left;
	this->right = right;
	value = value;
}

Node::~Node()
= default;
