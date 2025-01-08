// MemberFunctionPointers1 :

#include <iostream>
#include <cmath>

class CPoint
{
public:
    CPoint(double dX, double dY) : mdX(dX), mdY(dY) {}

    double TwoShortTriangleSides(CPoint& qrP)
    {
        // cmath::fabs is for finding absolute value
        return fabs(mdX - qrP.mdX) + fabs(mdY - qrP.mdY);
    }

    double Hypotenuse(CPoint& qrP)
    {
        return sqrt( (mdX - qrP.mdX) * (mdX - qrP.mdX) +
            (mdY - qrP.mdY) * (mdY - qrP.mdY) );
    }

private:
    double mdX;
    double mdY;

};


int main()
{
    using namespace std;

    CPoint qPoint1(6.0, 5.0);
    CPoint qPoint2(2.0, 2.0);

    cout << "Both Short Triangle Sides added distance = " << qPoint1.TwoShortTriangleSides(qPoint2) << endl;
    cout << "Hypotenuse distance = " << qPoint1.Hypotenuse(qPoint2) << endl << endl;

    //  ----------------  SAME AS ABOVE ----------------------
    
    // fnDistance is a pointer to a member function in the CPoint class,  
    // takes a CPoint argument and returns a double.
    double (CPoint::*fnDistance)(CPoint&); // function pointer declaration
    fnDistance = &CPoint::TwoShortTriangleSides; // assigns function ptr to L1 member function
    cout << "Both Short Triangle Sides added distance = " << (qPoint1.*fnDistance)(qPoint2) << endl; // dot de-reference operator
    fnDistance = &CPoint::Hypotenuse;
    cout << "Hypotenuse distance = " << (qPoint1.*fnDistance)(qPoint2) << endl;

    system("pause");
    return 0;
}

