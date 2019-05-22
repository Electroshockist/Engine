#ifndef AWINDOW_H
#define AWINDOW_H

#include <string>
#include "MathPrimitives.h"

using namespace std;

class AWindow {
public:
	//Title
	virtual void setTitle(string n) = 0;
	virtual string getTitle() = 0;

	//Position
	///position can only be set initially, therefore there are no setters for position
	virtual MATH::Vector2 getPosition() {
		return  MATH::Vector2(getX(), getY());
	};

	virtual int getX() = 0;
	virtual int getY() = 0;

	//Size
	///Size can only be set initially, therefore there are no setters for size
	virtual MATH::Vector2 getDimensions() {
		return  MATH::Vector2(getWidth(), getHeight());
	};

	virtual int getWidth() = 0;
	virtual int getHeight() = 0;

	virtual void addEventListener(string event) = 0;

	virtual ~AWindow() {};

};
#endif