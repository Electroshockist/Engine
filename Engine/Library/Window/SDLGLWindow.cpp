#include "SDLGLWindow.h"
#include"../Debug/Debug.h"

#include <GLEW\glew.h>
#include <SDL\SDL_opengl.h>


SDLGLWindow::SDLGLWindow() :window(nullptr) {}

bool SDLGLWindow::onCreate(string title, int x, int y, int width, int height) {
	AWindow::onCreate(title, x, y, width, height);

	if(!initSDL()) {
		return false;
	}

	window = SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_WINDOW_OPENGL);

	if(window == nullptr) {
		Debug::fatalError("Failed to create a window", __FILE__, __LINE__);
		return false;
	}
	return true;
}

void SDLGLWindow::setTitle(string* title) {
	AWindow::setTitle(title);
	SDL_SetWindowTitle(window, title->c_str());
}

SDLGLWindow::~SDLGLWindow() {
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	window = nullptr;
	AWindow::~AWindow();
}

bool SDLGLWindow::initSDL() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		return false;
	}
	return true;
}

bool SDLGLWindow::initGL() {
	context = SDL_GL_CreateContext(window);
	int major, minor;
	getInstalledOpenGLInfo(&major,&minor);
	setAttributes(major, minor);

	/// Fire up the GL Extension Wrangler
	GLenum err = glewInit();
	if(err != GLEW_OK) {
		Debug::fatalError("Glew initialization failed", __FILE__, __LINE__);
		return false;
	}

	GLsizei w = *getWidth();
	GLsizei h = *getHeight();

	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, w, h);
	Debug::info("OpenGL version: " + std::string((char*)glGetString(GL_VERSION)), __FILE__, __LINE__);
	return true;
}

void SDLGLWindow::setAttributes(int major, int minor) {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
	SDL_GL_SetSwapInterval(1);
	glewExperimental = GL_TRUE;
	return;
}

void SDLGLWindow::getInstalledOpenGLInfo(int *major, int *minor) {
	/// You can to get some info regarding versions and manufacturer
	const GLubyte *version = glGetString(GL_VERSION);
	/// You can also get the version as ints	
	const GLubyte *vendor = glGetString(GL_VENDOR);
	const GLubyte *renderer = glGetString(GL_RENDERER);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

	std::cout << "GL Version " << version << std::endl;
	std::cout << "Graphics card vendor " << vendor << std::endl;
	std::cout << "Graphics card name " << renderer << std::endl;
	std::cout << "GLSL Version " << glslVersion << std::endl;
	glGetIntegerv(GL_MAJOR_VERSION, major);
	glGetIntegerv(GL_MINOR_VERSION, minor);
	return;
}
