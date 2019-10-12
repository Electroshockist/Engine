#include "SDLGLWindow.h"
#include <iostream>


SDLGLWindow::SDLGLWindow(string title, int X, int Y, int width, int height) : window(nullptr) {

	initSDL();
	SDL_Event windowEvent;
	window = SDL_CreateWindow(title.c_str(), X, Y, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

	if(window == nullptr) {
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

int SDLGLWindow::getX() {
	return getPosition().x;
}

int SDLGLWindow::getY() {
	return getPosition().y;
}

MATH::Vector2 SDLGLWindow::getPosition() {
	int *x = nullptr, *y = nullptr;
	SDL_GetWindowPosition(window, x, y);

	return MATH::Vector2(*x, *y);
}

int SDLGLWindow::getWidth() {
	return getDimensions().x;
}

int SDLGLWindow::getHeight() {
	return getDimensions().y;
}

MATH::Vector2 SDLGLWindow::getDimensions() {
	int *w = nullptr, *h = nullptr;
	SDL_GetWindowSize(window, w, h);

	return MATH::Vector2(*w, *h);
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
