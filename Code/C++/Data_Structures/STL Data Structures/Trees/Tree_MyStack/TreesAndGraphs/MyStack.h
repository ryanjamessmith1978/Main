#pragma once

#include <iostream>

using namespace std;

template<class T>
class MyStack
{
public:

	MyStack() : head(nullptr), tail(nullptr), bIsFlattened(false) {};
	~MyStack();
	void push(T data);
	T pop();
	void printAllValue();

public:
	class Element
	{
	public:
		Element(Element* n, T d) : next(n), data(d) {}
		Element* getNext() const { return next; }
		Element* getPrev() const { return prev; }
		Element* getChild() const { return child; }
		Element* getParent() const { return parent; }
		T getData() const { return data; }
		void setNextElement(Element* n, Element* p) { next = n; if (next) { next->setPrevElement(p); } }
		void setPrevElement(Element* p) { prev = p; }
		void setChildElement(Element* c) { child = c; }
		void setParentElement(Element* par) { parent = par; }

	private:
		Element* next;
		Element* prev;
		Element* child;
		Element* parent;
		T		 data;
	};

	Element* head;
	Element* tail;
	bool	 bIsFlattened;

public:

	bool IsCyclicList(Element* head);
	bool deleteElement(Element* elem);
	bool insertAfter(Element* elem, int data);
	void insertInFront(Element* elem);
	void removeHead();

	void flattenList(Element* head, Element** tail);
	void appendElementList(Element* child, Element** tail);

	void unflattenList(Element* head, Element** tail);
	void exploreAndSeparate(Element* childListStart);

	MyStack<T>::Element* getHead() { return head; }
	MyStack<T>::Element* getTail() { return tail; }
	MyStack<T>::Element* findMToLastElement(Element* head, int m)
	{
		MyStack<T>::Element* current;
		MyStack<T>::Element* mBehind;

		if (!head) { return NULL; }

		current = head;
		for (int i = 0; i < m; i++)
		{
			if (current->getNext())
			{
				current = current->getNext();
			}
			else
				return NULL;
		}

		mBehind = head;
		while (current->getNext())
		{
			current = current->getNext();
			mBehind = mBehind->getNext();
		}

		return mBehind;
	}
};

////////////////////////////////////////////////////////////////// DEFINITIONS ////////////////////////////////////////////////////////////////////////

template<class T>
inline void MyStack<T>::printAllValue()
{
	Element* tmp = head;
	while (tmp)
	{
		if (!bIsFlattened)
		{
			if (tmp->getChild())
			{
				Element* tmpChild = tmp->getChild();

				if (tmpChild)
				{
					while (tmpChild->getChild())
						tmpChild = tmpChild->getChild();

					while (tmpChild->getParent())
					{
						std::cout << tmpChild->getParent()->getData() << " Child's data: ";
						Element* tmpNext = tmpChild;
						while (tmpNext)
						{
							std::cout << tmpNext->getData() << ", ";
							tmpNext = tmpNext->getNext();
							if (!tmpNext) { std::cout << "\n\n"; }
						}
						if (tmpChild->getParent() == nullptr) { break; }
						tmpChild = tmpChild->getParent();
					}
				}
			}
		}

		std::cout << tmp->getData() << ", ";
		tmp = tmp->getNext();
	}

	std::cout << "\n\n";
}

template<class T>
inline bool MyStack<T>::IsCyclicList(Element* head)
{
	/*
	Element* elem = head;

	while (elem)
	{
	if (elem == elem->getNext()) { return true; }
	if (elem->getNext() == nullptr) { return false; }

	Element* nextElem = elem->getNext();
	while (nextElem)
	{
	if (nextElem->getNext() == elem) { return true; }
	nextElem = nextElem->getNext();
	}

	elem = elem->getNext();
	}*/

	Element* fast;
	Element* slow;

	if (!head) { return false; }

	slow = head;
	fast = head->getNext();

	while (true)
	{
		if (!fast || !fast->getNext())
			return false;
		else if (fast == slow || fast->getNext() == slow)
			return true;
		else
		{
			slow = slow->getNext();
			fast = fast->getNext()->getNext();
		}
	}

	return false;
}

template<class T>
inline bool MyStack<T>::deleteElement(Element* elem)
{
	Element* curPos = head;
	if (!elem) { return false; }

	if (elem == head)
	{
		head = elem->getNext();
		delete elem;
		if (!head) { tail = nullptr; }
		return true;
	}

	while (curPos)
	{
		if (curPos->getNext() == elem)
		{
			curPos->setNextElement(elem->getNext(), curPos);
			delete elem;
			if (curPos->getNext() == nullptr) { tail = curPos; }
			return true;
		}
		curPos = curPos->getNext();
	}
	return false;
}

template<class T>
inline bool MyStack<T>::insertAfter(Element* elem, int data)
{
	Element* newElem = nullptr;
	Element* curPos = nullptr;
	Element** ppNext = &head;

	newElem = new Element(nullptr, data);

	while (true)
	{
		if (curPos == elem)
		{
			newElem->next = *ppNext;
			*ppNext = newElem;
			// Update tail if inserting at end of list
			if (!(newElem->next))
				tail = newElem;
			return true;
		}
		if (!(curPos = *ppNext))
			break;
		ppNext = &(curPos->next);
	}

	delete newElem;
	return false;
}

template<class T>
inline void MyStack<T>::insertInFront(Element* elem)
{
	elem->setNextElement(head, nullptr);
	head = elem;
}

template<class T>
inline void MyStack<T>::removeHead()
{
	Element* tmp;
	if (head)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
}

template<class T>
inline void MyStack<T>::flattenList(Element* head, Element** tail)
{
	bIsFlattened = true;

	std::cout << "\\\\\\\\\\\\\\ FLATTENED \\\\\\\\\\\\\\" << "\n\n";

	Element* curNode = head;
	while (curNode)
	{
		if (curNode->getChild())
		{
			appendElementList(curNode->getChild(), tail);
		}
		curNode = curNode->getNext();
	}
}

template<class T>
inline void MyStack<T>::appendElementList(Element* child, Element** tail)
{
	Element* curNode;
	(*tail)->setNextElement(child, *tail);
	child->setPrevElement(*tail);

	// Find the new tail, which is the end of the child list.
	for (curNode = child; curNode->getNext(); curNode = curNode->getNext()); // intentionally empty

																			 // Update the tail pointer now that curNode is the new tail
	*tail = curNode;
}

template<class T> // bad code
inline void MyStack<T>::unflattenList(Element* head, Element** tail)
{
	std::cout << "\\\\\\\\\\\\\\ UNFLATTENED \\\\\\\\\\\\\\" << "\n\n";

	bIsFlattened = true;

	Element* curNode;

	exploreAndSeparate(head);

	for (curNode = head; curNode->getNext(); curNode = curNode->getNext());

	*tail = curNode;
}

template<class T> // bad code
inline void MyStack<T>::exploreAndSeparate(Element* childListStart)
{
	Element* curNode = childListStart;

	while (curNode)
	{
		Element* curNodeChild = curNode->getChild();
		if (curNodeChild)
		{
			// get to bottom most child
			while (curNodeChild->getChild())
				curNodeChild = curNodeChild->getChild();

			// remove bottom most child
			// remove all other children on the same level (via next)
			while (curNodeChild->getParent())
			{
				Element* tmp = curNodeChild;
				if (tmp->getNext() == nullptr)
				{
					Element* tmpChild = curNodeChild->getParent();
					tmp->setChildElement(nullptr);
					this->deleteElement(tmp);
					curNodeChild = tmpChild;
					if (curNodeChild->getParent() == nullptr) { break; }
					continue;
				}
				else
				{
					while (tmp->getNext())
					{
						Element* next = tmp->getNext();
						tmp->setChildElement(nullptr);
						this->deleteElement(tmp);
						tmp = next;
					}

					curNodeChild = tmp->getParent();
					tmp->setChildElement(nullptr);
					this->deleteElement(tmp);
					if (curNodeChild->getParent() == nullptr) { break; }
				}
			}
		}
		curNode = curNode->getNext();
	}
}

template<class T>
inline T MyStack<T>::pop()
{
	Element* popElement = head;
	T data;

	if (head == nullptr)
		return; // throw MyStackError(E_EMPTY);

	data = head->getData();
	head = head->getNext();
	delete popElement;
	return data;
}

template<class T>
inline void MyStack<T>::push(T data)
{
	Element* elem = new Element(head, data);
	//head->setPrevElement(elem);
	head = elem;
	if (head->getNext() == nullptr) { tail = head; }
}


template<class T>
MyStack<T>::~MyStack()
{
	while (head)
	{
		Element* next = head->getNext();
		delete head;
		head = next;
	}
}