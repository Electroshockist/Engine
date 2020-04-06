#include "SDLEventListener.h"
#include "../../Engine/EngineMain.h"

SDLEventListener::~SDLEventListener(){}

void SDLEventListener::Update(){
	SDL_Event SDLevent;
	while(SDL_PollEvent(&SDLevent)){
		if(SDLevent.type == SDL_QUIT){
			EngineMain::GetInstance()->Exit();
		}
		MouseEventHandler::Update(SDLevent);
	}
}
