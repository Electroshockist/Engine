#ifndef ENGINEMAIN_H
#define ENGINEMAIN_H

#include "../Library/Window/SDLGLWindow.h"

#include "World1.h"

struct EngineMain {
	//delete constructors for singleton
	EngineMain(const EngineMain&) = delete;
	EngineMain(EngineMain&&) = delete;
	EngineMain& operator=(const EngineMain&) = delete;
	EngineMain& operator=(EngineMain&&) = delete;

	static EngineMain* getInstance();

	bool OnCreate();

	bool Run(int argc, char *argv[]);

private:
	EngineMain();
	~EngineMain();

	static std::unique_ptr<EngineMain> instance;
	friend std::default_delete<EngineMain>;
	
	SDLGLWindow *w;

	World1 world;
};

#endif // !ENGINEMAIN_H

