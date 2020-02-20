#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <map>

#include "../../Utilities/Parameter.h"
#include "../../Debugging/Debug.h"

struct Material{
	typedef std::pair<unsigned int, Parameter> ParameterPair;

	Material(){}

	Material(std::string name, unsigned int location, Parameter parameter){
		AddParameter(name, location, parameter);
	}

	void AddParameter(std::string name, unsigned int location, Parameter parameter){
		parameters[name] = std::pair<unsigned int, Parameter>(location, parameter);
	}

	ParameterPair *getParameterPair(std::string name){
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
	typedef std::map<std::string, ParameterPair> Parameters;
	Parameters parameters;

	void setupParameter(const std::string name, ParameterPair &parameterPair);
};
#endif // !MATERIAL_H
