#ifndef SDLGLWINDOW_H
#define SDLGLWINDOW_H

#include "AWindow.h"
#include <SDL\SDL.h>

class SDLGLWindow : public AWindow {
public:
	SDLGLWindow();

	bool OnCreate(string title, int X, int Y, int width, int height);

	//Title
	void SetTitle(const string tile) override;

	~SDLGLWindow();

	SDL_Window *window;
	SDL_GLContext context;

private:
	bool InitSDL();
	bool InitGL();
	void SetAttributes(int major, int minor);
	
	void GetInstalledOpenGLInfo(int *major, int *minor);
};

#endif // !SDLGLWINDOW_H
