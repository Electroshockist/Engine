#pragma once
#include "AWindow.h"
#include "SDL\SDL.h"

class SDLGLWindow : public AWindow {
public:
	SDLGLWindow(string title, int X, int Y, int width, int height);

	//Title
	void setTitle(string T) override;
	string getTitle() override;

	//Position
	int getX() override;
	int getY() override;

	//Size
	MATH::Vector2 getPosition() override;

	int getWidth() override;
	int getHeight() override;

	void addEventListener(string event) override;

	~SDLGLWindow();

	SDL_Window *window = NULL;

private:
	int initSDL();
	SDL_Event windowEvent;
};

