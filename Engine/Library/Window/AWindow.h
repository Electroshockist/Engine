#ifndef AWINDOW_H
#define AWINDOW_H

#include <string>
#include "..\Math\MathPrimitives.h"
#include <iostream>

using namespace std;

struct AWindow {
	AWindow() {}

	inline void onCreate(string title, int x, int y, int width, int height) {		
		this->title = &title;
		this->x = &x;
		this->y = &y;
		this->width = &width;
		this->height = &height;
	}

	//Title
	virtual void setTitle(string* t) { title = t; };
	inline string* getTitle() { return title; };

	//Position
	///position can only be set initially, therefore there are no setters for position

	//get window position
	virtual MATH::Vector2 getPosition() {
		return  MATH::Vector2(*getX(), *getY());
	};

	//get window X postition
	inline int* getX() { return x; };
	//get window Y postition
	inline int* getY() { return y; };

	//Size
	///Size can only be set initially, therefore there are no setters for size

	//get window size
	virtual MATH::Vector2 getDimensions() {
		return  MATH::Vector2(*getWidth(), *getHeight());
	};

	//get window hight
	inline int* getWidth() { return width; };
	//get window width
	inline int* getHeight() { return height; };

	virtual ~AWindow() {
		delete title, x, y, width, height;
		title = nullptr;
		x = y = width = height = nullptr;
		std::cout << "delete please" << std::endl;
	};

private:
	string* title;
	int *x, *y, *width, *height;
};
#endif