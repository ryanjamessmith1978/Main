// Main.c

#include <stddef.h>
#include <stdio.h>
#include "CStack.h"

int main()
{
	printf("Hello World!\n");

	struct Element* myStack = malloc(sizeof(struct Element));
	myStack->data = 4;

	push(&myStack, 3);
	push(&myStack, 2);
	push(&myStack, 1);

	struct Element* tmp = myStack;

	while (tmp)
	{
		printf("%d", tmp->data);
		tmp = tmp->next;
	}

	system("pause");

	return 0;
}