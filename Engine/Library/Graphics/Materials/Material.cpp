#include "Material.h"
#include <GLEW/glew.h>

void Material::SetupParameters(){
	if(parameters.empty()){
		Debug::warning("No material parameters exist.", __FILE__, __LINE__);
		return;
	}

	for(Parameters::iterator it = parameters.begin(); it != parameters.end(); it++){
		it->second.Setup(it->first);
	}
}

void Material::SetupLocations(){
	Parameters::iterator it;
	for(it = parameters.begin(); it != parameters.end(); it++){
		it->second.location = glGetUniformLocation(shaderProgram, it->second.nameInShader);
	}
}
