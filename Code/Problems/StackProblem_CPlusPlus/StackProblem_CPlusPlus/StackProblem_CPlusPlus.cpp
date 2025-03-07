// StackProblem_CPlusPlus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyStack.h"
#include <iostream>

int main()
{
	MyStack<int>* myStack = new MyStack<int>();

	myStack->push(5);
	myStack->push(4);
	myStack->push(3);
	myStack->push(2);
	myStack->push(1);		
	
	MyStack<int>::Element* inst = new MyStack<int>::Element(nullptr, -1);
	MyStack<int>::Element* instCh1 = new MyStack<int>::Element(nullptr, -10);
	MyStack<int>::Element* instChCh1 = new MyStack<int>::Element(nullptr, -100);
	MyStack<int>::Element* instChCh2 = new MyStack<int>::Element(nullptr, -200);
	MyStack<int>::Element* instChChCh1 = new MyStack<int>::Element(nullptr, -1000);
	MyStack<int>::Element* instCh2 = new MyStack<int>::Element(nullptr, -20);
	inst->setChildElement(instCh1);
	instCh1->setNextElement(instCh2, instCh1);
	instCh1->setChildElement(instChCh1);
	instCh1->setParentElement(inst);
	instCh2->setParentElement(inst);
	instChCh1->setNextElement(instChCh2, instChCh1);
	instChCh1->setChildElement(instChChCh1);
	instChCh1->setParentElement(instCh1);
	instChCh2->setParentElement(instCh1);
	instChChCh1->setParentElement(instChCh1);

	MyStack<int>::Element* tail = &(*(myStack->getTail()));
	myStack->insertInFront(inst);
	//tail->setNextElement(inst, tail);
	myStack->printAllValue();
	
	/*
	myStack->flattenList(myStack->getHead(), &tail);
	myStack->printAllValue();
	*/
	
	std::cout << "Is Acyclic: " << myStack->IsCyclicList(&(*(myStack->getTail()))) << "\n\n";
	

	/*
	MyStack<int>::Element* inst1 = new MyStack<int>::Element(nullptr, -1);
	myStack->insertInFront(inst);
	myStack->insertInFront(inst1);	
	myStack->push(-2);
	myStack->printAllValue();

	std::cout << "\n\n";
	std::cout << myStack->findMToLastElement(myStack->head, 0)->getData() << std::endl;
	*/

    return 0;
}
