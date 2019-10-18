#include <iostream>
#include "GlutWindow.h"

GlutWindow::GlutWindow(string title, int X, int Y, int width, int height) {
	AWindow::setTitle(&title);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(X, Y);
	glutInitWindowSize(width, height);
	glutCreateWindow(title.c_str());
	glutDisplayFunc(GlutWindow::initDisplay);
}

void GlutWindow::setTitle(string* title) {
	AWindow::setTitle(title);
	glutSetWindowTitle(title->c_str());
}

void GlutWindow::print() {
	std::cout << "Title: " << getTitle() << "\nPosition: [" << getX() << ", " << getY() << "]\nSize: [" << getWidth() << ", " <<getHeight() << "]\n";
}

