// Enumerations.cpp 
//

#include <iostream>

using namespace std;

enum EPowers
{
	keN = 3,
	keNSquared = keN * keN,
	keNCubed = keNSquared * keN
};

enum ECardSuit
{
	keClubs = 4,
	keDiamonds,
	keHearts = 10,
	keSpades
};

enum EColor
{
	keRed,
	keBlue,
	keGreen
};

int main()
{
	/*
	cout << keClubs << endl;
	cout << keDiamonds << endl;
	cout << keHearts << endl;
	cout << keSpades << endl;
	*/
	
	cout << keN << endl;
	cout << keNSquared << endl;
	cout << keNCubed << endl;
	

	EColor eMyColor = keBlue;

	int iInt = 2;
	eMyColor = (EColor)iInt;

	cout << eMyColor << endl;

	system("pause");
}