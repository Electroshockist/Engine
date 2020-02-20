#ifndef PARAMETER
#define PARAMETER

#include <variant>

#include <glm/glm.hpp>

struct Parameter{
	typedef std::variant<
		int, glm::vec<2, int>, glm::vec<3, int>, glm::vec<4, int>, glm::mat<2, 2, int>, glm::mat<2, 3, int>, glm::mat<2, 4, int>, glm::mat<3, 2, int>,
		glm::mat<3, 3, int>, glm::mat<3, 4, int>, glm::mat<4, 2, int>, glm::mat<4, 3, int>, glm::mat<4, 4, int>,

		float, glm::vec<2, float>, glm::vec<3, float>, glm::vec<4, float>, glm::mat<2, 2, float>, glm::mat<2, 3, float>, glm::mat<2, 4, float>, glm::mat<3, 2, float>,
		glm::mat<3, 3, float>, glm::mat<3, 4, float>, glm::mat<4, 2, float>, glm::mat<4, 3, float>, glm::mat<4, 4, float>,

		double, glm::vec<2, double>, glm::vec<3, double>, glm::vec<4, double>, glm::mat<2, 2, double>, glm::mat<2, 3, double>, glm::mat<2, 4, double>, glm::mat<3, 2, double>,
		glm::mat<3, 3, double>, glm::mat<3, 4, double>, glm::mat<4, 2, double>, glm::mat<4, 3, double>, glm::mat<4, 4, double>,

		unsigned int, glm::vec<2, unsigned int>, glm::vec<3, unsigned int>, glm::vec<4, unsigned int>, glm::mat<2, 2, unsigned int>, glm::mat<2, 3, unsigned int>, glm::mat<2, 4, unsigned int>, glm::mat<3, 2, unsigned int>,
		glm::mat<3, 3, unsigned int>, glm::mat<3, 4, unsigned int>, glm::mat<4, 2, unsigned int>, glm::mat<4, 3, unsigned int>, glm::mat<4, 4, unsigned int>
	> Data;

	std::string name;
	Data data;

	Parameter(std::string name, Data data){
		this->name = name;
		this->data = data;
	}

	enum Type{
		EMPTY,

		INT,
		INT2,
		INT3,
		INT4,
		INT2X2,
		INT3X3,
		INT4X4,
		INT2X3,
		INT3X2,
		INT2X4,
		INT4X2,
		INT3X4,
		INT4X3,

		UINT,
		UINT2,
		UINT3,
		UINT4,
		UINT2X2,
		UINT3X3,
		UINT4X4,
		UINT2X3,
		UINT3X2,
		UINT2X4,
		UINT4X2,
		UINT3X4,
		UINT4X3,

		FLOAT,
		FLOAT2,
		FLOAT3,
		FLOAT4,
		FLOAT2X2,
		FLOAT3X3,
		FLOAT4X4,
		FLOAT2X3,
		FLOAT3X2,
		FLOAT2X4,
		FLOAT4X2,
		FLOAT3X4,
		FLOAT4X3,

		DOUBLE,
		DOUBLE2,
		DOUBLE3,
		DOUBLE4,
		DOUBLE2X2,
		DOUBLE3X3,
		DOUBLE4X4,
		DOUBLE2X3,
		DOUBLE3X2,
		DOUBLE2X4,
		DOUBLE4X2,
		DOUBLE3X4,
		DOUBLE4X3
	}getType();
};

#endif // !PARAMETER

