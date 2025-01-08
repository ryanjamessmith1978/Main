#include "CStack.h"
#include <stddef.h>
#include <stdio.h>

bool push(struct Element** stack, void* data)
{
	struct Element* elem = malloc(sizeof(struct Element));

	if (!elem) { return false; }

	elem->data = data;
	elem->next = *stack;
	*stack = elem;
	return true;
}

bool pop(struct Element** stack, void** data)
{
	struct Element* elem;

	if (!(elem = *stack)) { return false; } // if the operation of assigning pointer that stacks point to, to the value of a new struct Element fails, then return false, else perform assignment.  Aka if the stack is empty

	*data = elem->data; // passes back void* data of this stack's element back to the caller.  
	*stack = elem->next; // assigns the pointer of the next element to the current stack's position
	free(elem); // removes the item
	return true;
}

bool createStack(struct Element** stack)
{
	*stack = NULL;
	return true;
}

bool deleteStack(struct Element** stack)
{
	struct Element* next;

	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}

	return true;
}

bool deleteElement(struct Element** head, struct Element* elem)
{
	struct Element* curPos = *head;

	if (elem == *head)
	{
		head = elem->next;
		free(elem);
		return true;
	}

	while (curPos)
	{
		if (curPos->next == elem)
		{
			curPos->next = elem->next;
			free(elem);
			if (curPos->next == NULL) { struct Element* tail = curPos; }
			return true;
		}
		curPos = curPos->next;
	}

	return false;
}

bool insertAfter(struct Element** head, struct Element* elem, int data)
{

	return true;
}