#ifndef GLUTWINDOW_H
#define GLUTWINDOW_H

#include "../Window/AWindow.h"
#include "../Input/MouseAdapter.h"

//Depreciated
struct GlutWindow : public AWindow {
	GlutWindow(string title, int X, int Y, int width, int height);

	//Implements functionality for mouse button click an mouse motion
	void AddEventListener(string event) {
		if(event == MouseEvent::MOUSE_PRESSED)
			glutMouseFunc(&MouseAdapter::MouseClicked);
		else if(event == MouseEvent::MOUSE_MOVED)
			glutMotionFunc(&MouseAdapter::MouseMoved);
	}

	//Starts OpenGL Window
	void Draw() {
		glutMainLoop();
	}

	//Title
	void SetTitle(string* n) override;

	void Print();

	virtual ~GlutWindow() {}

private:
	//Initializes Display
	//Optional Implementation
	static void InitDisplay() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glutSwapBuffers();
	}
};

#endif