#include "UniformParameter.h"

UniformParameter::UniformParameter(const char * name, const GLenum type, const GLint * value){
	this->name = name;
	this->type = type;
	this->value = value;
}

UniformParameter::~UniformParameter(){
	delete name;
	name = nullptr;
	delete value;
	value = nullptr;
}
