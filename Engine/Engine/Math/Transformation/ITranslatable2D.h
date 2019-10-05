#ifndef ITRANSLATABLE2D_H
#define ITRANSLATABLE2D_H

#include "../MathPrimitives.h"

struct ITranslatable2D {
	MATH::Vector2 position;
	ITranslatable2D(MATH::Vector2 position);
};
#endif // !ITRANSLATABLE2D_H
