// FunctionPtrs3_CoinSort.cpp :

#include <iostream>
#include <cstdlib>

using namespace std;

class CCoin
{
public:
	int miYear;
	int miValue;
};

int CompareByYear(const void* kvpCoin1, const void* kvpCoin2)
{
	CCoin* qpCoin1 = (CCoin*)kvpCoin1;
	CCoin* qpCoin2 = (CCoin*)kvpCoin2;
	if (qpCoin1->miYear < qpCoin2->miYear)
	{
		return -1;
	}
	else if (qpCoin1->miYear == qpCoin2->miYear)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int CompareByValue(const void* kvpCoin1, const void* kvpCoin2)
{
	CCoin* qpCoin1 = (CCoin*)kvpCoin1;
	CCoin* qpCoin2 = (CCoin*)kvpCoin2;
	if (qpCoin1->miValue < qpCoin2->miValue)
	{
		return -1;
	}
	else if (qpCoin1->miValue == qpCoin2->miValue)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


int main()
{
	CCoin qaCoin[] = { {1986, 25}, {1982, 1}, {1979, 10}, {1980, 100}, {1984, 50} };

	// So, even though the defintion of qSort takes a fn pointer, we can pass in a function directly without the ()
	qsort(qaCoin, 5, sizeof(CCoin), CompareByYear); 
	cout << "Sorted by year" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Coin #" << i << ": Year = " << qaCoin[i].miYear
			<< " Value = " << qaCoin[i].miValue << endl;
	}

	qsort(qaCoin, 5, sizeof(CCoin), CompareByValue);
	cout << "Sorted by value" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Coin #" << i << ": Year = " << qaCoin[i].miYear
			<< " Value = " << qaCoin[i].miValue << endl;
	}	
   
	system("pause");

	return 0;
}

/*
	void qsort( const void* kvpArray, size_t qNumberOfElements, size_t qElementSizeInBytes, 
	int (*pfnCompareFn) ( const void *, const void *));
	// ^^ This is a function pointer argument... but where is the function pointer declaration in main for CompareByYear?
*/
