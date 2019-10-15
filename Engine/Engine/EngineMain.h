#ifndef ENGINEMAIN_H
#define ENGINEMAIN_H
#include "Window\GlutWindow.h"
#include "Window\SDLGLWindow.h"
struct EngineMain {
	//delete constructors for singleton
	EngineMain(const EngineMain&) = delete;
	EngineMain(EngineMain&&) = delete;
	EngineMain& operator=(const EngineMain&) = delete;
	EngineMain& operator=(EngineMain&&) = delete;

	static EngineMain* getInstance();

	int run(int argc, char *argv[]);

private:
	EngineMain();
	~EngineMain();

	static std::unique_ptr<EngineMain> instance;
	friend std::default_delete<EngineMain>;
	
	SDLGLWindow *w;
};

#endif // !ENGINEMAIN_H

