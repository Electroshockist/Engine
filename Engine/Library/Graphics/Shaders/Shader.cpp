#include "Shader.h"

#include <iostream>

#include "../../Debugging/Debug.h"

#define SETUNIFORM(name, useShader)	if(useShader) this->Use(); Uniform * u = GetUniform(name); if(u == nullptr){ Debug::warning("The uniform " + std::string(name) + " does not exist in the shader \"" + this->name + "\".", __FILE__, __LINE__); return;}

Shader& Shader::Use(){
	glUseProgram(this->ID);
	return *this;
}

void Shader::SetUniformData(const GLchar* name, GLfloat value, GLboolean useShader){
	SETUNIFORM(name, useShader);
	glUniform1f(u->location, value);
}

void Shader::SetUniformData(const GLchar* name, GLint value, GLboolean useShader){
	SETUNIFORM(name, useShader);
	glUniform1i(u->location, value);
}

void Shader::SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader){
	SETUNIFORM(name, useShader);
	glUniform2f(GetUniform(name)->location, x, y);
}

void Shader::SetUniformData(const GLchar* name, const glm::vec2& value, GLboolean useShader){
	SETUNIFORM(name, useShader);
	glUniform2f(GetUniform(name)->location, value.x, value.y);
}

void Shader::SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader){
	SETUNIFORM(name, useShader);
	glUniform3f(GetUniform(name)->location, x, y, z);
}

void Shader::SetUniformData(const GLchar* name, const glm::vec3& value, GLboolean useShader){
	SETUNIFORM(name, useShader);
	glUniform3f(GetUniform(name)->location, value.x, value.y, value.z);
}

void Shader::SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader){
	SETUNIFORM(name, useShader);
	glUniform4f(GetUniform(name)->location, x, y, z, w);
}

void Shader::SetUniformData(const GLchar* name, const glm::vec4& value, GLboolean useShader){
	SETUNIFORM(name, useShader);
	glUniform4f(GetUniform(name)->location, value.x, value.y, value.z, value.w);
}

void Shader::SetUniformData(const GLchar* name, const glm::mat4& matrix, GLboolean useShader){
	SETUNIFORM(name, useShader);
	glUniformMatrix4fv(GetUniform(name)->location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::BindTexture(const GLchar * name, GLenum textureType, GLenum textureNum, GLuint data){
	SetUniformData("material.diffuseMap", (int)GetTextureNum(textureNum));
	glActiveTexture(textureNum);

	glBindTexture(textureType, data);
}

void Shader::CreateUniform(const GLchar* name){
	//store the name and location of the uniform
	Uniform u = Uniform(name);
	u.location = glGetUniformLocation(ID, name);

	uniforms.push_back(u);
}

bool Shader::ItemExists(std::string name){
	for(Uniform u : uniforms){
		if(u.name == name){
			return true;
		}
	}

	return false;
}

Shader::Uniform * Shader::GetUniform(std::string name){
	for(size_t i = 0; i < uniforms.size(); i++){
		if(uniforms[i].name == name){
			return &uniforms[i];
		}
	}
	return nullptr;
}

GLuint Shader::GetTextureNum(GLenum textureNum){
	//glenums are ordered contiguoisly, so treat GL_Texture as 0
	return textureNum - GL_TEXTURE0;
}

