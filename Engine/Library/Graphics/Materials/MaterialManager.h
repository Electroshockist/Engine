//#ifndef MATERIALMANAGER_H
//#define MATERIALMANAGER_H
//
//#include "Material.h"
//
//#include <map>
//
//struct MaterialManager{
//	MaterialManager(){}
//
//	~MaterialManager(){}
//
//	Material *LoadMaterial(std::string file);
//
//	Material *GetMaterial(std::string file);
//
//	//delete copy constructors for singleton
//	MaterialManager(const MaterialManager &) = delete;
//	MaterialManager(MaterialManager &&) = delete;
//	MaterialManager &operator=(const MaterialManager &) = delete;
//	MaterialManager &operator=(MaterialManager &&) = delete;
//
//	static MaterialManager *GetInstance();
//
//private:
//	//singleton instance pointer
//	static std::unique_ptr<MaterialManager> managerInstance;
//	friend std::default_delete<MaterialManager>;
//
//	std::map<std::string, Material *> materials;
//};
//
//
//#endif // !MATERIALMANAGER_H
//

#ifndef MATERIALHANDLER_H
#define MATERIALHANDLER_H

#include <memory>
#include <map>
#include <glm\glm.hpp>
#include <GLEW/glew.h>
#include <string>

struct Material{
	GLuint diffuseMap;
	float shine; // ns
	float transparency;//d

	glm::vec3 ambient;//ka
	glm::vec3 diffuse;//kd
	glm::vec3 specular;//ks

	inline Material() : diffuseMap(0), shine(0.0f), transparency(0.0f), ambient(glm::vec3(1.0f)), diffuse(glm::vec3(1.0f)), specular(glm::vec3()){}
};

class MaterialManager{
	static std::map<std::string, Material> materials;

public:
	void AddMaterial(const std::string& name, Material mat);
	const Material GetMaterial(const std::string& name);

	///Singleton

	static MaterialManager * GetInstance();

	//delete constructors for singleton
	MaterialManager(const MaterialManager&) = delete;
	MaterialManager(MaterialManager&&) = delete;
	MaterialManager& operator=(const MaterialManager&) = delete;
	MaterialManager& operator=(MaterialManager&&) = delete;

private:
	static std::unique_ptr<MaterialManager> instance;
	friend std::default_delete<MaterialManager>;
	MaterialManager();
	~MaterialManager();
};
#endif // !MATERIALHANDLER_H