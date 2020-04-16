#ifndef PARAMETER_H
#define PARAMETER_H

#include <variant>

#include <glm/glm.hpp>

struct Parameter{
	typedef std::variant<
		int, glm::vec<2, int>, glm::vec<3, int>, glm::vec<4, int>,
		unsigned int, glm::vec<2, unsigned int>, glm::vec<3, unsigned int>, glm::vec<4, unsigned int>,
		float, glm::vec<2, float>, glm::vec<3, float>, glm::vec<4, float>,
		double, glm::vec<2, double>, glm::vec<3, double>, glm::vec<4, double>
	> Data;

	Data data;

	Parameter(){}

	Parameter(Data data){
		this->data = data;
	}

	enum Type{
		EMPTY,

		INT,
		INT2,
		INT3,
		INT4,

		UINT,
		UINT2,
		UINT3,
		UINT4,

		FLOAT,
		FLOAT2,
		FLOAT3,
		FLOAT4,

		DOUBLE,
		DOUBLE2,
		DOUBLE3,
		DOUBLE4,
	}getType();
};

#endif // !PARAMETER

