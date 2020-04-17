#include "World1.h"

#include <glm/gtc/type_ptr.hpp>

#include "../Library/Graphics/3D/ModelLoader.h"
#include "../Library/Graphics/Shaders/ShaderManager.h"
#include "../Library/Effects/LightSource.h"
#include "../Library/Data Structures/Events/Mouse/MouseEventHandler.h"
#include "../Library/Graphics/3D/SkyBox.h"
#include "../Library/Effects/Particle.h"
#include "EngineMain.h"

bool World1::OnCreate(){
	CreateNoise3D();
	model = new Model("./Resources/Models/Dice.obj", "./Resources/Materials/Dice.mtl", ShaderManager::GetInstance()->getShader("basicShader"));
	model2 = new Model("./Resources/Models/Dice.obj", "./Resources/Materials/Dice.mtl", ShaderManager::GetInstance()->getShader("noiseShader"));
	
	glm::vec3 position = glm::vec3(-3.0, -4.0, 0.0);
	glm::vec3 position2 = glm::vec3(-5.0, -2.0, 0.0);

	float angle = 0.0f;
	float angle2 = 0.0f;

	glm::vec3 rotation = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 rotation2 = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.0f);
	glm::vec3 scale2 = glm::vec3(2.0f);

	int modelInstance = model->createInstance(position, angle, rotation, scale);
	int modelInstance2 = model2->createInstance(position2, angle2, rotation2, scale2);

	normalMatrix = glm::mat4(model2->getInstances()[0]);

	camera = new Camera();
	camera->Translate(glm::vec3(0, 0, 10));
	camera->AddLightSources(new LightSource(glm::vec3(5.0f, 10.0f, 5.0f), 1.0f, 0.5f, glm::vec3(1.0f, 1.0f, 1.0f)));

	p = new ParticleGenerator(ShaderManager::GetInstance()->getShader("particleShader"), "Apple_Body", 20);

	skybox = new SkyBox();
	skybox->onCreate();
	//m = ModelLoader::GetInstance()->LoadModel("./Resources/Models/Dice.obj","./Resources/Materials/Dice.mtl", ShaderManager::GetInstance()->getShader("basicShader"));
	//m.CreateInstance(glm::vec3(), 0, glm::vec3(), glm::vec3());
	//camera = new Camera(/*EngineMain::GetInstance()->w*/);
	//camera->SetPosition(glm::vec3(0, 10, 0));
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
	elapsedTime += deltaTime_;
	p->Update(deltaTime_, glm::vec3(0, 2, 0), glm::vec3(0, 2, 0), 20, glm::vec3(2));
	return true;
}

bool World1::Render(){
	skybox->Render(camera);

	glUseProgram(ShaderManager::getShader("basicShader"));
	model->render(camera);

	glUseProgram(ShaderManager::getShader("noiseShader"));
	glUniformMatrix4fv(glGetUniformLocation(ShaderManager::getShader("noiseShader"), "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));

	glUniformMatrix3fv(glGetUniformLocation(ShaderManager::getShader("noiseShader"), "cameraPos"), 1, GL_FALSE, glm::value_ptr(camera->GetPosition()));
	glUniform1f(glGetUniformLocation(ShaderManager::getShader("noiseShader"), "time"), elapsedTime);
	model2->render(camera);

	p->Draw();

	glUseProgram(0);
	return true;
}

void World1::OnMouseMove(int x, int y){
	if(camera){
		camera->ProcessMouseMovement(MouseEventHandler::GetMouseOffset().x,
									 MouseEventHandler::GetMouseOffset().y);
	}

	if(skybox){
		skybox->onMouseMove(MouseEventHandler::GetMouseOffset().x,
							MouseEventHandler::GetMouseOffset().y);
	}
}

void World1::OnMouseZoom(int zoom){
	if(camera){
		camera->ProcessMouseZoom(zoom);
	}
}
