#pragma once
#include "AWindow.h"
#include "SDL\SDL.h"

class SDLWindow : public AWindow {
public:
	SDLWindow(string title, int X, int Y, int width, int height);

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

	~SDLWindow();

private:
	SDL_Window *window = NULL;
	int initSDL();
};

