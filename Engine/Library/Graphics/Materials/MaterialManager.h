#ifndef MATERIALHANDLER_H
#define MATERIALHANDLER_H

#include "Material.h"

#include <map>

struct MaterialManager{
	MaterialManager(){}

	~MaterialManager(){}

	void AddMaterial(std::string name);

	const Material GetMaterial(std::string file);

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

	std::map<std::string, Material*> materials;
};


#endif // !MATERIALHANDLER_H

