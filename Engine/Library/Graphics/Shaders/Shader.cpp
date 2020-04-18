#include "Shader.h"

#include <iostream>

#include "../../Debugging/Debug.h"

Shader& Shader::Use(){
	glUseProgram(this->ID);
	return *this;
}

void Shader::SetFloat(const GLchar* name, GLfloat value, bool overwrite, GLboolean useShader){
	if(Settable(name, Type::FLOAT, overwrite)){
		if(useShader)
			this->Use();
		glUniform1f(glGetUniformLocation(this->ID, name), value);
	}
}

void Shader::SetInteger(const GLchar* name, GLint value, bool overwrite, GLboolean useShader){
	if(Settable(name, Type::INT, overwrite)){
		if(useShader)
			this->Use();
		glUniform1i(glGetUniformLocation(this->ID, name), value);
	}
}

void Shader::SetVector2f(const GLchar* name, GLfloat x, GLfloat y, bool overwrite, GLboolean useShader){
	if(Settable(name, Type::VEC2, overwrite)){
		if(useShader)
			this->Use();
		glUniform2f(glGetUniformLocation(this->ID, name), x, y);
	}
}

void Shader::SetVector2f(const GLchar* name, const glm::vec2& value, bool overwrite, GLboolean useShader){
	if(Settable(name, Type::VEC2, overwrite)){
		if(useShader)
			this->Use();
		glUniform2f(glGetUniformLocation(this->ID, name), value.x, value.y);
	}
}

void Shader::SetVector3f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, bool overwrite, GLboolean useShader){
	if(Settable(name, Type::VEC3, overwrite)){
		if(useShader)
			this->Use();
		glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
	}
}

void Shader::SetVector3f(const GLchar* name, const glm::vec3& value, bool overwrite, GLboolean useShader){
	if(Settable(name, Type::VEC3, overwrite)){
		if(useShader)
			this->Use();
		glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z);
	}
}

void Shader::SetVector4f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, bool overwrite, GLboolean useShader){
	if(Settable(name, Type::VEC4, overwrite)){
		if(useShader)
			this->Use();
		glUniform4f(glGetUniformLocation(this->ID, name), x, y, z, w);
	}
}

void Shader::SetVector4f(const GLchar* name, const glm::vec4& value, bool overwrite, GLboolean useShader){
	if(Settable(name, Type::VEC4, overwrite)){
		if(useShader)
			this->Use();
		glUniform4f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z, value.w);
	}
}

void Shader::SetMatrix4(const GLchar* name, const glm::mat4& matrix, bool overwrite, GLboolean useShader){
	if(Settable(name, Type::MAT4, overwrite)){
		if(useShader)
			this->Use();
		glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, GL_FALSE, glm::value_ptr(matrix));
	}
}

float* Shader::GetFloat(const GLchar * name){
	if(Gettable(name, Type::FLOAT)) return &floats[name].second;
	return nullptr;
}

int * Shader::GetInteger(const GLchar * name){
	if(Gettable(name, Type::INT)) return &ints[name].second;
	return nullptr;
}

glm::vec2* Shader::GetVector2f(const GLchar* name){
	if(Gettable(name, Type::VEC2)) return &vec2s[name].second;
	return nullptr;
}

glm::vec3* Shader::GetVector3f(const GLchar* name){
	if(Gettable(name, Type::VEC3)) return &vec3s[name].second;
	return nullptr;
}

glm::vec4* Shader::GetVector4f(const GLchar* name){
	if(Gettable(name, Type::VEC4)) return &vec4s[name].second;
	return nullptr;
}

glm::mat4* Shader::GetMatrix4(const GLchar* name){
	if(Gettable(name, Type::MAT4)) return &mat4s[name].second;
	return nullptr;
}



bool Shader::Gettable(std::string name, Type type){
	//if item does not exist, it is not gettable
	if(contentMap.find(name) == contentMap.end()){
		Debug::warning("No uniform " + name + " exists.", __FILE__, __LINE__);
		return false;
	}
	Type t = contentMap[name];

	//if item is not of the desired type, it is not gettable
	if(t != type){
		Debug::warning("Uniform " + name + " is of type " + ToString(t) + " but was acessed as type " + ToString(type), __FILE__, __LINE__);
		return false;
	}

	return true;
}

bool Shader::Settable(std::string name, Type type, bool overwrite){
	//if item does not exist, return true
	if(contentMap.find(name) == contentMap.end()) return true;

	Type t = contentMap[name];

	//if item is the same type as the desired item, allow the user to determine whether to overwrite it or not
	if(t == type){
		return overwrite;
	}
	return false;
}
