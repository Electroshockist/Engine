#pragma once
#include "MathPrimitives.h"
struct IRotatable3D
{
	IRotatable3D(MATH::Vector3 rotation, MATH::Vector3 anchorPoint);
	~IRotatable3D();

private:
	MATH::Quaternion rotationQuaternion;
};

