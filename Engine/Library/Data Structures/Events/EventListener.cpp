#include "EventListener.h"
#include "../../Engine/EngineMain.h"

EventListener::~EventListener() {}

void EventListener::update() {
	SDL_Event SDLevent;
	while(SDL_PollEvent(&SDLevent)) {
		if(SDLevent.type == SDL_QUIT) {
			EngineMain::GetInstance()->Exit();
		}
		switch(SDLevent.type) {
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEMOTION:
			case SDL_MOUSEWHEEL:
				MouseEventListener::Update(SDLevent);
				break;
			default:
				break;
		}
	}
}
