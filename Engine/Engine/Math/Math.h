#ifndef MATH_H
#define MATH_H

#include <math.h>

namespace  MATH {
	/// This is used in normalizing vectors. Dividing by zero is a well known
	/// problem but dividing by nearly zero is also a problem. 1.0x10-7 is very
	/// small in "float" percision. 
	#ifndef VERY_SMALL
	#define VERY_SMALL 1.0e-7f
	#endif

	#ifndef PI
	#define PI 3.14159265358979323846f
	#endif

	#ifndef DEGREES_TO_RADIANS
	#define DEGREES_TO_RADIANS (PI / 180.0f)
	#endif

	struct FloatSafe {
		inline static float checkFloat(float f) {
			if (abs(f) > VERY_SMALL) return f;
			return 0;
		}

		//get absolute cos value and check if it's too small for a float to hold correctly
		inline static float cos(float angle) {
			return checkFloat(cos(angle));
		}

		//get absolute sin value and check if it's too small for a float to hold correctly
		inline static float sin(float angle) {
			return checkFloat(sin(angle));
		}
	};
}

#endif