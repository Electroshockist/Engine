#include "MaterialManager.h"
//#include <sstream>
//
//#include "../Textures/TextureManager.h"
//
//#include "../../Debugging/Debug.h"
//
//using namespace std;
//
//unique_ptr<MaterialManager> MaterialManager::managerInstance = nullptr;
//
//Material *MaterialManager::LoadMaterial(string file){
//	//if material already exists, return it directly
//	Material *m = GetMaterial(file);
//	if(m != nullptr){
//		return m;
//	}
//
//	m = new Material();
//	m->AddParameter("diffuseMap", "diffuseMap", Parameter(0u));
//	m->AddParameter("transparency", "transparency", Parameter(0.0f));
//	m->AddParameter("shine", "shine", Parameter(0.0f));
//	m->AddParameter("ambient", "ambient", Parameter(glm::vec3(1.0f)));
//	m->AddParameter("diffuse", "diffuse", Parameter(glm::vec3(1.0f)));
//	m->AddParameter("specular", "specular", Parameter(glm::vec3()));
//
//	//otherwise load material
//	ifstream in(file.c_str(), ios::in);
//	if(!in){
//		Debug::error("Cannot open MTL file " + file, __FILE__, __LINE__);
//		return nullptr;
//	}
//	string matName = "";
//	string line;
//
//	//shortform
//	#define GetData(name) m->GetParameter(name)->parameter.data
//
//	while(getline(in, line)){
//		if(line.substr(0, 7) == "newmtl "){
//			if(get<unsigned int>(GetData("diffuseMap")) != 0){
//				materials[file] = m;
//				m = nullptr;
//			}
//			matName = line.substr(7);
//			GetData("diffuseMap") = Parameter::Data(TextureManager::GetInstance()->LoadTexture(matName));
//		}
//		//Shine
//		if(line.substr(0, 4) == "	Ns "){
//			istringstream v(line.substr(4));
//			v >> get<float>(GetData("shine"));
//		}
//
//		//Transparency
//		if(line.substr(0, 3) == "	d "){
//			istringstream v(line.substr(3));
//			v >> get<float>(GetData("transparency"));
//		}
//
//		//Ambient
//		if(line.substr(0, 4) == "	Ka "){
//			istringstream v(line.substr(4));
//
//			double x, y, z;
//
//			v >> x >> y >> z;
//			get<glm::vec3>(GetData("ambient")) = glm::vec3(x, y, z);
//		}
//
//		//Diffuse
//		if(line.substr(0, 4) == "	Kd "){
//			istringstream v(line.substr(4));
//
//			double x, y, z;
//
//			v >> x >> y >> z;
//			get<glm::vec3>(GetData("diffuse")) = glm::vec3(x, y, z);
//		}
//
//		//Specular
//		if(line.substr(0, 4) == "	Ks "){
//			istringstream v(line.substr(4));
//
//			double x, y, z;
//
//			v >> x >> y >> z;
//			get<glm::vec3>(GetData("specular")) = glm::vec3(x, y, z);
//		}
//	}
//
//	if(get<unsigned int>(GetData("diffuseMap")) != 0){
//		materials[matName] = m;
//	};
//	return m;
//	#undef GetData(name)
//}
//
//Material *MaterialManager::GetMaterial(string name){
//	if(materials.find(name) != materials.end()){
//		return materials[name];
//	}
//	Debug::warning("Could not find texture with name " + name, __FILE__, __LINE__);
//	return nullptr;
//}
//
//
//MaterialManager *MaterialManager::GetInstance(){
//	if(managerInstance == nullptr){
//		managerInstance.reset(new MaterialManager);
//	}
//	return managerInstance.get();
//}

#include <iostream>

#include "../../Debugging/Debug.h"

std::unique_ptr<MaterialManager> MaterialManager::instance = nullptr;
std::map<std::string, Material> MaterialManager::materials = std::map<std::string, Material>();

MaterialManager::MaterialManager(){}


MaterialManager::~MaterialManager(){
	if(materials.size() > 0){
		materials.clear();
	}
}

void MaterialManager::AddMaterial(const std::string & name, Material mat){
	materials[name] = mat;
}

const Material MaterialManager::GetMaterial(const std::string & name){
	for(auto const&[key, val] : materials){
		std::cout << name << " == " << key << " " << (name == key ? "true" : "false") << std::endl;
	}
	if(materials.find(name) != materials.end()){
		return materials[name];
	}
	Debug::warning("Could not find texture with name " + name, __FILE__, __LINE__);
	return Material();
}

//get singleton instance
MaterialManager * MaterialManager::GetInstance(){
	if(instance == nullptr){
		instance.reset(new MaterialManager);
	}
	return instance.get();
}
