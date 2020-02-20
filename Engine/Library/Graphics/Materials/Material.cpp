#include "Material.h"
#include <GLEW/glew.h>

void Material::setupParameter(const std::string name, ParameterPair &parameterPair){
	try{
		Parameter::Type type = parameterPair.second.getType();
		Parameter::Data &data = parameterPair.second.data;
		unsigned int &location = parameterPair.first;

		switch(data.index()){
			case 0:
				Debug::warning("Material parameter with name " + name + " is empty.", __FILE__, __LINE__);
				break;
			case 1:
				glUniform1i(location, std::get<int>(data));

			default:
				Debug::error("Material parameter with name " + name + " does not exist. This error should never occur.", __FILE__, __LINE__);
				break;
		}
	} catch(const std::bad_variant_access & e){
		Debug::error("Improper variant cast at parameter with name" + name + "." + e.what() + " This error should never occur.", __FILE__, __LINE__);
	}
}

void Material::setupParameter(const std::string name, ParameterPair &parameterPair){}
