
#include <iostream>
using namespace std;

class Tire {
public:
	Tire(string n, int presure) :name(n), presure(presure) {};
	string getName() { return name; }
	int getPresure() { return presure; }

protected:
	string name;
	int presure;
};

class SimpleTire : public Tire {
public:
	SimpleTire() :Tire("SimpleTire", 75) {}
};

class LuxuryTire : public Tire {
public:
	LuxuryTire() :Tire("LuxuryTire", 100) {}
};

class Body {
public:
	Body(string n, int strength) :name(n), strength(strength) {}
	string getName() { return name; }
	int getStrength() { return strength; }

protected:
	string name;
	int strength;
};

class SimpleBody : public Body {
public:
	SimpleBody() :Body("SimpleBody", 75) {}
};

class LuxuryBody : public Body {
public:
	LuxuryBody() :Body("LuxuryBody", 100) {} // uses abstract class' initializer list contructor.
};

class Car {

public:
	Car(string n) :name(n) {}
	void setTire(Tire* t) { tire = t; }
	void setBody(Body* b) { body = b; }
	void printDetails() {
		cout << endl << "Car: " << name << endl;
		cout << "Tire: " << tire->getName() << " Presure: " << tire->getPresure() << endl;
		cout << "Body: " << body->getName() << " Strength: " << body->getStrength() << endl << endl;
	}

protected:
	string name;
	Tire* tire;
	Body* body;
};