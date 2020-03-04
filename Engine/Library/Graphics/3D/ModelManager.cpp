#include "ModelManager.h"

std::unique_ptr<ModelManager> ModelManager::managerInstance = nullptr;

ModelManager * ModelManager::GetInstance(){
	if(managerInstance == nullptr){
		managerInstance.reset(new ModelManager());
	}
	return static_cast<ModelManager*>(managerInstance.get());
}

ModelManager::ModelManager(){}
ModelManager::~ModelManager(){}
