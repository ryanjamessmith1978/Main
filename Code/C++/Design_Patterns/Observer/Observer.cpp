// Observer.cpp  | https://www.youtube.com/watch?v=Th1A2szPctI&list=PLalVdRk2RC6otl3oBU2cn-P6DWi1y1PS3&index=13
// Subscriber pattern
// Observe what's going on elsewhere without being directly involved.

#include "subject.h"

int main() {
	Subject* channel = new Subject();
	Subscriber* subscriber = new Subscriber();

	channel->Add(subscriber);
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();

	Subscriber* subscriber2 = new Subscriber();
	channel->Add(subscriber2);

	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();

	system("pause");
}