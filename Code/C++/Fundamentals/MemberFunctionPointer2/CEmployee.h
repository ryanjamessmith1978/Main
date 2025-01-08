#pragma once
#include <iostream>

class CEmployee
{
public:

	CEmployee()
	{
		// function ptr variable is defined in private section of this class
		mpfnWageCalc = &CEmployee::TraineeWageCalc; // assigns TraineeWageCalc by default
	}

	void MakeExperienced() 
	{
		mpfnWageCalc = &CEmployee::ExperiencedWageCalc;
	}
	
	// The function that we point to
	// is called with the function ptr inside of our function 'CalculateWage'
	double CalculateWage(double dHousWorked)
	{
		// this-> pointer refers to the object (CEmployee object) that called the member function
		// and because the this-> object is a pointer we use the Arrow Dereference operator ->*
		return (this->*mpfnWageCalc)(dHousWorked); // why do we have to use this?
		
		// In order to use a member function pointer, it has to be assigned to a class
		// Since the member function pointer (*mpfnWageCalc) was already defined locally
		// We don't need to scope to the class when calling, we reference the class's func ptr with this->
		// this-> is a substitue for it's own class
	}

private:

	double (CEmployee::*mpfnWageCalc)(double);
	
	double TraineeWageCalc(double dHoursWorked)
	{
		return 9.25 * dHoursWorked;
	}

	double ExperiencedWageCalc(double dHoursWorked)
	{
		return 15.75 * dHoursWorked;
	}
};

