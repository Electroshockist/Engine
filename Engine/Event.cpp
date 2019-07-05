#include "pch.h"
#include "Event.h"

Event::Listener::Listener(Event * event) {
	subscribe(event);
}

void Event::Listener::subscribe(Event * event) {
	subscribedEvent = event;
	event->listeners.push_back(this);
	std::cout << "subscribed" << std::endl;
}

void Event::Listener::unsubscribe() {
	std::vector<Listener*>* listeners = &subscribedEvent->listeners;

	for (size_t i = 0; i < listeners->size(); i++) {
		if (listeners->at(i) == this) {
			listeners->erase(listeners->begin() + i);
		}

	}
}

Event::Listener::~Listener() {
	unsubscribe();
}

void Event::notify() {
	for (size_t i = 0; i < listeners.size(); i++) {
		listeners.at(i)->onNotify();
	}
}

Event::~Event() {
}
