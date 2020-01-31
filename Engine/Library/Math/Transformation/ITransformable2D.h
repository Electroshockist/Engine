#ifndef ITRANSFORMABLE2D_H
#define ITRANSFORMABLE2D_H

#include "ITranslatable2D.h"
#include "IRotatable2D.h"

struct ITransformable2D : public ITranslatable2D, public IRotatable2D {
	ITransformable2D(glm::vec2 position, float rotation, glm::vec2 anchorPoint);
};
#endif // !ITRANSFORMABLE2D_H

