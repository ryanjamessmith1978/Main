// Polymorphism.cpp :

#include <iostream>
using namespace std;

class CShape
{
public:
    virtual double Area()
    {
        return 0.0;
    }

    // virtual double Area() = 0;
    // Pure Virtual functions - disables the ability to instantiate objects of the class type
    // Pure Virtual functions doesn't disable the ability to use pointers of that base class type. 
    // The constructor doesn't need to be pure virtual, just any function within the base class
    // to disable it from being instantiated.
    // Pure virtual function just like a member function pointer:
    // Depending on the object type, the pointer points to a different function
};

class CCircle : public CShape
{
public:
    CCircle(double dRadius) : mdRadius(dRadius) {}
    virtual double Area()
    {
        return 3.14159 * mdRadius * mdRadius;
    }

private:
    double mdRadius;
};

class CSquare : public CShape
{
public:
    CSquare(double dSide) : mdSide(dSide) {}
    virtual double Area()
    {
        return mdSide * mdSide;
    }

private:
    double mdSide;
};

int main()
{
    CShape* qpaShapes[5];

    CCircle qCircle1(1.0);
    CCircle qCircle2(2.0);
    CCircle qCircle3(3.0);

    CSquare qSquare1(2.0);
    CSquare qSquare2(5.0);

    qpaShapes[0] = &qCircle1;
    qpaShapes[1] = &qCircle2;
    qpaShapes[2] = &qCircle3;
    qpaShapes[3] = &qSquare1;
    qpaShapes[4] = &qSquare2;

    double dAreaSum = 0.0;
    for (int i = 0; i < 5; i++)
    {
        double dArea = qpaShapes[i]->Area();
        std::cout << "Area[" << i << "] = " << dArea << endl;
        dAreaSum = dAreaSum + dArea;
    }
    
    system("pause");
    return 0;
}

