#include "UniformParameter.h"

#include "../../Debugging/Debug.h"
#include "GLEW/glew.h"

using namespace std;
using namespace glm;

UniformParameter::UniformParameter() : location(0), nameInShader(""), parameter(Parameter()){}

UniformParameter::UniformParameter(unsigned int shaderProgram, string nameInShader, Parameter parameter){
	this->location = glGetUniformLocation(shaderProgram, nameInShader.c_str());
	this->nameInShader = nameInShader;
	this->parameter = parameter;
}

void UniformParameter::Setup(string name){
	try{
		Parameter::Type type = parameter.getType();
		Parameter::Data &data = parameter.data;

		switch(type){
			case Parameter::Type::EMPTY:
				Debug::warning("Material parameter with name " + name + " is empty.", __FILE__, __LINE__);
				break;
			case Parameter::Type::INT:
				glUniform1i(location, get<int>(data));
				break;
			case Parameter::Type::INT2:
				vec<2, int> vec2i = get<vec<2, int>>(data);
				glUniform2i(location, vec2i.x, vec2i.y);
				break;
			case Parameter::Type::INT3:
				vec<3, int> vec3i = get<vec<3, int>>(data);
				glUniform3i(location, vec3i.x, vec3i.y, vec3i.z);
				break;
			case Parameter::Type::INT4:
				vec<4, int> vec4i = get<vec<4, int>>(data);
				glUniform4i(location, vec4i.x, vec4i.y, vec4i.z, vec4i.w);
				break;
			case Parameter::Type::UINT:
				glUniform1ui(location, get<GLuint>(data));
				break;
			case Parameter::Type::UINT2:
				vec<2, GLuint> vec2ui = get<vec<2, GLuint>>(data);
				glUniform2ui(location, vec2ui.x, vec2ui.y);
				break;
			case Parameter::Type::UINT3:
				vec<3, GLuint> vec3ui = get<vec<3, GLuint>>(data);
				glUniform3ui(location, vec3ui.x, vec3ui.y, vec3ui.z);
				break;
			case Parameter::Type::UINT4:
				vec<4, GLuint> vec4ui = get<vec<4, GLuint>>(data);
				glUniform4ui(location, vec4ui.x, vec4ui.y, vec4ui.z, vec4ui.w);
				break;
			case Parameter::Type::FLOAT:
				glUniform1f(location, get<GLuint>(data));
				break;
			case Parameter::Type::FLOAT2:
				vec<2, GLuint> vec2f = get<vec<2, GLuint>>(data);
				glUniform2f(location, vec2f.x, vec2f.y);
				break;
			case Parameter::Type::FLOAT3:
				vec<3, GLuint> vec3f = get<vec<3, GLuint>>(data);
				glUniform3f(location, vec3f.x, vec3f.y, vec3f.z);
				break;
			case Parameter::Type::FLOAT4:
				vec<4, GLuint> vec4f = get<vec<4, GLuint>>(data);
				glUniform4f(location, vec4f.x, vec4f.y, vec4f.z, vec4f.w);
				break;
			case Parameter::Type::DOUBLE:
				glUniform1d(location, get<GLuint>(data));
				break;
			case Parameter::Type::DOUBLE2:
				vec<2, GLuint> vec2d = get<vec<2, GLuint>>(data);
				glUniform2d(location, vec2d.x, vec2d.y);
				break;
			case Parameter::Type::DOUBLE3:
				vec<3, GLuint> vec3d = get<vec<3, GLuint>>(data);
				glUniform3d(location, vec3d.x, vec3d.y, vec3d.z);
				break;
			case Parameter::Type::DOUBLE4:
				vec<4, GLuint> vec4d = get<vec<4, GLuint>>(data);
				glUniform4d(location, vec4d.x, vec4d.y, vec4d.z, vec4d.w);
				break;

			default:
				Debug::error("Material parameter with name " + name + " does not exist. This error should never occur.", __FILE__, __LINE__);
				break;
		}
	} catch(const bad_variant_access & e){
		Debug::error("Improper variant cast at parameter with name" + name + "." + e.what() + " This error should never occur.", __FILE__, __LINE__);
	}
}

UniformParameter::~UniformParameter(){}
