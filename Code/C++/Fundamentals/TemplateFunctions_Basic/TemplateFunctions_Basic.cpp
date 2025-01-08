// TemplateFunctions_Basic.cpp : 

#include <iostream>

template <typename PData>
PData Max(PData xValue1, PData xValue2);

template <typename PData>
void Swap(PData& xrItem1, PData& xrItem2);

int main()
{
    using namespace std;
    int* pIntPtr = new int;


    // Max function
    int iInt1 = 1;
    int iInt2 = 2;
    cout << Max(iInt1, iInt2) << endl;
    double dDouble1 = 3.4;
    double dDouble2 = 1.5;
    cout << Max(dDouble1, dDouble2) << endl;

    // Swap function
    int i1 = 1;
    int i2 = 2;
    cout << i1 << " " << i2 << endl;
    Swap(i1, i2);
    cout << i1 << " " << i2 << endl;

    double d1 = 1.2;
    double d2 = 2.1;
    cout << d1 << " " << d2 << endl;
    Swap(d1, d2);
    cout << d1 << " " << d2 << endl;

    system("pause");
}

// PData is the template datatype
// template <typename PData> syntax needs to be directly above function using template
// Max is a function that uses the PData template.

template <typename PData>
PData Max(PData xValue1, PData xValue2)
{
    if (xValue1 > xValue2)
    {
        return xValue1;
    }
    else
    {
        return xValue2;
    }
}

template <typename PData>
void Swap(PData& xrItem1, PData& xrItem2)
{
    PData xTemp = xrItem1;
    xrItem1 = xrItem2;
    xrItem2 = xTemp;
}
