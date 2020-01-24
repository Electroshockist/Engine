#include "Event.h"

AListener::AListener(Event * event) {
	Subscribe(event);
}

void AListener::Subscribe(Event * event) {
	subscribedEvent = event;
	event->listeners.push_back(this);
}

void AListener::Unsubscribe() {
	std::vector<AListener*>* listeners = &subscribedEvent->listeners;

	for (size_t i = 0; i < listeners->size(); i++) {
		if (listeners->at(i) == this) {
			listeners->erase(listeners->begin() + i);
		}
	}
}

AListener::~AListener() {
	Unsubscribe();
}