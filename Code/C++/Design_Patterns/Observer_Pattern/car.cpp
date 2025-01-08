#include <iostream>
#include <vector>
#include <algorithm>
#include "observer.h"
#include "car.h"

// ctrl+k, ctrl+o to switch between .h and .cpp

using namespace std;

int car::getPosition()
{
	return position;
}
void car::setPosition(int newPosition)
{
	position = newPosition;
	notify();
}
void car::setTmp(int newTmp)
{
	tmp = newTmp;
	notifyTmp();
}
void car::attach(class observer* obs)
{
	observerList.push_back(obs);
}
void car::detach(class observer* obs)
{
	observerList.erase(std::remove(observerList.begin(), observerList.end(), obs), observerList.end());
}
void car::notify()
{
	for (int i = 0; i < observerList.size(); ++i)
	{
		observerList[i]->update();
	}
}
void car::notifyTmp()
{
	for (int i = 0; i < observerTmpList.size(); ++i) 
	{
		observerTmpList[i]->update();
	}
}