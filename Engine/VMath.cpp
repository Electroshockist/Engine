#include "pch.h"
#include "VMath.h"
#include <type_traits>
using namespace MATH;

//template<
//	typename T //real type
//>
Vector3 VMath::reflect(const Vector3 &v, const Vector3 &n) {
	Vector3 result;
	float scalar = 2.0f * dot(v, n);
	Vector3 temp = n * scalar;
	result = temp - v;
	return result;
}

//template<
//	typename T //real type
//>
Vector3 VMath::reflect(const Vector3 &v, const Plane &p) {
	Vector3 result;
	float scalar = 2.0f * dot(v, p);
	Vector3 temp = p * scalar;
	result = temp - v;
	return result;
}

/***
Vector3 VMath::reflect2(const Vector3 &v, const Plane &p){
	Vector3 result;
	float length  = mag(v);
	Vector3 n = v / length;
	float scalar = 2.0f * dot(n,p);
	Vector3 temp = p * scalar;
	result = temp - v;
	result  = result *  length;
	return result;
}
***/

//template<
//	typename T //real type
//>
float VMath::distance(const Vector3 &a, const Vector3 &b) {
	Vector3 r = a - b;
	return(mag(r));
}

//template<
//	typename T //real type
//>
float VMath::distance(const Vector3 &v, const Plane &p) {
	return v.x*p.x + v.y*p.y + v.z*p.z - p.d;
}

//template<
//	typename T //real type
//>
float VMath::distance(const Sphere &s, const Plane &p) {
	return distance((Vector3)s, p) - s.r;
}
