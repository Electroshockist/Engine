#ifndef AWINDOW_H
#define AWINDOW_H

#include <string>
#include "..\Math\MathPrimitives.h"

using namespace std;

struct AWindow {
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
	inline int* getWidth() { return w; };
	//get window width
	inline int* getHeight() { return h; };

	virtual ~AWindow() {
		delete title, x, y, w, h;
		title = nullptr;
		x = y = w = h = nullptr;
	};

private:
	string* title;
	int *x, *y, *w, *h;

};
#endif