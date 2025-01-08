// Factory Pattern | https://www.youtube.com/watch?v=XyNWEWUSa5E&list=PLk6CEY9XxSIDZhQURp6d8Sgp-A0yKKDKV&index=1
// Creational Design Pattern

#include <iostream>
#include "ToyFactory.cpp"
using namespace std;

int main() {
	
	int toyType = 0;

	while (1) {
		cout << endl << "Enter toyType or Zero for exit" << endl;
		cin >> toyType;

		if (!toyType)
			break;

		// Q: When can you use a class directly to call a function 
		// versus needing to instantiate a local object then call a function?
		// Q: What does it mean when a class has no defined constructor? 
		// Q: What does it mean when a class has no defined constructor with private members uninitialized?
		// In this example, we ran additional set function during it's construction using factory construction?
		// Q: Is that a factory thing, or do members need to be initialized?
		// Creating objects dynamically at runtime.
		Toy* v = ToyFactory::createToy(toyType); // Client doesn't know anything about how object is constructed.
		if (v) {
			v->showProduct();
			delete v;
		}
	}
	cout << "Exit.." << endl;
	

	system("pause");
}

//  ### FACTORY DESIGN PATTERN ###

// FDP: Creates Object for you, rather you instatiating object directly.
// FDP: Call a function that behaves like a factory function, tell factory function what type of object you want.
// Factory Design Pattern also called, 'Virtual Constructor'. 
//  No virtual constructor in C++ (can't construct abstract class in C++).  

// How to implement?
// Define an interface or an abstract class for creating an object
// but let the subclasses decide which class to instantiate.  

// Advantages?  When?
// Less code change if we change object creation process.
// We create object without exposing creation logic to client.  Why would we want that?
// We get the benefits of a virtual constructor.  Dynamic runtime creation using abstract class to create a ptr.