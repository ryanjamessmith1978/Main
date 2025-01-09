#include "Dice.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Dice::Dice()
{
	srand(time(0));
	RollNumber = CreateRollNumber();
}

Dice::~Dice()
{

}

int Dice::CreateRollNumber()
{	
	RollNumber = rand() % 6 + 1;
	return RollNumber;
}
