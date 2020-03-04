#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

#include "../3D/UniformParameter.h"
#include "../../Debugging/Debug.h"

struct Material{

	Material() : shaderProgram(0){}

	Material(unsigned int &shaderProgram, std::string name, char nameInShader[], unsigned int &location, Parameter parameter){
		this->shaderProgram = shaderProgram;
		AddParameter(name, nameInShader, location, parameter);
	}

	void AddParameter(std::string name, char nameInShader[], unsigned int &location, Parameter parameter){
		parameters[name] = UniformParameter(location, nameInShader, parameter);
	}

	UniformParameter *GetParameter(std::string name){
		return &parameters.at(name);
	}

	void SetupLocations();

	void SetupParameters();

private:
	unsigned int shaderProgram;

	Parameters parameters;
};
#endif // !MATERIAL_H
