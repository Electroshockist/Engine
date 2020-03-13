#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <map>

#include "Model.h"

struct ModelLoader{
	static Model* LoadModel(std::string file);
	static void CreateModel(const std::string &name, const std::string &file);
	static void PostProcessing();
};


#endif // !MODELMANAGER_H
