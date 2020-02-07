#ifndef AMATERIAL_H
#define AMATERIAL_H

#include <string>

#include <glm/glm.hpp>

class AMaterial{
public:
	AMaterial(std::string name, glm::vec2 *vector){
		AddParameter(name, vector);
	}
	AMaterial(std::string name, glm::vec3 *vector){
		AddParameter(name, vector);
	}
	AMaterial(std::string name, glm::vec4 *vector){
		AddParameter(name, vector);
	}

	void AddParameter(std::string name, glm::vec2 *vector){
		AddParameter(name, vector, 2);
	}
	void AddParameter(std::string name, glm::vec3 *vector){
		AddParameter(name, vector, 3);
	}
	void AddParameter(std::string name, glm::vec4 *vector){
		AddParameter(name, vector, 4);
	}

	std::pair<int, void *> getParameter(std::string name){
		return parameters.at(name);
	}

private:
	void AddParameter(std::string name, void *vectorData, int type){
		parameters.insert(std::pair(name, std::pair<int, void *>(type, vectorData)));
	}

	typedef std::map<std::string, std::pair<int, void *> > Parameters;

	Parameters parameters;
};

#endif // !AMATERIAL_H

