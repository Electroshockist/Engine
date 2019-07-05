#pragma once
#include "MathPrimitives.h"

struct ITranslatable3D {
	MATH::Vector3 position;
	ITranslatable3D(MATH::Vector3 position);
};
