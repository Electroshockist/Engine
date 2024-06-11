#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <glm/glm.hpp>
#include <SDL/SDL_image.h>

struct Rectangle{ 
	Rectangle();
	Rectangle(glm::vec2 position, glm::vec2 size);

	~Rectangle();

protected:
	glm::vec2 position;
	glm::vec2 size;
};

#endif // !RECTANGLE_H