#pragma once
#ifndef GLUTWINDOW_H
#define GLUTWINDOW_H

#include "AWindow.h"
#include "MouseAdapter.h"

struct GlutWindow : public AWindow {
	GlutWindow(string title, int X, int Y, int width, int height);

	//Implements functionality for mouse button click an mouse motion
	void addEventListener(string event){
		if (event == MouseEvent::MOUSE_PRESSED)
			glutMouseFunc(&MouseAdapter::mouseClicked);
		else if (event == MouseEvent::MOUSE_MOVED)
			glutMotionFunc(&MouseAdapter::mouseMoved);
	}

	//Starts OpenGL Window
	void draw() {
		glutMainLoop();
	}

	//Title
	void setTitle(string n) override;
	string getTitle() override;

	//Position
	int getX() override;
	int getY() override;

	//Size
	int getWidth() override;
	int getHeight() override;

	void print();

	virtual ~GlutWindow() {}

private:
	string title;

	//Initializes Display
	//Optional Implementation
	static void initDisplay() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glutSwapBuffers();
	}
};

#endif