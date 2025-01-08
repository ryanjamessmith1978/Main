#include "car.h"
using namespace std;

class observer
{    
public:
    observer(car* car) {
        _car = car;
        _car->attach(this);
    }
    virtual void update() = 0;

protected:
    car* getCar() {
        return _car;
    }

private:
    car* _car;
};    

class Leftobserver : public observer {
public:
    Leftobserver(car* car) : observer(car) {}
    void update() {
        int pos = getCar()->getPosition();
        if (pos < 0) {
            cout << "left side" << endl;
        }
    }
};

class Rightobserver : public observer {
public:
    Rightobserver(car* car) : observer(car) {}
    void update() {
        int pos = getCar()->getPosition();
        if (pos > 0) {
            cout << "right side" << endl;
        }
    }
};

class Middleobserver : public observer {
public:
    Middleobserver(car* car) : observer(car) {}
    void update() {
        int pos = getCar()->getPosition();
        if (pos == 0) {
            cout << "running in middle" << endl;
        }
    }
};


