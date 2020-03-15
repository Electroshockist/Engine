#include "EngineMain.h"
#include "../Library/Debugging/Debug.h"

std::unique_ptr<EngineMain> EngineMain::instance = nullptr;

EngineMain::EngineMain() : w(nullptr){}

EngineMain *EngineMain::getInstance(){
	if(instance == nullptr){
		instance.reset(new EngineMain);
	}
	return instance.get();
}

bool EngineMain::OnCreate(int argc, char *argv[]){
	w = new SDLGLWindow();
	if(!w->OnCreate("Testes", 200, 200, 1080, 720)){
		Debug::fatalError("Failed to create window", __FILE__, __LINE__);
		return false;
	}
	if(!world.OnCreate()){
		Debug::fatalError("Failed to create world", __FILE__, __LINE__);
		return false;
	}

	return true;
}

bool EngineMain::Run(){
	if(!world.Update(1)){
		return false;
	};
	getchar();
	return true;
}

EngineMain::~EngineMain(){
	//figure out why deleting gives an error
	delete w;
	w = nullptr;
}
