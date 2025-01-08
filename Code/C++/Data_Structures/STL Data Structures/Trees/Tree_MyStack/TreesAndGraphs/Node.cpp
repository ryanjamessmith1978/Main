#include "stdafx.h"
#include "Node.h"
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

Node::Node()
{
	left = nullptr;
	right = nullptr;
	value = 0;
}

Node::Node(Node* l, Node* r, int v)
{
	left = l;
	right = r;
	value = v;
}

int Node::getTreeHeight(Node* n)
{
	if (n == nullptr) { return 0; }

	return 1 + std::max(getTreeHeight(n->getLeft()), getTreeHeight(n->getRight()));
}

void Node::preOrderTraversal(Node* root)
{
	if (root == nullptr) { return; }
	root->printValue(root->value);
	preOrderTraversal(root->getLeft());
	preOrderTraversal(root->getRight());	
}

void Node::inOrderTraversal(Node* root)
{
	if (root == nullptr) { return; }
	inOrderTraversal(root->getLeft());
	root->printValue(root->value);
	inOrderTraversal(root->getRight());
}

void Node::postOrderTraversal(Node* root)
{
	if (root == nullptr) { return; }
	postOrderTraversal(root->getLeft());
	postOrderTraversal(root->getRight());
	root->printValue(root->value);
}

void Node::printValue(int value)
{
	std::cout << value << ", ";
}

Node* Node::findNode(Node* root, int value)
{
	while (root)
	{
		int curVal = root->getValue();
		if (curVal == value) break;
		if (curVal < value) { root = root->getRight(); }
		else { root = root->getLeft(); }
	}

	return root;
}

Node Node::findLowestCommonAncestor(Node* root, int value1, int value2)
{
	// make a list of parent nodes for value 1 from youngest to oldest
	// make a list of parent nodes for value 2
	// compare from beginning of list to end, first one is the lowest
	std::stack<Node> valueOneNodes;
	std::stack<Node> valueTwoNodes;
	Node* root1 = root;
	Node* root2 = root;

	valueOneNodes.push(*root1);

	while (root1->getValue() != value1)
	{
		if (value1 < root1->getValue())
		{
			if (root1->getLeft() && value1 > root1->getLeft()->getValue())
				root1 = root1->getRight();
			else
				root1 = root1->getLeft();
		}
		else if (value1 > root1->getValue())
		{
			if (root1->getRight() && value1 < root1->getRight()->getValue())
				root1 = root1->getLeft();
			else
				root1 = root1->getRight();
		}
		
		if (root1->getValue() == value1)
			break;
		else
			valueOneNodes.push(*root1);
	}
	
	valueTwoNodes.push(*root2);

	while (root2->getValue() != value2)
	{
		if (value2 < root2->getValue())
		{
			if (root2->getLeft() && value2 > root2->getLeft()->getValue())
				root2 = root2->getRight();
			else
				root2 = root2->getLeft();			
		}
		else if (value2 > root2->getValue())
		{
			if (root2->getRight() && value2 < root2->getRight()->getValue())
				root2 = root2->getLeft();
			else
				root2 = root2->getRight();			
		}

		if (root2->getValue() == value2)
			break;
		else
			valueTwoNodes.push(*root2);
	}

	while (!valueOneNodes.empty())
	{
		Node curr1 = valueOneNodes.top();

		std::stack<Node> valTwoNodes = valueTwoNodes;
		while (!valTwoNodes.empty())
		{
			Node curr2 = valTwoNodes.top();
			if (curr2.getValue() == curr1.getValue())
				return curr2;
			else
				valTwoNodes.pop();
		}

		valueOneNodes.pop();
	}

	return *root1;
}

Node* Node::heapifyBinaryTree(Node* root)
{
	Node* elem = nullptr;

	int nodeSize = traverse(root, 0, NULL);
	const unsigned int constnodeSize = nodeSize;
	Node* nodeArr = new Node[constnodeSize];
	Node nodeArray[5];

	//std::sort(nodeArr, constnodeSize);
	//std::sort(nodeArr, nodeArr + constnodeSize);


	return elem;
}

int Node::traverse(Node* node, int count, Node* arr[])
{
	if (node == nullptr) return count;
	if (arr != nullptr)
		arr[count] = node;

	count++;
	count = traverse(node->getLeft(), count, arr);
	count = traverse(node->getRight(), count, arr);

	return count;
}

Node* Node::rotateRight()
{
	Node* newRoot = left;
	left = newRoot->right;
	newRoot->right = this;

	return newRoot;
}


Node::~Node()
{
}