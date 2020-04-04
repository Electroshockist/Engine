#ifndef ENGINEMAIN_H
#define ENGINEMAIN_H

#include "../Library/Window/SDLGLWindow.h"
#include "../Library/Timer/Timer.h"

#include "World1.h"

struct EngineMain {
	//delete constructors for singleton
	EngineMain(const EngineMain&) = delete;
	EngineMain(EngineMain&&) = delete;
	EngineMain& operator=(const EngineMain&) = delete;
	EngineMain& operator=(EngineMain&&) = delete;

	static EngineMain* GetInstance();

	bool OnCreate(int argc, char *argv[]);

	bool Run();

	bool Update(const float deltaTime);
	bool Render();

	void notifyMousePressed(int mouseX, int mouseY);
	void notifyMouseReleased(int mouseX, int mouseY, int buttonType);
	void notifyMouseMove(int mouseX, int mouseY);
	void notifyMouseScroll(int scroll);

	void Exit();

	SDLGLWindow *w;

private:
	EngineMain();
	~EngineMain();

	static std::unique_ptr<EngineMain> instance;
	friend std::default_delete<EngineMain>;

	World1 world;
	Timer timer;

	bool isRunning;
	unsigned int fps;
};

#endif // !ENGINEMAIN_H

