#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <map>
#include <variant>

#include <glm/glm.hpp>

#include "../../Debugging/Debug.h"

struct Parameter{
	typedef std::variant<int, unsigned int, double, float, glm::vec2, glm::vec3, glm::vec4> Data;

	std::string name;
	Data data;
	unsigned int location;

};

struct Material{


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

		for(Parameters::iterator it = parameters.begin(); it != parameters.end(); it++){
			setupParameter(it->first, it->second);
		}
	}

private:
	typedef std::map<std::string*, Parameter> Parameters;
	Parameters parameters;

	void setupParameter(const std::string name, Parameter& parameter){
		try{
			Parameter::Data& data = parameter.data;
			unsigned int& location = parameter.location;

			switch(data.index()){
				case 0:
					Debug::warning("Material parameter with name " + name + " is empty.", __FILE__, __LINE__);
					break;
				case 1:
					glUniform1i(location, std::get<int>(data));
					break;
				case 2:
					glUniform1ui(location, std::get<unsigned int>(data));
					break;
				case 3:
					glUniform1d(location, std::get<double>(data));
					break;
				case 4:
					glUniform1f(location, std::get<float>(data));
					break;
				case 5:
					glm::vec2 data2 = std::get<glm::vec2>(data);
					glUniform2f(location, data2.x, data2.y);
					break;
				case 6:
					glm::vec3 data3 = std::get<glm::vec3>(data);
					glUniform3f(location, data3.x, data3.y, data3.z);
					break;
				case 7:
					glm::vec4 data4 = std::get<glm::vec4>(data);
					glUniform4f(location, data4.x, data4.y, data4.z, data4.w);
					break;

				default:
					Debug::error("Material parameter with name " + name + " does not exist. This error should never occur.", __FILE__, __LINE__);
					break;
			}
		} catch(const std::bad_variant_access& e){
			Debug::error("Improper variant cast at parameter with name" + name + "." + e.what() + " This error should never occur.", __FILE__, __LINE__);
		}
	}
};
#endif // !MATERIAL_H
