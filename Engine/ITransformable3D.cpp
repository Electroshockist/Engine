#include "pch.h"
#include "ITransformable3D.h"

ITransformable3D::ITransformable3D(MATH::Vector3 position, MATH::Vector3 rotation, MATH::Vector3 anchorPoint) :
	ITranslatable3D(position),
	IRotatable3D(rotation, anchorPoint) {}
