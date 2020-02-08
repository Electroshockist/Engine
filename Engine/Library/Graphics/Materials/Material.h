#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <map>

#include <glm/glm.hpp>
union Parameter{
	float f;
	double d;
	int i;
	unsigned int uint;
	glm::vec2 vec2;
	glm::vec3 vec3;
	glm::vec4 vec4;
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

private:
	typedef std::map<std::string, Parameter> Parameters;
	Parameters parameters;
};
#endif // !MATERIAL_H
