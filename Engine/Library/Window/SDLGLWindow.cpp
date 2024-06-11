#include "SDLGLWindow.h"
#include"../Debugging/Debug.h"

#include <GLEW\glew.h>
#include <SDL\SDL_opengl.h>

SDLGLWindow::SDLGLWindow() : window(nullptr), context(nullptr){}

bool SDLGLWindow::OnCreate(string title, int x, int y, int width, int height){
	AWindow::OnCreate(title, x, y, width, height);

	if(!InitSDL()) return false;

	window = SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_OPENGL);

	if(window == nullptr){
		Debug::fatalError("Failed to create a window", __FILE__, __LINE__);
		return false;
	}

	if(!InitGL()) return false;

	return true;
}

void SDLGLWindow::SetTitle(const string title){
	AWindow::SetTitle(title);
	SDL_SetWindowTitle(window, title.c_str());
}

SDLGLWindow::~SDLGLWindow(){
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	window = nullptr;
}

bool SDLGLWindow::InitSDL(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		return false;
	}
	return true;
}

bool SDLGLWindow::InitGL(){
	context = SDL_GL_CreateContext(window);

	int major, minor;
	GetInstalledOpenGLInfo(&major, &minor);
	SetAttributes(major, minor);

	/// Fire up the GL Extension Wrangler
	GLenum err = glewInit();
	if(err != GLEW_OK){
		Debug::fatalError("Glew initialization failed", __FILE__, __LINE__);
		return false;
	}

	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, GetWidth(), GetHeight());
	return true;
}

void SDLGLWindow::SetAttributes(int major, int minor){
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
	SDL_GL_SetSwapInterval(1);
	glewExperimental = GL_TRUE;
	return;
}

void SDLGLWindow::GetInstalledOpenGLInfo(int *major, int *minor){
	/// You can to get some info regarding versions and manufacturer
	const GLubyte *version = glGetString(GL_VERSION);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	/// You can also get the version as ints	
	const GLubyte *vendor = glGetString(GL_VENDOR);
	const GLubyte *renderer = glGetString(GL_RENDERER);

	std::cout << "GL Version " << version << std::endl;
	std::cout << "GLSL Version " << glslVersion << std::endl;
	std::cout << "Graphics card vendor " << vendor << std::endl;
	std::cout << "Graphics card name " << renderer << std::endl;
	glGetIntegerv(GL_MAJOR_VERSION, major);
	glGetIntegerv(GL_MINOR_VERSION, minor);

	std::cout << std::endl;

	return;
}