#include "AEvent.h"

AListener::AListener(AEvent * event) {
	subscribe(event);
}

void AListener::subscribe(AEvent * event) {
	subscribedEvent = event;
	event->listeners.push_back(this);
}

void AListener::unsubscribe() {
	std::vector<AListener*>* listeners = &subscribedEvent->listeners;

	for (size_t i = 0; i < listeners->size(); i++) {
		if (listeners->at(i) == this) {
			listeners->erase(listeners->begin() + i);
		}

	}
}

AListener::~AListener() {
	unsubscribe();
}