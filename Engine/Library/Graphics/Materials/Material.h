#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <map>
#include <variant>

#include <glm/glm.hpp>

#include "../../Debugging/Debug.h"

struct Material{
	typedef std::variant<int, unsigned int, double, float, glm::vec2, glm::vec3, glm::vec4> Parameter;

	Material(){}

	Material(std::string name, Parameter parameter){
		AddParameter(name, parameter);
	}

	void AddParameter(std::string name, Parameter parameter){
		parameters[name] = parameter;
	}

	Parameter *getParameter(std::string name){
		return &parameters.at(name);
	}

	void setupParameters(){
		if(parameters.empty()){
			Debug::warning("No material parameters exist.", __FILE__, __LINE__);
			return;
		}

		for(auto const& x : parameters){
			setupParameter(x);
		}
	}

private:
	typedef std::map<std::string, Parameter> Parameters;
	Parameters parameters;

	void setupParameter(std::pair<std::string, Parameter> parameterPair){
		try{
			switch(parameterPair.second.index()){
				case 0:
					Debug::warning("Material parameter with name " + parameterPair.first + " is empty.", __FILE__, __LINE__);
					break;
				case 1:
					glUniform1i
					break;
				default:
					Debug::error("Material parameter with name " + parameterPair.first + " does not exist. This error should never occur.", __FILE__, __LINE__);
					break;
			}
		}
		catch(const std::bad_variant_access& e){
			Debug::error("Improper variant cast at parameter with name" + parameterPair.first + "." + e.what() + " This error should never occur.", __FILE__, __LINE__);
		}
	}
};
#endif // !MATERIAL_H
