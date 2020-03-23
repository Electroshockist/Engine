#include "EngineMain.h"
#include "../Library/Debugging/Debug.h"
#include "../Library/Graphics/Shader/ShaderManager.h"

std::unique_ptr<EngineMain> EngineMain::instance = nullptr;

EngineMain::EngineMain() : w(nullptr), isRunning(false), fps(120){}

EngineMain *EngineMain::getInstance(){
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

	if(!world.OnCreate()){
		Debug::fatalError("Failed to create world", __FILE__, __LINE__);
		return false;
	}

	timer.Start();

	ShaderManager::getInstance()->createProgram("basicShader",
												"./Resources/Shaders/vertexShader.glsl",
												"./Resources/Shaders/fragmentShader.glsl"
	);

	return isRunning = true;
}

bool EngineMain::Run(){
	while(isRunning){
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

EngineMain::~EngineMain(){
	delete w;
	w = nullptr;

	SDL_Quit();
	exit(0);
}
