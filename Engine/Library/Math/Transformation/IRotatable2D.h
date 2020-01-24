#ifndef IROTATABLE_2D
#define IROTATABLE_2D

#include "../MathPrimitives.h"

//todo: set anchor
struct IRotatable2D {
	IRotatable2D(float rotation, MATH::Vector2  anchorPoint);

	void Rotate(float rotation);

	float rotation = 0;

private:
	MATH::Vector2 anchorPoint;
};
#endif // !IROTATABLE_2D
