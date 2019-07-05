//todo
#include <vector>
#include <iostream>

#pragma once
struct Event {
	struct Listener {
		Event* subscribedEvent;
		Listener(Event* event);

		void subscribe(Event* event);
		void unsubscribe();

		inline virtual void onNotify() {
			std::cout << "notified" << std::endl;
		};

		virtual ~Listener();
	};

	friend Listener;
	Event() {}
	void notify();
	~Event();

private:
	std::vector<Listener*> listeners;
};
