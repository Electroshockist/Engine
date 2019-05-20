#include "pch.h"

#include <iostream>

#include "GlutWindow.h"

GlutWindow::GlutWindow(string _title, int X, int Y, int width, int height) {
	title = _title;
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(X, Y);
	glutInitWindowSize(width, height);
	glutCreateWindow(title.c_str());
	glutDisplayFunc(GlutWindow::initDisplay);
}

void GlutWindow::setTitle(string _title) {
	title = _title;
	glutSetWindowTitle(_title.c_str());
}

string GlutWindow::getTitle() {
	return title;
}

//MATH::Vector2<int> GlutWindow::getPosition() {
//	return MATH::Vector2<int>(getX(), getY());
//}

int GlutWindow::getX() {
	return glutGet(GLUT_WINDOW_X);
}

int GlutWindow::getY() {
	return glutGet(GLUT_WINDOW_Y);
}

//MATH::Vector2<int> GlutWindow::getDimensions() {
//	return MATH::Vector2<int>(getWidth(), getHeight());
//}

int GlutWindow::getWidth() {
	return glutGet(GLUT_WINDOW_WIDTH);
}

int GlutWindow::getHeight() {
	return glutGet(GLUT_WINDOW_HEIGHT);
}

void GlutWindow::print() {
	std::cout << "Title: " << getTitle() << "\nPosition: [" << getX() << ", " << getY() << "]\nSize: [" << getWidth() << ", " <<getHeight() << "] ";
}

