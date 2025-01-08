// FunctionPointers2.cpp :


#include <iostream>
using namespace std;

double Add(double dX, double dY)
{
    return dX + dY;
}

double Multiply(double dX, double dY)
{
    return dX * dY;
}


int main()
{
    double (*fnOperation)(double, double);
    fnOperation = Add;
    cout << fnOperation(2.0, 3.0) << endl;

    fnOperation = Multiply;
    cout << fnOperation(2.0, 3.0) << endl;

    double (*fnOperation2[2]) (double, double) = { Add, Multiply };

    cout << fnOperation2[0](2.0, 3.0) << endl;
    cout << fnOperation2[1](2.0, 3.0) << endl;

    system("pause");

    return 0;
}
