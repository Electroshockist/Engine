#ifndef UNIFORMPARAMETER_H
#define UNIFORMPARAMETER_H

#include <string>
#include <map>

#include "../../Utilities/Parameter.h"

struct UniformParameter{
	unsigned int location;
	char *nameInShader;
	Parameter parameter;

	UniformParameter();
	UniformParameter(unsigned int &location, char nameInShader[], Parameter parameter);

	void Setup(std::string name);

	~UniformParameter();
};

typedef std::map<std::string, UniformParameter> Parameters;

#endif // !UNIFORMPARAMETER_H

