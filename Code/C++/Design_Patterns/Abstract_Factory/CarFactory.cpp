
#include <iostream>
#include "Car.cpp"

class CarFactory {

public:
	virtual Car* buildWholeCar() = 0;

protected:
	virtual Tire* buildTire() = 0;
	virtual Body* buildBody() = 0;

private:
	Car* car;
};

class SimpleCarFactory : public CarFactory {
	Tire* buildTire() {
		return new SimpleTire();
	}
	Body* buildBody() {
		return new SimpleBody();
	}

	Car* buildWholeCar() {
		Car* car = new Car("SimpleCar");
		car->setTire(buildTire());
		car->setBody(buildBody());
		return car;
	}
};

class LuxuryCarFactory : public CarFactory {
	Tire* buildTire() {
		return new LuxuryTire();
	}
	Body* buildBody() {
		return new LuxuryBody();
	}
	Car* buildWholeCar() {
		Car* car = new Car("LuxuryCar");
		car->setTire(buildTire());
		car->setBody(buildBody());
		return car;
	}
};