#include "World1.h"
#include "../Library/Graphics/3D/ModelLoader.h"
#include "../Library/Graphics/Shaders/ShaderManager.h"
#include "../Library/Effects/LightSource.h"
#include "../Library/Data Structures/Events/Mouse/MouseEventHandler.h"
#include "../Library/Graphics/3D/SkyBox.h"
#include "EngineMain.h"

bool World1::OnCreate(){
	model = new Model("./Resources/Models/Dice.obj", "./Resources/Materials/Dice.mtl", ShaderManager::GetInstance()->getShader("basicShader"));
	glm::vec3 position = glm::vec3(-3.0, -4.0, 0.0);
	float angle = 0.0f;
	glm::vec3 rotation = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.0f);
	int modelInstance = model->createInstance(position, angle, rotation, scale);
	camera = new Camera();
	camera->setPosition(glm::vec3(0, 0, 10));
	camera->addLightSources(new LightSource(glm::vec3(5.0f, 10.0f, 5.0f), 1.0f, 0.5f, glm::vec3(1.0f, 1.0f, 1.0f)));
	//m = ModelLoader::GetInstance()->LoadModel("./Resources/Models/Dice.obj","./Resources/Materials/Dice.mtl", ShaderManager::GetInstance()->getShader("basicShader"));
	//m.CreateInstance(glm::vec3(), 0, glm::vec3(), glm::vec3());
	//camera = new Camera(/*EngineMain::GetInstance()->w*/);
	//camera->setPosition(glm::vec3(0, 10, 0));
	//m.SetCamera(camera);

	//LightSource l = LightSource(glm::vec3(5.0f, 10.0f, 5.0f), 1.0f, 0.5f, glm::vec3(1.0f, 1.0f, 1.0f));

	//glm::vec3 copyLightPos = l.GetPosition();
	//glm::vec3 copyLightColor = l.GetColour();

	//camera->parameters["light.lightPos"] = UniformParameter(ShaderManager::GetInstance()->getShader("basicShader"), "light.lightPos", Parameter(copyLightPos));
	//camera->parameters["light.ambientValue"] = UniformParameter(ShaderManager::GetInstance()->getShader("basicShader"), "light.ambientValue", Parameter(l.GetAmbientValue()));
	//camera->parameters["light.diffuseValue"] = UniformParameter(ShaderManager::GetInstance()->getShader("basicShader"), "light.diffuseValue", Parameter(l.GetDiffuseValue()));
	//camera->parameters["light.color"] = UniformParameter(ShaderManager::GetInstance()->getShader("basicShader"), "light.color", Parameter(copyLightColor));

	return true;
}

bool World1::Update(const float deltaTime_){
	return true;
}

bool World1::Render(){
	glUseProgram(ShaderManager::getShader("basicShader"));
	model->render(camera);
	return true;
}

void World1::OnMouseMove(int x, int y){
	if(camera){
		camera->processMouseMovement(MouseEventHandler::GetMouseOffset().x,
									 MouseEventHandler::GetMouseOffset().y);
	}
}
