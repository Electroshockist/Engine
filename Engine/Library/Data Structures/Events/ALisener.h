#ifndef LISTENER_H
#define LISTENER_H

//Event listener
struct AListener {
	//The event that the listener is subscribed to
	class Event* subscribedEvent;

	//AEvent is a friend so that only AEvent can call onNotify()
	friend Event;

	AListener(Event* event);

	//subscribe to an event
	void Subscribe(Event* event);
	//unsubscribe from current event
	void Unsubscribe();

	virtual ~AListener();

protected:
	//Called when a subscribed event calls its notify() function
	virtual void OnNotify() = 0;
};

#endif //!LISTENER_H

