#include "pch.h"
#include "SDLWindow.h"


SDLWindow::SDLWindow(string title, int X, int Y, int width, int height) {

	initSDL();
	SDL_Event windowEvent;
	window = SDL_CreateWindow(title.c_str(), X, Y, width, height, SDL_WINDOW_ALLOW_HIGHDPI);

	if (window == NULL) {
		cout << "SDLWindow creation failed: " << SDL_GetError() << endl;
		return;
	}
}

void SDLWindow::setTitle(string t) {
	SDL_SetWindowTitle(window, t.c_str());
}

string SDLWindow::getTitle() {
	return SDL_GetWindowTitle(window);
}

int SDLWindow::getX()
{
	return 0;
}

int SDLWindow::getY()
{
	return 0;
}

MATH::Vector2 SDLWindow::getPosition() {
	int *w = nullptr, *h = nullptr;
	SDL_GetWindowSize(window, h, w);

	return MATH::Vector2(*w, *h);
}

int SDLWindow::getWidth() {
	int *h = nullptr, *w = nullptr;
	SDL_GetWindowSize(window, h, w);

	return *w;
}

int SDLWindow::getHeight() {
	int *h = nullptr, *w = nullptr;
	SDL_GetWindowSize(window, h, w);

	return *h;
}


void SDLWindow::addEventListener(string event)
{
}

SDLWindow::~SDLWindow() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int SDLWindow::initSDL() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
	}
	return EXIT_SUCCESS;
}
