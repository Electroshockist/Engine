#ifndef BASEEVENT_H
#define BASEEVENT_H

#include <vector>
#include "ALisener.h"

struct Event {
	friend AListener;
	Event() {}
	//Notifies all listeners in listeners list
	inline void notify() {
		for(size_t i = 0; i < listeners.size(); i++) {
			listeners.at(i)->onNotify();
		}
	}
	virtual ~Event();

private:
	//Stores a list of listeners to notify when notify() is called
	std::vector<AListener*> listeners;
};

#endif // !BASEEVENT_H
