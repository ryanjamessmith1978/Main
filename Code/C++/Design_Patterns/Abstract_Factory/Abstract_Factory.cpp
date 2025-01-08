// Abstract Factory Pattern | https://www.youtube.com/watch?v=blDsmrsyOME&list=PLm0fFUL4gEt_Fxr324K9WswUff_Pub7CN&index=2&t=380s

#include <iostream>
#include "CarFactory.cpp"
using namespace std;

#define SIMPLE_CAR 1
//#define LUXURY_CAR 1 // turn on and off depending on which factory I activate.

int main() {

#ifdef SIMPLE_CAR
	CarFactory* factory = new SimpleCarFactory;

#elif LUXURY_CAR
	CarFactory* factory = new LuxuryCarFactory;
#endif

	Car* car = factory->buildWholeCar(); // doesn't know which buildWholeCar def.at compile time
	car->printDetails();				 // depending on which #define is uncommented up top.

	system("pause");
}

// Abstract Factory Design Pattern (AFDP)
// Defines an Abstract Factory Class that creates Families of related objects indirectly
// but doesn't Specify their concrete sub-class (sub-classes are also factories).
// 
// Fundamental Design
// The general creation process is the same in the sub-classes as in the abstract parenty factory 
// but the concrete sub-class factories create different but related classes. 
// 
// Why/When
// Need a system to be independent of how objects are created and composed.
// Need a system configurable with multiple families of objects.
// Client is hidden from the creation process of the objects and it's composition.
// Show interface but not implementation
//
//
// Concrete Class v Abstract Class
//  * An abstract class is meant to be used as a base class where some 
// or all functions are declared purely virtual and hence can not be instantiated.
// A concrete class is an ordinary class which has no purely virtual functions and 
// hence can be instantiated.
//
/* Abstract Class v Interface
While abstract classes can contain both implemented and unimplemented member functions 
and have member variables, interfaces only contain pure virtual functions and no member variables. 
Additionally, a class can only inherit from one abstract class, but it can implement multiple interfaces.
*/