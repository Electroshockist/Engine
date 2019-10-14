#pragma once
#include "AWindow.h"
#include "SDL\SDL.h"

class SDLGLWindow : public AWindow {
public:
	SDLGLWindow(string title, int X, int Y, int width, int height);

	//Title
	void setTitle(string* T) override;

	~SDLGLWindow();

	SDL_Window *window;

private:
	int initSDL();
	SDL_Event windowEvent;
};

