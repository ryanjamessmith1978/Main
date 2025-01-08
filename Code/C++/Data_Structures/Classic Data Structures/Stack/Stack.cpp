// Stack.cpp | https://www.youtube.com/watch?v=yIBkQzL77aY&t=314s
// User-Defined Stack: LIFO
// Stacks are typically defined as a list,
// where the newest element is added to the front of the list
// and when an element is popped, it's removed from the front of the list as well.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    struct Node* next;
};

class stack {
public:
    stack(){}
    ~stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    void push(string d)
    {
        Node* tmp = new Node{ d, m_top };
        m_top = tmp;

    }
    // pops top Node off of the stack
    string pop()
    {
        if (!isEmpty())
        {
            Node* tmp = m_top;
            m_top = m_top->next;
            delete tmp;
            return m_top->data;
        }

        return "Empty";
    }

    void printStack(Node* t)
    {
        while (t != NULL)
        {
            cout << t->data << ", ";
            t = t->next;
        }

        cout << endl;
    }

    Node* top()
    {
        return m_top;
    }

    bool isEmpty() {
        return (m_top == NULL);
    }

private:
    Node* m_top = NULL;
};

int main()
{
    // Does this need to be a pointer?
    stack* myStack = new stack();
    myStack->push("CheeseBurger");
    myStack->push("Pizza");
    myStack->push("Large Coffee");

    myStack->pop();
    myStack->printStack(myStack->top());

    delete myStack;

    system("pause");
}

// Do you need to have a separate Stack class to implement user-defined Stack?