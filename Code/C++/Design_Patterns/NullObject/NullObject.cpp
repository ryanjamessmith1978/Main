// NullObject.cpp | https://www.youtube.com/watch?v=e3epYFGrS88&list=PLalVdRk2RC6otl3oBU2cn-P6DWi1y1PS3&index=20
// Design a project where you don't have to do Null checks.
// YOU'LL be able to know if you program runs correctly and don't need ptrs.
// Only accept references which are actual instantiations.


#include "object.h"

// real instantiation that you are accessing with references
// there is no such instantiation possible with an interface
void control_animal(const IAnimal& animal) {
	animal.MakeSound();
}

// this one can pass null into here.
void control_animal2(const IAnimal* animal) {
	animal->MakeSound(); // need a null check
}

int main() {
		
	Dog dog1;
	control_animal(dog1);

	// probably should make it a proxy, and have one staticly initialized at all times.
	NullAnimal nullanimal; 

	// it's tries to take over or call, but there's nothing to call
	control_animal(nullanimal);

	system("pause");
}