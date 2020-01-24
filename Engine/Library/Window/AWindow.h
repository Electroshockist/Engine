#ifndef AWINDOW_H
#define AWINDOW_H

#include <string>
#include "..\Math\MathPrimitives.h"
#include <iostream>

using namespace std;

struct AWindow {
	AWindow() {}

	inline void OnCreate(string title, int x, int y, int width, int height) {		
		this->title = &title;
		this->x = &x;
		this->y = &y;
		this->width = &width;
		this->height = &height;
	}

	//Title
	virtual void SetTitle(string* t) { title = t; };
	inline string* GetTitle() { return title; };

	//Position
	///position can only be set initially, therefore there are no setters for position

	//get window position
	virtual MATH::Vector2 GetPosition() {
		return  MATH::Vector2(*GetX(), *GetY());
	};

	//get window X postition
	inline int* GetX() { return x; };
	//get window Y postition
	inline int* GetY() { return y; };

	//Size
	///Size can only be set initially, therefore there are no setters for size

	//get window size
	virtual MATH::Vector2 GetDimensions() {
		return  MATH::Vector2(*GetWidth(), *GetHeight());
	};

	//get window hight
	inline int* GetWidth() { return width; };
	//get window width
	inline int* GetHeight() { return height; };

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