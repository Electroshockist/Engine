#include "EngineMain.h"
#include "../Library/Debug/Debug.h"
#include <iostream>

std::unique_ptr<EngineMain> EngineMain::instance = nullptr;

EngineMain::EngineMain() {}

EngineMain * EngineMain::getInstance() {
	if(instance == nullptr) {
		instance.reset(new EngineMain);		
	}
	return instance.get();
}

int EngineMain::run(int argc, char * argv[]) {
	w = new SDLGLWindow();
	if(!w->onCreate("Testes", 200, 200, 1080, 720)) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

EngineMain::~EngineMain() {	
	//figure out why deleting 
	AWindow* w2;
	delete w2;
	w = nullptr;
}
