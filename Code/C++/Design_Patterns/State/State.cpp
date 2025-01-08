// State.cpp | https://www.youtube.com/watch?v=Y3FHNAYeamc&list=PLalVdRk2RC6otl3oBU2cn-P6DWi1y1PS3&index=16&t=6s
// Designs some sort of situation, your program is in, and do some certain thing
// Initial engine (context), store a back reference in our states, so the states can call back to the engine to change states

// Need a class to handle states.  Engine.

#include <iostream>
#include "state.h"

int main() {
	Engine engine1(new ConcreteStateB);
	engine1.RequestA();
	engine1.RequestA();

	system("pause");
}

// ; semicolons - create a class, call a function, prototype a function (but NOT define a function).  
// why use .cpp files instead of just .h files?