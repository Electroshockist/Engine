#pragma once
#ifndef GLUTWINDOW_H
#define GLUTWINDOW_H

#include <string>

#include "AWindowBase.h"
#include "GlutMouseAdapter.h"

class GlutWindow : public AWindowBase
{
public:
	GlutWindow(string title, int X, int Y, int width, int height);

	//Implements functionality for mouse button click an mouse motion
	void addEventListener(string event)
	{
		if (event == GlutMouseEvent::MOUSE_PRESSED)
			glutMouseFunc(&GlutMouseAdapter::mouseClicked);
		else if (event == GlutMouseEvent::MOUSE_MOVED)
			glutMotionFunc(&GlutMouseAdapter::mouseMoved);
	}

	//Starts OpenGL Window
	void draw() {
		glutMainLoop();
	}

	//Title
	void setTitle(string n) override;
	string getTitle() override;

	//Position
	//MATH::Vector2<int> getPosition();

	int getX() override;
	int getY() override;

	////Size
	//MATH::Vector2<int> getDimensions();

	int getWidth() override;
	int getHeight() override;

	void print();

private:
	string title = "unset";

	//Initializes Display
	//Optional Implementation
	static void initDisplay() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glutSwapBuffers();
	}
};

#endif