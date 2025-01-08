#pragma once
class InitializerListExample
{
public:

	InitializerListExample(int a, int b) : myInt1(a), myInt2(b) {} // Initializer List
	
	/*  OLD SCHOOL CONSTRUCTOR 
	InitializerListExample(int a, int b)
	{
		myInt1 = a;
		myInt2 = b;
	}
	*/

	inline int GetMyInt1() { return myInt1;}
	inline int GetMyInt2() { return myInt2;}

private:

	int myInt1;
	int myInt2;
};

