#pragma once

typedef enum
{
	false = 0,
	true = 1
} bool;

struct Element
{
	struct Element* next;
	void* data;
};

bool push(struct Element** stack, void* data);
bool pop(struct Element** stack, void** data);
bool createStack(struct Element** stack);
bool deleteStack(struct Element** stack);
bool deleteElement(struct Element** head, struct Element* elem);
// bool insertAfter