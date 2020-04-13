#ifndef AWINDOW_H
#define AWINDOW_H

#include <string>
#include <iostream>
#include <glm/glm.hpp>

using namespace std;

struct AWindow{
	AWindow() : title(""), x(0), y(0), width(0), height(0){}

	inline void OnCreate(string title, int x, int y, int width, int height){
		this->title = title;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	//Title
	virtual void SetTitle(const string t){ title = t; };
	inline const string& GetTitle() const{ return title; };

	//Position
	///position can only be set initially, therefore there are no setters for position

	//get window position
	inline virtual glm::vec2 GetPosition() const{
		return glm::vec2(GetX(), GetY());
	};

	//get window X postition
	const inline int& GetX() const{ return x; };
	//get window Y postition
	const inline int& GetY() const{ return y; };

	//Size
	///Size can only be set initially, therefore there are no setters for size

	//get window size
	inline virtual glm::vec2 getDimensions() const{
		return glm::vec2(GetWidth(), GetHeight());
	};

	//get window hight
	const inline int& GetWidth() const{ return width; };
	//get window width
	const inline int& GetHeight() const{ return height; };

	virtual ~AWindow(){};

private:
	string title;
	int x, y, width, height;
};
#endif