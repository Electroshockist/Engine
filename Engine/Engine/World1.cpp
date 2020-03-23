#include "World1.h"
#include "../Library/Graphics/3D/ModelLoader.h"
#include "../Library/Graphics/Shader/ShaderManager.h"

bool World1::OnCreate(){
	m = ModelLoader::GetInstance()->LoadModel("./Resources/Models/Dice.obj","./Resources/Materials/Dice.mtl", ShaderManager::getInstance()->getShader("basicShader"));
	c = new Camera();
	return true;
}

bool World1::Update(const float deltaTime_){
	return true;
}

bool World1::Render(){
	m.Render(c);
	return true;
}
