#ifndef IROTATABLE_2D
#define IROTATABLE_2D

#include <glm/glm.hpp>

//todo: set anchor
struct IRotatable2D {
	IRotatable2D(float rotation, glm::vec2  anchorPoint);

	void Rotate(float rotation);

	float rotation = 0;

protected:
	glm::vec2 anchorPoint;
};
#endif // !IROTATABLE_2D
