#ifndef __io__
#define __io__

#include <iostream>
using namespace std;

#endif

#include "Toy.cpp"

class ToyFactory {
public:
	static Toy* createToy(int type) {

		Toy* toy = NULL;

		switch (type) {
		case 1: {
			toy = new Car;
			break;
		}
		case 2: {
			toy = new Bike;
			break;
		}
		case 3: {
			toy = new Plane;
			break;
		}
		default: {
			cout << "invalid toy type please re-enter type" << endl;
			return NULL;
		}
		}

		toy->prepareParts();
		toy->combineParts();
		// Advantage to a Factory: you can add preprocessing here in future 
		// without accounting for construction behavior of individual objects
		toy->assembleParts();
		toy->applyLabel();

		return toy;
	}
};