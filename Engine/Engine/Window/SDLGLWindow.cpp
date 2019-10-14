#include "SDLGLWindow.h"
#include <iostream>


SDLGLWindow::SDLGLWindow(string title, int X, int Y, int width, int height) : window(nullptr) {
	AWindow::setTitle(&title);
	initSDL();
	SDL_Event windowEvent;
	window = SDL_CreateWindow(title.c_str(), X, Y, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

	if(window == nullptr) {
		cout << "SDLGLWindow creation failed: " << SDL_GetError() << endl;
		return;
	}
}

void SDLGLWindow::setTitle(string* title) {
	AWindow::setTitle(title);
	SDL_SetWindowTitle(window, title->c_str());
}

SDLGLWindow::~SDLGLWindow() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int SDLGLWindow::initSDL() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
