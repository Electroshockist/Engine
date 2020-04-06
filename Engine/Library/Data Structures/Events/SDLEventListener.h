#ifndef EVENTLISTENER
#define EVENTLISTENER

#include "Mouse/MouseEventHandler.h"

class Engine;
class SDLEventListener {
public:
		//delete constructors for singleton
	SDLEventListener() = delete;
	SDLEventListener(const SDLEventListener&) = delete;
	SDLEventListener(SDLEventListener&&) = delete;
	SDLEventListener& operator=(const SDLEventListener&) = delete;
	SDLEventListener& operator=(SDLEventListener&&) = delete;
	~SDLEventListener();

	static void Update();
};
#endif // !EVENTLISTENER

