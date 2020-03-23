#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include "Material.h"

#include <map>

struct MaterialManager{
	MaterialManager(){}

	~MaterialManager(){}

	Material *LoadMaterial(std::string file);

	Material *GetMaterial(std::string file);

	//delete copy constructors for singleton
	MaterialManager(const MaterialManager &) = delete;
	MaterialManager(MaterialManager &&) = delete;
	MaterialManager &operator=(const MaterialManager &) = delete;
	MaterialManager &operator=(MaterialManager &&) = delete;

	static MaterialManager *GetInstance();

private:
	//singleton instance pointer
	static std::unique_ptr<MaterialManager> managerInstance;
	friend std::default_delete<MaterialManager>;

	std::map<std::string, Material *> materials;
};


#endif // !MATERIALMANAGER_H

