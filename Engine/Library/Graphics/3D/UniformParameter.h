#ifndef UNIFORMPARAMETER_H
#define UNIFORMPARAMETER_H

#include <string>
#include <map>

#include "../../Utilities/Parameter.h"

struct UniformParameter{

	UniformParameter();
	UniformParameter(unsigned int shaderProgram, std::string nameInShader, Parameter parameter);

	void Setup(std::string name);
	~UniformParameter();

	Parameter parameter;
	std::string nameInShader;
	int location;
};

typedef std::map<std::string, UniformParameter> Parameters;

#endif // !UNIFORMPARAMETER_H

