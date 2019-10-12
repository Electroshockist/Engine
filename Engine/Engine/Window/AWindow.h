#ifndef AWINDOW_H
#define AWINDOW_H

#include <string>
#include "..\Math\MathPrimitives.h"

using namespace std;

struct AWindow {
	//Title
	virtual void setTitle(string t) = 0;
	virtual string getTitle() = 0;

	//Position
	///position can only be set initially, therefore there are no setters for position

	//get window position
	virtual MATH::Vector2 getPosition() {
		return  MATH::Vector2(getX(), getY());
	};

	//get window X postition
	virtual int getX() = 0;
	//get window Y postition
	virtual int getY() = 0;

	//Size
	///Size can only be set initially, therefore there are no setters for size

	//get window size
	virtual MATH::Vector2 getDimensions() {
		return  MATH::Vector2(getWidth(), getHeight());
	};

	//get window hight
	virtual int getWidth() = 0;
	//get window width
	virtual int getHeight() = 0;

	virtual ~AWindow() {};

};
#endif