#include "Model.h"
#include <iostream>
#include "ModelLoader.h"

Model::Model(GLuint shaderProgram_)
	: meshes(std::vector<Mesh *>()), shaderProgram(0), modelInstances(std::vector<glm::mat4>()){

	shaderProgram = shaderProgram_;
	//obj = new LoadObjModel();

	//obj->loadModel(objPath_, matPath_);
	//this->LoadModel();
}

Model::~Model(){
	if(meshes.size() > 0){
		//for(auto m : meshes){
		//	delete m;
		//	m = nullptr;
		//}
		meshes.clear();
	}
	modelInstances.clear();
}

void Model::AddMesh(Mesh *mesh_){
	meshes.push_back(mesh_);
}

void Model::Render(ACamera *camera_){
	for(auto m : meshes){
		m->Render(camera_, modelInstances);
	}
}

int Model::CreateInstance(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_){
	modelInstances.push_back(getTransform(position_, angle_, rotation_, scale_));
	return modelInstances.size() - 1;
}

void Model::UpdateInstance(int index_, glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_){
	modelInstances[index_] = getTransform(position_, angle_, rotation_, scale_);

}

glm::mat4 Model::getTransform(int index_) const{
	return modelInstances[index_];
}


GLuint Model::GetShaderProgram() const{
	return shaderProgram;
}

glm::mat4 Model::getTransform(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_){
	this->position = position_;
	glm::mat4 model;
	model = glm::translate(model, position_);
	model = glm::rotate(model, angle_, rotation_);
	model = glm::scale(model, scale_);

	return model;
}