#include "ITransformable2D.h"

ITransformable2D::ITransformable2D(glm::vec2 position, float rotation, glm::vec2 anchorPoint): ITranslatable2D(position), IRotatable2D(rotation, anchorPoint) {}
