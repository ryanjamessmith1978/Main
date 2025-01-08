#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class car {
public:
	int getPosition();
	void setPosition(int newPosition);

	void setTmp(int newTmp);
	void attach(class observer* obs);
	void detach(class observer* obs);
	
	void notify();
	void notifyTmp();

private:
	int position;
	int tmp;
	std::vector<class observer*> observerList;
	std::vector<class observer*> observerTmpList;
};

