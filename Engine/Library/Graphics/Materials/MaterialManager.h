#ifndef MATERIALHANDLER_H
#define MATERIALHANDLER_H

#include "Material.h"

#include <map>

class MaterialManager{
public:
	MaterialManager(){}

	~MaterialManager(){}

private:
	std::map<std::string, Material> manager;
};


#endif // !MATERIALHANDLER_H

