#include "World1.h"

#include <glm/gtc/type_ptr.hpp>

#include "../Library/Graphics/3D/ModelLoader.h"
#include "../Library/Graphics/Shaders/ShaderManager.h"
#include "../Library/Effects/LightSource.h"
#include "../Library/Data Structures/Events/Mouse/MouseEventHandler.h"
#include "../Library/Graphics/3D/SkyBox.h"
#include "../Library/Effects/Particle.h"
#include "../Library/GameObject/GameObject.h"
#include "EngineMain.h"

using namespace DataStructures;

bool World1::OnCreate(){
	noiseID = CreateNoise3D();
	model = new Model("./Resources/Models/Dice.obj", "./Resources/Materials/Dice.mtl", ShaderManager::GetInstance()->getShader("basicShader"));
	model2 = new Model("./Resources/Models/skull.obj", "./Resources/Materials/Dice.mtl", ShaderManager::GetInstance()->getShader("noiseShader"));
	model3 = new Model("./Resources/Models/Plane.obj", "./Resources/Models/Dice.mtl", ShaderManager::GetInstance()->getShader("noiseShader"));

	glm::vec3 position = glm::vec3(3.0, -2.0, 0.0);
	glm::vec3 position2 = glm::vec3(-10.0, 0.0, 0.0);
	glm::vec3 position3 = glm::vec3(0.0, -4.0, 0.0);

	float angle = 0.0f;
	float angle2 = 90.0f;

	glm::vec3 rotation = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::vec3 scale = glm::vec3(1.0f);
	glm::vec3 scale2 = glm::vec3(2.0f);
	glm::vec3 scale3 = glm::vec3(2.0f);

	int modelInstance = model->createInstance(position, angle, rotation, scale);
	int modelInstance2 = model2->createInstance(position2, angle2, rotation, scale2);
	int modelInstance3 = model3->createInstance(position3, angle, rotation, scale3);

	normalMatrix = glm::mat4(model2->getInstances()[0]);

	camera = new Camera();
	camera->Translate(glm::vec3(0, 0, 10));
	camera->AddLightSources(new LightSource(glm::vec3(5.0f, 2.0f, 5.0f), 1.0f, 0.5f, glm::vec3(1.0f, 1.0f, 1.0f)));

	p = new ParticleGenerator("./Resources/Models/Dice.obj", "./Resources/Materials/Dice.mtl", 20, position2);

	skybox = new SkyBox();
	skybox->onCreate();

	Decorator::Node
		*a = new Decorator::Node(),
		*aa = new Decorator::Node(),
		*aaa = new Decorator::Node(),
		*b = new Decorator::Node();

	/*GameObject * g = new GameObject();
	g->addComponent(model);*/

	//a->data = g;

	a->AddChild("aa", aa);
	aa->AddChild("aaa", aaa);

	sceneGraph.root.AddChild("a", a);
	sceneGraph.root.AddChild("b", b);

	sceneGraph.PrintGraph();

	AudioPlayer::Instance()->PlayMusic("Audio/AK - Night Drive.mp3");
	AudioPlayer::Instance()->MusicVolume(15);
	

	return true;
}

bool World1::Update(const float deltaTime_){
	elapsedTime += deltaTime_;
	p->Update(deltaTime_);
	return true;
}

bool World1::Render(){
	skybox->Render(camera);

	model->Render(camera);

	Shader * shader = ShaderManager::getShader("noiseShader");
	shader->Use();

	glBindTexture(GL_TEXTURE_CUBE_MAP, skybox->GetSubMesh().material.diffuseMap);
	shader->BindTexture("noise3D", GL_TEXTURE_3D, 1, noiseID);
	shader->SetUniformData("time", elapsedTime);
	shader->SetUniformData("lightPos", camera->GetLightSources()[0]->GetPosition());

	shader->SetUniformData("noiseSpread", 0.25f);
	shader->SetUniformData("noiseSpeed", 0.05f);
	shader->SetUniformData("noiseHeight", 0.5f);

	model2->Render(camera);
	model3->Render(camera);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	glBindTexture(GL_TEXTURE_3D, 0);


	p->Render(camera);

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

void World1::OnMouseClicked(int mouseX, int mouseY, int buttonType){

	if (buttonType == 1) {
		
		AudioPlayer::Instance()->PlaySFX("Audio/Sword_Slash.mp3",0,-1);
		cout << "pppoopoo" << endl;
	}

}
