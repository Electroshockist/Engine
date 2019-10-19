#ifndef AEVENT_H
#define AEVENT_H

#include <vector>
#include "ALisener.h"

struct AEvent {
	friend AListener;
	AEvent() {}
	//Notifies all listeners in listeners list
	inline void notify() {
		for(size_t i = 0; i < listeners.size(); i++) {
			listeners.at(i)->onNotify();
		}
	}
	virtual ~AEvent();

private:
	//Stores a list of listeners to notify when notify() is called
	std::vector<AListener*> listeners;
};

#endif // !AEVENT_H
