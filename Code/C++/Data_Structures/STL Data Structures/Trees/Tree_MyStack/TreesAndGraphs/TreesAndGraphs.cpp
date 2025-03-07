// TreesAndGraphs.cpp 


#include "stdafx.h"
#include <iostream>
#include <string>
#include "Node.h"
//#include "MyStack.h"
#include <stack>

using namespace std;

void preorderTraversal(Node root);

int main()
{
	//                     5
	//               4           6
	//             2   3       7   8
	//          -1   1           9   10

	Node* NegOne = new Node(nullptr, nullptr, -1);
	Node* One = new Node(nullptr, nullptr, 1);
	Node* Two = new Node(NegOne, One, 2);
	Node* Three = new Node(nullptr, nullptr, 3);
	Node* Foor = new Node(Two, Three, 4);	
	
	Node* Nine = new Node(nullptr, nullptr, 9);
	Node* Ten = new Node(nullptr, nullptr, 10);
	Node* Seven = new Node(nullptr, nullptr, 7);
	Node* Eight = new Node(Nine, Ten, 8);
	Node* Six = new Node(Seven, Eight, 6);	
	Node* Five = new Node(Foor, Six, 5);
	
	//std::cout << "Lowest Common Ancestor: " << (Five->findLowestCommonAncestor(Five, 1, 3)).getValue()
	//  << "\n\n"; // PreOrder, InOrder, PostOrder depth first traversals
	
	// preorderTraversal(*Five);
	// Five->heapifyBinaryTree(Five);

	// Unbalanced Tree            6
	//                        4       7
	//                    2      5
	//                 1     3

	Node* uOne = new Node(nullptr, nullptr, 1);
	Node* uThree = new Node(nullptr, nullptr, 3);
	Node* uFive = new Node(nullptr, nullptr, 5);
	Node* uSeven = new Node(nullptr, nullptr, 7);
	Node* uTwo = new Node(uOne, uThree, 2);
	Node* uFour = new Node(uTwo, uFive, 4);
	Node* uSix = new Node(uFour, uSeven, 6);

	uSix->preOrderTraversal(uSix);
	std::cout << "\n\n";
	uSix = uSix->rotateRight();
	uSix->preOrderTraversal(uSix);

	delete Five;
    return 0;
}

void preorderTraversal(Node root)
{
	std::stack<Node> myStack;
	myStack.push(root);

	while (!myStack.empty())// bah
	{
		Node curr = myStack.top();
		curr.printValue(curr.getValue());
		myStack.pop();
		Node elem(nullptr, nullptr, 0);
		if ((curr.getRight()) != nullptr) { elem = *(curr.getRight()); }
		if(elem.getValue() != 0) { myStack.push(elem); }
		if ((curr.getLeft()) != nullptr) { elem = *(curr.getLeft()); }
		if (elem.getValue() != 0) { myStack.push(elem); }
	}
}