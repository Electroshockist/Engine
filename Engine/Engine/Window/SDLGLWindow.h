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

	MATH::Vector2 getDimensions() override;

	~SDLGLWindow();

	SDL_Window *window;

private:
	int initSDL();
	SDL_Event windowEvent;
};

