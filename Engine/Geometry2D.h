#pragma once
#include "ITransformable2D.h"

namespace MATH {

	struct Shape : ITranslatable2D {

	};

	struct Polygon : ITransformable2D {

	};

	struct Circle : public Shape {
		float radius;
	};

	struct Square : public Shape {
		float length;
	};

	struct Rectangle : public Square{
		float length, width;

	};
}
