#include "UniformParameter.h"

#include "../../Debugging/Debug.h"
#include "GLEW/glew.h"


UniformParameter::UniformParameter() : location(0), nameInShader(nullptr), parameter(Parameter()){}

UniformParameter::UniformParameter(unsigned int &location, char nameInShader[], Parameter parameter){
	this->location = location;
	this->nameInShader = nameInShader;
	this->parameter = parameter;
}

void UniformParameter::Setup(std::string name){
	try{
		Parameter::Type type = parameter.getType();
		Parameter::Data &data = parameter.data;

		switch(type){
			case Parameter::Type::EMPTY:
				Debug::warning("Material parameter with name " + name + " is empty.", __FILE__, __LINE__);
				break;
			case Parameter::Type::INT:
				glUniform1i(location, std::get<int>(data));
				break;
			case Parameter::Type::INT2:
				glm::vec<2, int> vec2i = std::get<glm::vec<2, int>>(data);
				glUniform2i(location, vec2i.x, vec2i.y);
				break;
			case Parameter::Type::INT3:
				glm::vec<3, int> vec3i = std::get<glm::vec<3, int>>(data);
				glUniform3i(location, vec3i.x, vec3i.y, vec3i.z);
				break;
			case Parameter::Type::INT4:
				glm::vec<4, int> vec4i = std::get<glm::vec<4, int>>(data);
				glUniform4i(location, vec4i.x, vec4i.y, vec4i.z, vec4i.w);
				break;
			case Parameter::Type::UINT:
				glUniform1ui(location, std::get<GLuint>(data));
				break;
			case Parameter::Type::UINT2:
				glm::vec<2, unsigned int> vec2ui = std::get<glm::vec<2, unsigned int>>(data);
				glUniform2ui(location, vec2ui.x, vec2ui.y);
				break;
			case Parameter::Type::UINT3:
				glm::vec<3, unsigned int> vec3ui = std::get<glm::vec<3, unsigned int>>(data);
				glUniform3ui(location, vec3ui.x, vec3ui.y, vec3ui.z);
				break;
			case Parameter::Type::UINT4:
				glm::vec<4, unsigned int> vec4ui = std::get<glm::vec<4, unsigned int>>(data);
				glUniform4ui(location, vec4ui.x, vec4ui.y, vec4ui.z, vec4ui.w);
				break;
			case Parameter::Type::FLOAT:
				glUniform1f(location, std::get<GLuint>(data));
				break;
			case Parameter::Type::FLOAT2:
				glm::vec<2, unsigned int> vec2f = std::get<glm::vec<2, unsigned int>>(data);
				glUniform2f(location, vec2f.x, vec2f.y);
				break;
			case Parameter::Type::FLOAT3:
				glm::vec<3, unsigned int> vec3f = std::get<glm::vec<3, unsigned int>>(data);
				glUniform3f(location, vec3f.x, vec3f.y, vec3f.z);
				break;
			case Parameter::Type::FLOAT4:
				glm::vec<4, unsigned int> vec4f = std::get<glm::vec<4, unsigned int>>(data);
				glUniform4f(location, vec4f.x, vec4f.y, vec4f.z, vec4f.w);
				break;
			case Parameter::Type::DOUBLE:
				glUniform1d(location, std::get<GLuint>(data));
				break;
			case Parameter::Type::DOUBLE2:
				glm::vec<2, unsigned int> vec2d = std::get<glm::vec<2, unsigned int>>(data);
				glUniform2d(location, vec2d.x, vec2d.y);
				break;
			case Parameter::Type::DOUBLE3:
				glm::vec<3, unsigned int> vec3d = std::get<glm::vec<3, unsigned int>>(data);
				glUniform3d(location, vec3d.x, vec3d.y, vec3d.z);
				break;
			case Parameter::Type::DOUBLE4:
				glm::vec<4, unsigned int> vec4d = std::get<glm::vec<4, unsigned int>>(data);
				glUniform4d(location, vec4d.x, vec4d.y, vec4d.z, vec4d.w);
				break;

			default:
				Debug::error("Material parameter with name " + name + " does not exist. This error should never occur.", __FILE__, __LINE__);
				break;
		}
	} catch(const std::bad_variant_access & e){
		Debug::error("Improper variant cast at parameter with name" + name + "." + e.what() + " This error should never occur.", __FILE__, __LINE__);
	}
}

UniformParameter::~UniformParameter(){
	delete nameInShader;
	nameInShader = nullptr;
}
