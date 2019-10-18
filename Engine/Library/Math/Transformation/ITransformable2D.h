#ifndef ITRANSFORMABLE2D_H
#define ITRANSFORMABLE2D_H

#include "ITranslatable2D.h"
#include "IRotatable2D.h"

struct ITransformable2D : public ITranslatable2D, public IRotatable2D {
	ITransformable2D(MATH::Vector2 position, float rotation, MATH::Vector2 anchorPoint);
};
#endif // !ITRANSFORMABLE2D_H

