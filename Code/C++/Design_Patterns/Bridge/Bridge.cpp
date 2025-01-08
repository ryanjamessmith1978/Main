// Bridge.cpp | https://www.youtube.com/watch?v=7BIdsD34-pg
//
// Bridge design pattern is used to decouple a class into two parts – Abstraction and it’s Implementation
// Both can evolve in future without affecting each other. 
// It increases the loose coupling between class abstraction and its implementation 
//
// C++ has no built-in concept of interfaces.
// A C++ Interface is a way to describe the behavior of a class without committing to the implementation.

#include <iostream>
#include <string>
using namespace std;

// Color Interface
class fillColorImp
{
public:
    virtual void fillColor() = 0;
};

class greenColor : public fillColorImp
{
public:
    void fillColor()
    {
        cout << "Its is Green color" << endl;
    }
};

class redColor : public fillColorImp
{
public:
    void fillColor()
    {
        cout << "Its is red color" << endl;
    }
};

// Shape Interface
class Shape {
public:
    virtual void colorIt() = 0;
    virtual void drawIt() = 0;
};

// Bridge Class inherits from Shape
class bridge : public Shape
{
public:
    bridge(fillColorImp* obj)
    {
        cout << "\ninside constructor of bridge class\n" << endl;
        colorObj1 = obj;
    }

    // virtual void colorIt() = 0; these are available to bridge
    // virtual void drawIt() = 0;

protected:
    fillColorImp* colorObj1;

};

// Square Class inherits from Bridge (which inherits from shape)
class square : public bridge
{
public:

    // Passes in fillColor interface *ptr and calls the bridge constructor.
    // Whatever object is passed to square constructor(fillColorImp* obj) is passed to bridge constructor.

    square(fillColorImp* obj) : bridge(obj) {} // bridge contructor : square 'is-a' bridge, NOT 'has-a'

    void colorIt()
    {
        colorObj1->fillColor();
    }

    void drawIt()
    {
        cout << "Squar drawan without color" << endl;
    }

    // fillColorImp* colorObj1; available to this class because's its a bridge.
};

class Rectangle : public bridge
{
public:

    Rectangle(fillColorImp* obj) :bridge(obj) {}

    void colorIt()
    {
        colorObj1->fillColor();
    }

    void drawIt()
    {
        cout << "Squar drawan without color" << endl;
    }
};


int main() {

    Shape* shapeobj1;
    fillColorImp* ObjRed = new redColor;
    fillColorImp* ObjGreen = new greenColor;
    
    //UseCase1
    cout << "\nUsecase1" << endl;
    cout << "------------------------------------" << endl;
    shapeobj1 = new square(ObjRed);
    shapeobj1->colorIt();
    shapeobj1->drawIt();

    // changes square obj to contain a green color object via the bridge
    shapeobj1 = new square(ObjGreen);
    shapeobj1->colorIt();
    shapeobj1->drawIt();
    
    //UseCase2
    cout << "\n\nUsecase2 " << endl;
    cout << "------------------------------------" << endl;
    shapeobj1 = new Rectangle(ObjRed);
    shapeobj1->colorIt();
    shapeobj1->drawIt();
    
    std::cout << "\n";
    system("pause");
}

// BRIDGE DESIGN PATTERN
// De-coupling classes into two parts - abstraction and implementation.
// Implementing Bridge Pattern so classes aren't dependent on each other and can grow independently.
// 
// Problems with convential design (vs using Bridge Design):
// Num of classes, Larger .exe size, readability, tightly coupled, static bindings