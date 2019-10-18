#ifndef LISTENER_H
#define LISTENER_H

//Event listener
struct AListener {
	//The event that the listener is subscribed to
	class AEvent* subscribedEvent;

	//AEvent is a friend so that only AEvent can call onNotify()
	friend AEvent;

	AListener(AEvent* event);

	//subscribe to an event
	void subscribe(AEvent* event);
	//unsubscribe from current event
	void unsubscribe();

	virtual ~AListener();

protected:
	//Called when a subscribed event calls its notify() function
	virtual void onNotify() {};
};

#endif //!LISTENER_H

