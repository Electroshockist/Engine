#pragma once
#include "MathPrimitives.h"

//todo: set anchor
struct IRotatable2D {
	IRotatable2D(float rotation, MATH::Vector2  anchorPoint);

	void rotate(float rotation);

	float rotation = 0;

private:
	MATH::Vector2 anchorPoint;
};
