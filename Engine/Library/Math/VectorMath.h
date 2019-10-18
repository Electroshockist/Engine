#ifndef VMATH_H
#define VMATH_H

#include <type_traits>

#include <math.h>
#include <stdio.h>

/// This is a library of Vector3 math routines. 
#include "MathPrimitives.h"
#include "Geometry\Geometry.h"

namespace MATH {

	//template<
	//	typename T //real type
	//	//typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
	//>
	class VectorMath {

	public:
		/// Calculate the dot product between Vector3s a & b 
		inline static float dot(const Vector3 &a, const Vector3 &b) {
			return(a.x * b.x + a.y * b.y + a.z * b.z);
		}

		/// Calulate the cross product
		inline static const Vector3 cross(const Vector3 &a, const Vector3 &b) {
			return Vector3(a.y * b.z - a.z * b.y,
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x);
		}

		/// Return a normalized Vector3
		inline static Vector3 normalize(const Vector3 &a) {
			float magnitude;
			Vector3 result;
			magnitude = float(sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!! 
			if (magnitude < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				throw errorMsg;
			}
#endif
			result.x = a.x / magnitude;
			result.y = a.y / magnitude;
			result.z = a.z / magnitude;
			return result;
		}

		inline static float mag(const Vector3 &a) {
			return(sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
		}

		///  Angle-Axis rotation
		inline static Vector3 rotate(const Vector3 &n, float theta, const Vector3 &v) {
			return v * cos(theta) + VectorMath::dot(v, n) * n * (1.0f - cos(theta)) + VectorMath::cross(n, v) * sin(theta);
		}

		////////////////////////////////////////////////////////////////////////		
		/// These are a little more complex so I won't inline them
		////////////////////////////////////////////////////////////////////////
		/// Reflect off a normal  
		static Vector3 reflect(const Vector3 &v, const Vector3 &n);

		/// Reflect a normalized direction Vector3 off a plane 
		static Vector3 reflect(const Vector3 &v, const Plane &p);

		/// Reflect a velocity Vector3 off a plane maintaining the original magnitude (velocity) 
		static Vector3 reflectUnnormal(const Vector3 &v, const Plane &p);

		/// Get the distance between two Vector3s 
		static float distance(const Vector3 &a, const Vector3 &b);

		/// Get the distance between a point (Vector3) and a plane 
		static float distance(const Vector3 &v, const Plane &p);

		/// Get the distance between a sphere and a plane
		static float distance(const Sphere &s, const Plane &p);
	};
}

#endif