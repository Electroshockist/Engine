//#include "Model.h"
//#include <iostream>
//#include "ModelLoader.h"
//
//Model::Model(GLuint shaderProgram_)
//	: meshes(std::vector<Mesh *>()), shaderProgram(0), modelInstances(std::vector<glm::mat4>()){
//
//	shaderProgram = shaderProgram_;
//	//obj = new ModelLoader();
//
//	//obj->loadModel(objPath_, matPath_);
//	//this->LoadModel();
//}
//
//Model::~Model(){
//	if(meshes.size() > 0){
//		//for(auto m : meshes){
//		//	delete m;
//		//	m = nullptr;
//		//}
//		meshes.clear();
//	}
//	modelInstances.clear();
//}
//
//void Model::AddMesh(Mesh *mesh_){
//	meshes.push_back(mesh_);
//}
//
//void Model::Render(){
//	for(auto m : meshes){
//		m->Render(camera, modelInstances);
//	}
//}
//
//int Model::CreateInstance(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_){
//	modelInstances.push_back(getTransform(position_, angle_, rotation_, scale_));
//	return modelInstances.size() - 1;
//}
//
//void Model::UpdateInstance(int index_, glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_){
//	modelInstances[index_] = getTransform(position_, angle_, rotation_, scale_);
//
//}
//
//glm::mat4 Model::getTransform(int index_) const{
//	return modelInstances[index_];
//}
//
//
//GLuint Model::GetShaderProgram() const{
//	return shaderProgram;
//}
//
//glm::mat4 Model::getTransform(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_){
//	this->position = position_;
//	glm::mat4 model;
//	model = glm::translate(model, position_);
//	model = glm::rotate(model, angle_, rotation_);
//	model = glm::scale(model, scale_);
//
//	return model;
//}
#include "Model.h"
#include <iostream>

Model::Model(const std::string& objPath_, const std::string& matPath_, Shader * shaderProgram_)
	: subMeshes(std::vector<Mesh*>()), shaderProgram(0), modelInstances(std::vector<glm::mat4>()){
	shaderProgram = shaderProgram_;
	obj = new ModelLoader();

	obj->loadModel(objPath_, matPath_);
	this->loadModel();
}

Model::~Model(){
	onDestroy();
}

void Model::addMesh(Mesh * mesh_){
	subMeshes.push_back(mesh_);
}

void Model::onDestroy(){
	if(subMeshes.size() > 0){
		for(auto m : subMeshes){
			delete m;
			m = nullptr;
		}
		subMeshes.clear();
	}
	modelInstances.clear();
}

int Model::createInstance(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_){
	modelInstances.push_back(getTransform(position_, angle_, rotation_, scale_));
	return modelInstances.size() - 1;
}

void Model::updateInstance(int index_, glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_){
	modelInstances[index_] = getTransform(position_, angle_, rotation_, scale_);
}

glm::mat4 Model::getTransform(int index_) const{
	return modelInstances[index_];
}

std::vector<glm::mat4> Model::getInstances() const{
	return modelInstances;
}

Shader * Model::getShaderProgram() const{
	return shaderProgram;
}

void Model::Render(ACamera * camera){
	Camera* c = dynamic_cast<Camera*>(camera);
	if(c != nullptr){
		for(auto m : subMeshes){
			m->Render(c, modelInstances);
		}
	}
}

void Model::loadModel(){
	for(int i = 0; i < obj->getSubMeshes().size(); i++){
		subMeshes.push_back(new Mesh(obj->getSubMeshes()[i], shaderProgram));
	}
	delete obj;
	obj = nullptr;
}

glm::mat4 Model::getTransform(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_){
	this->position = position_;
	glm::mat4 tModel;
	glm::mat4 rModel;
	glm::mat4 sModel;

	tModel = glm::translate(glm::mat4(1), position_);
	rModel = glm::rotate(glm::mat4(1), angle_, rotation_);
	sModel = glm::scale(glm::mat4(1), scale_);

	glm::mat4 model = tModel * rModel * sModel;
	return model;
}