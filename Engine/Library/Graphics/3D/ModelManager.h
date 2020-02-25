#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "../../Utilities/Manager.h"
#include "Model.h"

class ModelManager : public Manager<Model>{
public:
	//delete copy constructors for singleton
	ModelManager(const ModelManager&) = delete;
	ModelManager(ModelManager&&) = delete;
	ModelManager& operator=(const ModelManager&) = delete;
	ModelManager& operator=(ModelManager&&) = delete;

	//get singleton instance
	static ModelManager* GetInstance();

private:
	//singleton instance pointer
	static std::unique_ptr<ModelManager> managerInstance;
	friend std::default_delete<ModelManager>;

	ModelManager();

	~ModelManager();
};


#endif // !MODELMANAGER_H
