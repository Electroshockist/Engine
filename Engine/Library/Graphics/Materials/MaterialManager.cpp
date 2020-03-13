#include "MaterialManager.h"

#include <sstream>

#include "../Textures/TextureManager.h"

#include "../../Debugging/Debug.h"


std::unique_ptr<MaterialManager> MaterialManager::managerInstance = nullptr;

void MaterialManager::AddMaterial(std::string name){

	std::ifstream in(name.c_str(), std::ios::in);
	if(!in){
		Debug::error("Cannot open MTL file " + name, __FILE__, __LINE__);
		return;
	}
	Material* m = new Material();
	std::string matName = "";
	std::string line;
	//while(std::getline(in, line)){
	//	if(line.substr(0, 7) == "newmtl "){
	//		if(std::get<int>(m->GetParameter("diffuseMap")->parameter.data) != 0){
	//			materials[name] = m;
	//			m = new Material();
	//		}
	//		matName = line.substr(7);
	//		m.diffuseMap = TextureManager::GetInstance()->LoadTexture(matName);
	//		m->GetParameter("diffuseMap")->parameter.data = TextureManager::GetInstance()->LoadTexture(matName);
	//	}
	//	//Shine
	//	if(line.substr(0, 4) == "	Ns "){
	//		std::istringstream v(line.substr(4));
	//		v >> m.shine;
	//	}

	//	//Transparency
	//	if(line.substr(0, 3) == "	d "){
	//		std::istringstream v(line.substr(3));
	//		v >> m.transparency;
	//	}

	//	//Ambient
	//	if(line.substr(0, 4) == "	Ka "){
	//		std::istringstream v(line.substr(4));

	//		double x, y, z;

	//		v >> x >> y >> z;
	//		m.ambient = glm::vec3(x, y, z);
	//	}

	//	//Diffuse
	//	if(line.substr(0, 4) == "	Kd "){
	//		std::istringstream v(line.substr(4));

	//		double x, y, z;

	//		v >> x >> y >> z;
	//		m.diffuse = glm::vec3(x, y, z);
	//	}

	//	//Specular
	//	if(line.substr(0, 4) == "	Ks "){
	//		std::istringstream v(line.substr(4));

	//		double x, y, z;

	//		v >> x >> y >> z;
	//		m.specular = glm::vec3(x, y, z);
	//	}
	//}

	//if(m.diffuseMap != 0){
	//	materials[matName] = m;
	//};
}

const Material MaterialManager::GetMaterial(std::string name){
	if(materials.find(name) != materials.end()){
		return *materials[name];
	}
	Debug::warning("Could not find texture with name " + name, __FILE__, __LINE__);
	return Material();
}

//get singleton instance
MaterialManager *MaterialManager::GetInstance(){
	if(managerInstance == nullptr){
		managerInstance.reset(new MaterialManager);
	}
	return managerInstance.get();
}
