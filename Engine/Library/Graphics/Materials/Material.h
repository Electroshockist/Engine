#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <map>

#include "../../Utilities/Parameter.h"
#include "../../Debugging/Debug.h"

struct MaterialParameter{
	unsigned int location;
	std::string nameInShader;
	Parameter parameter;

	MaterialParameter(unsigned int location, std::string nameInShader, Parameter parameter){
		this->location = location;
		this->nameInShader = nameInShader;
		this->parameter = parameter;
	}
};

struct Material{

	Material(){}

	Material(std::string name, std::string nameInShader, unsigned int location, Parameter parameter){
		AddParameter(name, nameInShader, location, parameter);
	}

	void AddParameter(std::string name, std::string nameInShader, unsigned int location, Parameter parameter){
		parameters[name] = MaterialParameter(location, nameInShader, parameter);
	}

	MaterialParameter *getParameter(std::string name){
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
	typedef std::map<std::string, MaterialParameter> Parameters;
	Parameters parameters;

	void setupParameter(const std::string name, MaterialParameter & parameter);
};
#endif // !MATERIAL_H
