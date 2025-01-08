// ObjectPool.cpp | https://www.youtube.com/watch?v=lNTYs72Hi_0&list=PLalVdRk2RC6otl3oBU2cn-P6DWi1y1PS3&index=4
// Object Pool pattern is used for caching, keeping memory aligned, 
// not re-creating variables, avoids constant allocating and de-allocating of memory.
// Create the object once, pull it when you need it, 
// put it back into the pool when done.

#include <iostream>
#include <cstdlib>
#include "objectpool.h"

// Object Pool is a manager, so you only want one instance of it for 
// allocating and de-allocating objects.
ObjectPool* ObjectPool::instance = nullptr;


int main() {

	// ?? How does defining instance above, give you access to ObjectPool class ??
	ObjectPool* pool = ObjectPool::getInstance();
	Resource* one;
	Resource* two;
	/* Resources will be created. */
	one = pool->getResource();
	one->setValue(10);
	std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
	two = pool->getResource();
	two->setValue(20);
	std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;
	pool->returnResource(one);
	pool->returnResource(two);

	// Resources will be reused.
	// Notice that the value of both resources were reset back to zero.
	one = pool->getResource();
	std::cout << "one = " << one->getValue() << " [" << one << "]" << std::endl;
	two = pool->getResource();
	std::cout << "two = " << two->getValue() << " [" << two << "]" << std::endl;

	system("pause");
}

