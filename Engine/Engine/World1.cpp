#include "World1.h"
#include "../Library/Graphics/3D/ModelLoader.h"
#include "../Library/Graphics/Shader/ShaderManager.h"
#include "../Library/Effects/LightSource.h"
#include "EngineMain.h"

bool World1::OnCreate(){
	m = ModelLoader::GetInstance()->LoadModel("./Resources/Models/Dice.obj","./Resources/Materials/Dice.mtl", ShaderManager::getInstance()->getShader("basicShader"));
	c = new Camera(EngineMain::getInstance()->w);

	LightSource l = LightSource(glm::vec3(5.0f, 10.0f, 5.0f), 1.0f, 0.5f, glm::vec3(1.0f, 1.0f, 1.0f));

	glm::vec3 copyCamPos = c->getPosition();
	glm::vec3 copyLightPos = l.GetPosition();
	glm::vec3 copyLightColor = l.GetColour();

	c->parameters["light.lightPos"] = UniformParameter(ShaderManager::getInstance()->getShader("basicShader"), "light.lightPos", Parameter(copyLightPos));
	c->parameters["light.ambientValue"] = UniformParameter(ShaderManager::getInstance()->getShader("basicShader"), "light.ambientValue", Parameter(l.GetAmbientValue()));
	c->parameters["light.diffuseValue"] = UniformParameter(ShaderManager::getInstance()->getShader("basicShader"), "light.diffuseValue", Parameter(l.GetDiffuseValue()));
	c->parameters["light.color"] = UniformParameter(ShaderManager::getInstance()->getShader("basicShader"), "light.color", Parameter(copyLightColor));

	return true;
}

bool World1::Update(const float deltaTime_){
	return true;
}

bool World1::Render(){
	m.Render(c);
	return true;
}
