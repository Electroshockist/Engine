#include "Material.h"
#include <GLEW/glew.h>

void Material::setupParameter(const std::string name, ParameterPair &parameterPair){
	try{
		Parameter::Type type = parameterPair.second.getType();
		Parameter::Data &data = parameterPair.second.data;
		unsigned int &location = parameterPair.first;

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
				glm::vec<4, int> vec3i = std::get<glm::vec<4, int>>(data);
				glUniform3i(location, vec3i.x, vec3i.y, vec3i.z);
				break;
			case Parameter::Type::UINT:
				glUniform1ui(location, std::get<GLuint>(data));
				break;


			default:
				Debug::error("Material parameter with name " + name + " does not exist. This error should never occur.", __FILE__, __LINE__);
				break;
		}
	} catch(const std::bad_variant_access & e){
		Debug::error("Improper variant cast at parameter with name" + name + "." + e.what() + " This error should never occur.", __FILE__, __LINE__);
	}
}

void Material::setupParameter(const std::string name, ParameterPair &parameterPair){}
