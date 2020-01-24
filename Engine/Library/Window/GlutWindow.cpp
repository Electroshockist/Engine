#include <iostream>
#include "GlutWindow.h"

GlutWindow::GlutWindow(string title, int X, int Y, int width, int height) {
	AWindow::SetTitle(&title);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(X, Y);
	glutInitWindowSize(width, height);
	glutCreateWindow(title.c_str());
	glutDisplayFunc(GlutWindow::InitDisplay);
}

void GlutWindow::SetTitle(string* title) {
	AWindow::SetTitle(title);
	glutSetWindowTitle(title->c_str());
}

void GlutWindow::Print() {
	std::cout << "Title: " << GetTitle() << "\nPosition: [" << GetX() << ", " << GetY() << "]\nSize: [" << GetWidth() << ", " <<GetHeight() << "]\n";
}

