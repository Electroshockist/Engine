#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

#include "../3D/UniformParameter.h"
#include "../../Debugging/Debug.h"

struct Material{
	Material() : shaderProgram(0), parameters(Parameters()){};

	void AddParameter(std::string name, std::string nameInShader, Parameter parameter);

	UniformParameter *GetParameter(std::string name);

	void SetupLocations();

	void SetupParameters();

	unsigned int shaderProgram;

	Parameters parameters;

};
#endif // !MATERIAL_H
