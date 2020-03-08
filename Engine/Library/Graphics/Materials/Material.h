#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

#include "../3D/UniformParameter.h"
#include "../../Debugging/Debug.h"
#include "../../Utilities/File.h"

struct Material{

	Material() : shaderProgram(0){}

	Material(unsigned int &shaderProgram);

	void AddParameter(std::string name, char nameInShader[], unsigned int &location, Parameter parameter);

	UniformParameter *GetParameter(std::string name);

	void SetupLocations();

	void SetupParameters();

	void Load(File file);

	unsigned int shaderProgram;

	Parameters parameters;
};
#endif // !MATERIAL_H
