#include "pch.h"
#include "ITransformable2D.h"

ITransformable2D::ITransformable2D(MATH::Vector2 position, float rotation, MATH::Vector2 anchorPoint): ITranslatable2D(position), IRotatable2D(rotation, anchorPoint) {}
