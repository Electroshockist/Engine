#ifndef MATHPRIMITIVES_H
#define MATHPRIMITIVES_H
#include <string> /// Used for passing exceptions 
#include <type_traits>

#include "Math.h"
///
/// Vector3 definitions followed by Vector4 
/// a Plane plus a Sphere is added at the end just for fun.
/// There are notes at the bottom of this file you might want to read
///

namespace  MATH {

	//template<
	//	typename T //real type
	//	//typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
	//>
	struct Vector2 {
		float  x, y;	///  Structures are default public!

		/// Just a little utility to populate a vector
		inline void Load(float _x, float _y) {
			x = _x; y = _y;
		}

		/// Here's a set of constructors
		inline Vector2(float s = float(0.0)) {
			Load(s, s);
		}

		inline Vector2(float _x, float _y) {
			Load(_x, _y);
		}

		/// A copy constructor
		inline Vector2(const Vector2& v) {
			/// In this context "const" means I promise not to modify anything v points to 
			Load(v.x, v.y);
		}

		///////////////////////////////////////////////////////////
		/// Operator overloads (see note 1 at the end of this file)
		///////////////////////////////////////////////////////////

		/// An assignment operator   
		inline Vector2& operator = (const Vector2& v) {
			Load(v.x, v.y);
			return *this;
		}


		/// Now we can use the Vector3 like an array but we'll need two overloads
		inline const float operator [] (int index) const {  /// This one is for reading the Vector3 as if where an array
			return *(&x + index);
		}

		inline float& operator [] (int index) {	/// This one is for writing to the Vector3 as if where an array.  
			return *(&x + index);					/// See note 2 at the end of this file about lvalues and rvalues
		}


		/// Add two Vector3s
		inline const Vector2 operator + (const Vector2& v) const {
			return Vector2(x + v.x, y + v.y);
		}

		/// Add a Vector3 to itself
		inline Vector2& operator += (const Vector2& v) {
			x += v.x;
			y += v.y;
			return *this;
		}

		/// Take the negative of a Vector3
		inline const Vector2 operator - () const {
			return Vector2(-x, -y);
		}

		/// Subtract two Vector3s
		inline const Vector2 operator - (const Vector2& v) const {
			return Vector2(x - v.x, y - v.y);
		}

		/// Subtract a Vec 3 from itself
		inline Vector2& operator -= (const Vector2& v) {
			x -= v.x;
			y -= v.y;
			return *this;
		}

		/// Multiply a Vector3 by a scalar
		inline const Vector2  operator * (const float s) const {
			return Vector2(s*x, s*y);
		}


		/// Multiply a scaler by a Vector3  - Ha! It's the scalar first then the Vector3
		/// Overloaded and a friend, ouch! It's the only way to make it work with a scalar first.
		/// Friends are tricky, look them up. 
		inline friend Vector2 operator * (const float s, const Vector2& v) {
			return v * s;
		}

		/// Multiply a Vector3 by a scalar and assign it to itself
		inline Vector2& operator *= (const float s) {
			x *= s;
			y *= s;
			return *this;
		}


		/// Divide by a scalar - Watch for divide by zero issues
		inline const Vector2 operator / (const float s) const {
#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!! 
			if (fabs(s) < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				throw errorMsg;
			}
#endif
			float r = 1.0f / s;
			return *this * r;
		}


		inline Vector2& operator /= (const float s) {
#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!! 
			if (fabs(s) < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				throw errorMsg;
			}
#endif // DEBUG
			float r = 1.0f / s;
			*this *= r;
			return *this;
		}

		inline void print() {
			printf("%f %f\n", x, y);
		}

		///
		/// Type conversion operators 
		///
		inline operator const float* () const {
			return static_cast<const float*>(&x);
		}

		inline operator float* () {
			return static_cast<float*>(&x);
		}

	};

	//template<
	//	typename T //real type
	//	//typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
	//>
	struct Vector3 : public Vector2 {
		///T  x;	///
		///T  y;	///  //from Vector2

		float z;	///  Structures are default public!

		/// Just a little utility to populate a vector
		inline void Load(float _x, float _y, float _z) {
			Vector2::Load(_x, _y);
			z = _z;
		}

		/// Here's a set of constructors
		inline Vector3(float s = float(0.0)) {
			Load(s, s, s);
		}

		inline Vector3(float _x, float _y, float _z) {
			Load(_x, _y, _z);
		}

		/// A copy constructor
		inline Vector3(const Vector3& v) {
			/// In this context "const" means I promise not to modify anything v points to 
			Load(v.x, v.y, v.z);
		}

		///////////////////////////////////////////////////////////
		/// Operator overloads (see note 1 at the end of this file)
		///////////////////////////////////////////////////////////

		/// An assignment operator   
		inline Vector3& operator = (const Vector3& v) {
			Load(v.x, v.y, v.z);
			return *this;
		}


		/// Now we can use the Vector3 like an array but we'll need two overloads
		inline const float operator [] (int index) const {  /// This one is for reading the Vector3 as if where an array
			return *(&x + index);
		}

		inline float& operator [] (int index) {	/// This one is for writing to the Vector3 as if where an array.  
			return *(&x + index);					/// See note 2 at the end of this file about lvalues and rvalues
		}

		/// Add two Vector3s
		inline const Vector3 operator + (const Vector3& v) const {
			return Vector3(x + v.x, y + v.y, z + v.z);
		}

		/// Add a Vector3 to itself
		inline Vector3& operator += (const Vector3& v) {
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		/// Take the negative of a Vector3
		inline const Vector3 operator - () const {
			return Vector3(-x, -y, -z);
		}

		/// Subtract two Vector3s
		inline const Vector3 operator - (const Vector3& v) const {
			return Vector3(x - v.x, y - v.y, z - v.z);
		}

		/// Subtract a Vec 3 from itself
		inline Vector3& operator -= (const Vector3& v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}

		/// Multiply a Vector3 by a scalar
		inline const Vector3  operator * (const float s) const {
			return Vector3(s*x, s*y, s*z);
		}


		/// Multiply a scaler by a Vector3  - Ha! It's the scalar first then the Vector3
		/// Overloaded and a friend, ouch! It's the only way to make it work with a scalar first.
		/// Friends are tricky, look them up. 
		inline friend Vector3 operator * (const float s, const Vector3& v) {
			return v * s;
		}

		/// Multiply a Vector3 by a scalar and assign it to itself
		inline Vector3& operator *= (const float s) {
			x *= s;
			y *= s;
			z *= s;
			return *this;
		}


		/// Divide by a scalar - Watch for divide by zero issues
		inline const Vector3 operator / (const float s) const {
#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!! 
			if (fabs(s) < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				throw errorMsg;
			}
#endif
			float r = 1.0f / s;
			return *this * r;
		}


		inline Vector3& operator /= (const float s) {
#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!! 
			if (fabs(s) < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				throw errorMsg;
			}
#endif // DEBUG
			float r = 1.0f / s;
			*this *= r;
			return *this;
		}

		inline void print() {
			printf("%f %f %f\n", x, y, z);
		}

		///
		/// Type conversion operators 
		///
		inline operator const float* () const {
			return static_cast<const float*>(&x);
		}

		inline operator float* () {
			return static_cast<float*>(&x);
		}

	};


	/// Vector4 definitions
	/// I am intentionally creating a Vector4 from a Vector3 so I can pass a Vector4 into a Subroutine that wants a Vector3
	/// in many cases this will be mathamatically OK, just be careful Vector4's are not quaterinians

	//template<
	//	typename T, //real type
	//	typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
	//>

	struct Vector4 : public Vector3 {
		///T  x;	///
		///T  y;	///  
		///T  z;	/// From Vector3
		float  w;

		/// Here's a set of constructors
		inline Vector4(float s = float(0.0)) {
			x = s;
			y = s;
			z = s;
			w = s;
		}
		inline Vector4(float _x, float _y, float _z, float _w) {
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}

		inline Vector4(const Vector4& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
		}

		inline Vector4(const Vector3& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = 1.0f;
		}

		/// An assignment operator
		inline Vector4& operator = (const Vector4& v) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
			return *this;
		}

		/// See Vector3 definition 
		inline float& operator [] (int index) {
			return *(&x + index);
		}
		inline const float operator [] (int i) const {
			return *(&x + i);
		}

		/// See Vector3 definition 
		inline Vector4 operator + (const Vector4& v) const {
			return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
		}

		/// See Vector3 definition 
		inline Vector4& operator += (const Vector4& v) {
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;
			return *this;
		}

		//// See Vector3 definition 
		inline Vector4 operator - () const {
			return Vector4(-x, -y, -z, -w);
		}

		/// See Vector3 definition 
		inline Vector4 operator - (const Vector4& v) const {
			return Vector4(x - v.x, y - v.y, z - v.z, v.w - w);
		}

		/// See Vector3 definition 
		inline Vector4& operator -= (const Vector4& v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;
			return *this;
		}

		/// See Vector3 definition 
		inline Vector4 operator * (const float s) const {
			return Vector4(s*x, s*y, s*z, s*w);
		}

		/// See Vector3 definition 
		inline Vector4& operator *= (const float s) {
			x *= s;
			y *= s;
			z *= s;
			w *= s;
			return *this;
		}

		/// See Vector3 definition 
		friend Vector4 operator * (const float s, const Vector4& v) {
			return v * s;
		}


		inline Vector4 operator / (const float s) const {
#ifdef DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!! 
			if (std::fabs(s) < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				throw errorMsg;
			}
#endif
			float r = 1.0f / s;
			return *this * r;
		}

		inline Vector4& operator /= (const float s) {
#ifdef _DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!! 
			if (fabs(s) < VERY_SMALL) {
				std::string errorMsg("Divide by nearly zero! ");
				throw errorMsg;
			}
#endif // DEBUG

			float r = 1.0f / s;
			*this *= r;
			return *this;
		}

		inline void print() {
			printf("%f %f %f %f\n", x, y, z, w);
		}

		///
		/// Type conversion operators 
		///
		inline operator const float* () const {
			return static_cast<const float*>(&x);
		}

		inline operator float* () {
			return static_cast<float*>(&x);
		}

	};
	/// Ability to call Vector4 Quaternion
	typedef Vector4 Quaternion;


	/// Just some extra stuff for fun


	/// A solution to the circular dependency problem.  
	/// This is what is called a "forward declaration."
	/// See note 3 at the bottom of this page.

	//template<
	//	typename T //real type
	//	//typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
	//>
	class VectorMath;
}
#endif


/*** Note 1.
I know, I hate operator overloading as a general rule but a few make sense!! Just be careful and
consistent. In the following code, I will overload many operators. I don't believe in
overloading when the operator is less than obvious.
For example, in this class, the relational operators (== != < > <= >=) might mean "in relation
to their magnitude or direction" I'm just not sure. Just write a function to do that and don't make
me guess what the operator might mean. Use the idea of "Least Astonishment" don't surprise me,
or shock me or anything else that will piss me or others off-SSF
***/

/*** Note 2.
In straight C programming, lvalues and rvalues literially means left and right assignments.  For example,
int x = 5; x is the lvalue and 5 is the rvalue. Easy. In C++ it get a bit more tricky. The modern idea is
rvalues are temporary vaules residing in the registers of the CPU. lvalues are actual memory locations.
In the code:
	inline float& operator [] ( int index ) {
		return *(&x + index);
	}
To read this precicely, &x is the address of the x variable (the first in the list of x,y,z) add to that
address the index as if it were an array. Then *(&x + index) dereferences that address back into the
object, the float& reference returns it as an address and thus an lvalue.
***/

/*** Note 3.
The issue here is that I need to use functions in Vector from VMath which require Vector but VMath
also requires Vector - this is a classic circular dependency problem or sometimes known as mutual recursion.
To solve this it requires a forward declaration.  A "forward declaration" is the declaration of a class for which
the you have not yet given a complete definition of (whateverClass.h). To do this all you need is the statement:
"class VMath;"  This warns the compiler that I will be using VMath in Vector; HOWEVER, in this case, it won't work because
I'm using the vector.h as a totally inlined set of functions - sometimes your just screwed
***/