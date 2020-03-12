#include "Material.h"
#include "MaterialManager.h"

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

void Material::Load(File file){
	//MaterialManager::GetInstance().
}

Material::Material(unsigned int &shaderProgram){
	this->shaderProgram = shaderProgram;
}

void Material::AddParameter(std::string name, char nameInShader[], unsigned int &location, Parameter parameter){
	parameters[name] = UniformParameter(location, nameInShader, parameter);
}

UniformParameter *Material::GetParameter(std::string name){
	return &parameters.at(name);
}

void Material::SetupLocations(){
	Parameters::iterator it;
	for(it = parameters.begin(); it != parameters.end(); it++){
		it->second.location = glGetUniformLocation(shaderProgram, it->second.nameInShader);
	}
}
