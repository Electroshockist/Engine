#ifndef AEVENT_H
#define AEVENT_H

#include <vector>
#include "ALisener.h"

struct AEvent {
	friend AListener;
	AEvent() {}
	//Notifies all listeners in listeners list
	void notify();
	virtual ~AEvent();

private:
	//Stores a list of listeners to notify when notify() is called
	std::vector<AListener*> listeners;
};

#endif // !AEVENT_H
