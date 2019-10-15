#include "EngineMain.h"
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
	w = new SDLGLWindow("Testes", 200, 200, 1080, 720);
	
	//figure out why this errors
	getchar();
	return EXIT_SUCCESS;
}

EngineMain::~EngineMain() {	
	delete w;
	w = nullptr;
}
