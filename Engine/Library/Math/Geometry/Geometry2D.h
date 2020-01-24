#ifndef GEOMETRY2D_H
#define GEOMETRY2D_H


#include "../Transformation/ITransformable2D.h"

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

	struct Rectangle : public Square {
		float width;
	};
}
#endif // !GEOMETRY2D_H