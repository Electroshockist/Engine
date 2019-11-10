#include "EngineMain.h"
#include "../Library/Debugging/Debug.h"

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
	getchar();
	return EXIT_SUCCESS;
}

EngineMain::~EngineMain() {
	//figure out why deleting gives an error
	delete w;
	w = nullptr;
}
