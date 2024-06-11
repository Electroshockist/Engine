#include "Rectangle.h"



Rectangle::Rectangle(){}

Rectangle::Rectangle(glm::vec2 position, glm::vec2 size){
	this->position = position;
	this->size = size;
}


Rectangle::~Rectangle(){}
