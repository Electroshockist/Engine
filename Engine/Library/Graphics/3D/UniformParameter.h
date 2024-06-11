#ifndef UNIFORMPARAMETER
#define UNIFORMPARAMETER

#include <GLEW/glew.h>

struct UniformParameter{
	const char* name;
	GLenum type;
	const GLint *value;

	UniformParameter(const char * name, const GLenum type, const GLint *value);
	~UniformParameter();
};

#endif // !UNIFORMPARAMETER