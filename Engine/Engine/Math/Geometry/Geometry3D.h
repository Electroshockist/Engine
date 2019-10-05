#pragma once
#include "MathPrimitives.h"
namespace MATH {
	///		A Sphere could be thought of as a just a center point (x,y,z) 
	///		comes from Vector3 then just add a radius

	//template<
	//	typename T, //real type
	//	typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
	//>
	struct Sphere : public Vector3 {
		float r;
		Sphere(float s = 0.0f) { x = s; y = s; z = s; r = s; }

		Sphere(float _x, float _y, float _z, float _r) {
			x = _x; y = _y; z = _z; r = _r;
		}

		inline Sphere(const Sphere& v) {
			x = v.x;  y = v.y;  z = v.z; r = v.r;
		}

		inline void print() {
			printf("%f %f %f %f\n", x, y, z, r);
		}
	};

	///  T x,y,z; came from vector as the normal to the surface + distance to the surface (d) 
	//template<
	//	typename T //real type
	//	//typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
	//>
	struct Plane : public Vector3 {
		float d;

		/// Here's a set of constructors
		inline Plane(float _s = 0.0f) : Vector3(_s) {
			d = _s;
		}
		inline Plane(float _x, float _y, float _z, float _d) {
			x = _x;
			y = _y;
			z = _z;
			d = _d;
		}

		inline Plane(const Plane& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			d = v.d;
		}

		/// This creates a normalized equation of a plane.
		/// Important: See note 3.
		inline Plane(const Vector3& v0, const Vector3& v1, const Vector3& v2) {
			Vector3 a = v1 - v0;
			Vector3 b = v2 - v0;
			Vector3 n = Vector3(a.y * b.z - a.z * b.y, /// This is the cross product
				a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x);
			float magnitude = float(sqrt(n.x * n.x + n.y * n.y + n.z * n.z)); /// normalize

			Plane(x / magnitude, y / magnitude, z / magnitude, a.x * b.x + a.y * b.y + a.z * b.z);
		}


		/// Convert this plane into a normalized plane
		inline void normalize() {
			float a = sqrt(x*x + y * y + z * z);
			x /= a;
			y /= a;
			z /= a;
			d /= a;
		}
		inline void print() {
			printf("%f %f %f %f\n", x, y, z, d);
		}
	};

	struct Ray {
		// Starting position of ray
		Vector3 start;
		// Direction of ray
		Vector3 direction;

		inline Ray() {
			start = Vector3();
			direction = Vector3();
		}

		// Set the member variables of the ray
		inline Ray(Vector3 start, Vector3 direction) {
			this->start = start;
			this->direction = direction;
		}

		// Where are we along the Ray? 
		// Calculate position = start + dir * t
		inline Vector3 currentPosition(float t) {
			return (start + direction * t);
		}
	};
}