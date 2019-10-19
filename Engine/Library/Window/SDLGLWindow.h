#ifndef SDLGLWINDOW_H
#define SDLGLWINDOW_H

#include "AWindow.h"
#include <SDL\SDL.h>

class SDLGLWindow : public AWindow {
public:
	SDLGLWindow();

	bool onCreate(string title, int X, int Y, int width, int height);

	//Title
	void setTitle(string* T) override;

	~SDLGLWindow();

	SDL_Window *window;
	SDL_GLContext context;

private:
	bool initSDL();
	bool initGL();
	void setAttributes(int major, int minor);
	
	void getInstalledOpenGLInfo(int *major, int *minor);
};

#endif // !SDLGLWINDOW_H
