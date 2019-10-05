#include "SDLGLWindow.h"
#include <iostream>


SDLGLWindow::SDLGLWindow(string title, int X, int Y, int width, int height) {

	initSDL();
	SDL_Event windowEvent;
	window = SDL_CreateWindow(title.c_str(), X, Y, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

	if (window == NULL) {
		cout << "SDLGLWindow creation failed: " << SDL_GetError() << endl;
		return;
	}
}

void SDLGLWindow::setTitle(string t) {
	SDL_SetWindowTitle(window, t.c_str());
}

string SDLGLWindow::getTitle() {
	return SDL_GetWindowTitle(window);
}

int SDLGLWindow::getX()
{
	return 0;
}

int SDLGLWindow::getY()
{
	return 0;
}

MATH::Vector2 SDLGLWindow::getPosition() {
	int *w = nullptr, *h = nullptr;
	SDL_GetWindowSize(window, h, w);

	return MATH::Vector2(*w, *h);
}

int SDLGLWindow::getWidth() {
	int *h = nullptr, *w = nullptr;
	SDL_GetWindowSize(window, h, w);

	return *w;
}

int SDLGLWindow::getHeight() {
	int *h = nullptr, *w = nullptr;
	SDL_GetWindowSize(window, h, w);

	return *h;
}


void SDLGLWindow::addEventListener(string event) {
}

SDLGLWindow::~SDLGLWindow() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int SDLGLWindow::initSDL() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
	}
	return EXIT_SUCCESS;
}
