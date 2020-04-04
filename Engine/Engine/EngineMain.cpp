#include "EngineMain.h"
#include "../Library/Debugging/Debug.h"
#include "../Library/Graphics/Shader/ShaderManager.h"
#include "../Library/Data Structures/Events/EventListener.h"

std::unique_ptr<EngineMain> EngineMain::instance = nullptr;

EngineMain::EngineMain() : w(nullptr), isRunning(false), fps(120){}

EngineMain *EngineMain::GetInstance(){
	if(instance == nullptr){
		instance.reset(new EngineMain);
	}
	return instance.get();
}

bool EngineMain::OnCreate(int argc, char *argv[]){
	w = new SDLGLWindow();
	if(!w->OnCreate("Test", 200, 200, 1080, 720)){
		Debug::fatalError("Failed to create window", __FILE__, __LINE__);
		return false;
	}

	ShaderManager::GetInstance()->createProgram("basicShader",
												"./Resources/Shaders/vertexShader.glsl",
												"./Resources/Shaders/fragmentShader.glsl"
	);

	if(!world.OnCreate()){
		Debug::fatalError("Failed to create world", __FILE__, __LINE__);
		return false;
	}

	timer.Start();


	return isRunning = true;
}

bool EngineMain::Run(){
	while(isRunning){
		EventListener::update();
		timer.UpdateFrameTicks();

		//if update or render returns error, return false
		if(!Update(timer.GetDeltaTime()) || !Render()){
			return false;
		}

		SDL_Delay(timer.GetSleepTime(fps));
	}
	return true;
}

bool EngineMain::Update(const float deltaTime){
	return world.Update(deltaTime);
}

bool EngineMain::Render(){
	glClearColor(0.1f, 0.01f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int returnValue = world.Render();
	SDL_GL_SwapWindow(w->window);
	return returnValue;
}

void EngineMain::notifyMousePressed(int mouseX, int mouseY){}

void EngineMain::notifyMouseReleased(int mouseX, int mouseY, int buttonType){}

void EngineMain::notifyMouseMove(int mouseX, int mouseY){
	world.OnMouseMove(mouseX, mouseY);
}

void EngineMain::notifyMouseScroll(int scroll){}

void EngineMain::Exit(){
	isRunning = false;
}

EngineMain::~EngineMain(){
	delete w;
	w = nullptr;

	SDL_Quit();
	exit(0);
}
