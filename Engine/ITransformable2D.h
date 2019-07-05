#pragma once
#include "ITranslatable2D.h"
#include "IRotatable2D.h"

struct ITransformable2D : public ITranslatable2D, public IRotatable2D {
	ITransformable2D(MATH::Vector2 position, float rotation, MATH::Vector2 anchorPoint);
};

