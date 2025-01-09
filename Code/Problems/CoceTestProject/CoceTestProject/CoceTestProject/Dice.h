#pragma once
// Dice Class 
// 

class Dice
{
public:
	Dice();
	~Dice();

	// randomly generated roll
	int CreateRollNumber();

private:

	int RollNumber;

};

