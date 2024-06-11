#include "Shader.h"

#include <iostream>

#include "../../Debugging/Debug.h"

#define UNIFORMCHECKS(name, useShader)	if(useShader) this->Use(); if(!ItemExists(name)){Debug::warning("The uniform " + std::string(name) + " does not exist in the shader \"" + this->name + "\".", __FILE__, __LINE__);return;}

//concatinate uniform command
#define GETUNIFORMCOMMAND(vSize, type, location, count, value) glUniform## vSize ## type ## v(location, count, value)

#define SETUNIFORMVALUE(type) if(performUniformCheck) UNIFORMCHECKS(name, useShader);switch(vectorSize){case 1:	GETUNIFORMCOMMAND(1, type, uniforms.at(name), count, value);break;case 2:GETUNIFORMCOMMAND(2, type, uniforms.at(name), count, value);break;case 3:GETUNIFORMCOMMAND(3, type, uniforms.at(name), count, value);break;case 4:GETUNIFORMCOMMAND(4, type, uniforms.at(name), count, value);break;default:UNIFORMERROR;break;}

#define UNIFORMERROR std::string msg = "Vectors cant be "; if(vectorSize > 4){msg += "greater than 4.";} else if(vectorSize < 1){msg += "less than 1.";}Debug::error(msg, __FILE__, __LINE__);

Shader& Shader::Use(){
	glUseProgram(this->ID);
	return *this;
}

void Shader::SetUniformData(const GLchar* name, GLfloat value, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);

	glUniform1f(uniforms.at(name), value);
}

void Shader::SetUniformData(const GLchar* name, GLfloat x, GLfloat y, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform2f(uniforms.at(name), x, y);
}

void Shader::SetUniformData(const GLchar* name, const glm::vec2& value, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform2f(uniforms.at(name), value.x, value.y);
}

void Shader::SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform3f(uniforms.at(name), x, y, z);
}

void Shader::SetUniformData(const GLchar* name, const glm::vec3& value, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform3f(uniforms.at(name), value.x, value.y, value.z);
}

void Shader::SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform4f(uniforms.at(name), x, y, z, w);
}

void Shader::SetUniformData(const GLchar* name, const glm::vec4& value, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform4f(uniforms.at(name), value.x, value.y, value.z, value.w);
}

void Shader::SetUniformData(const GLchar* name, const glm::mat4& matrix, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniformMatrix4fv(uniforms.at(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::SetUniformData(const GLchar* name, GLint value, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform1i(uniforms.at(name), value);
}

void Shader::SetUniformData(const GLchar * name, GLint x, GLint y, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform2i(uniforms.at(name), x, y);
}

void Shader::SetUniformData(const GLchar * name, GLint x, GLint y, GLint z, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform3i(uniforms.at(name), x, y, z);
}

void Shader::SetUniformData(const GLchar * name, GLint x, GLint y, GLint z, GLint w, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform4i(uniforms.at(name), x, y, z, w);
}

void Shader::SetUniformData(const GLchar * name, GLuint value, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform1ui(uniforms.at(name), value);
}

void Shader::SetUniformData(const GLchar * name, GLuint x, GLuint y, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform2ui(uniforms.at(name), x, y);
}

void Shader::SetUniformData(const GLchar * name, GLuint x, GLuint y, GLuint z, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform3ui(uniforms.at(name), x, y, z);
}

void Shader::SetUniformData(const GLchar * name, GLuint x, GLuint y, GLuint z, GLuint w, bool performUniformCheck, bool useShader){
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform4ui(uniforms.at(name), x, y, z, w);
}

void Shader::SetUniformData(const GLchar * name, const GLfloat * value, const GLenum type, int vectorSize, GLsizei count, bool performUniformCheck, bool useShader){
	SETUNIFORMVALUE(f);
}

void Shader::SetUniformData(const GLchar * name, const GLint * value, const GLenum type, int vectorSize, GLsizei count, bool performUniformCheck, bool useShader){
	SETUNIFORMVALUE(i);
}

void Shader::SetUniformData(const GLchar * name, const GLuint * value, const GLenum type, int vectorSize, GLsizei count, bool performUniformCheck, bool useShader){
	SETUNIFORMVALUE(ui);
}

void Shader::BindTexture(const GLchar * name, GLenum textureType, GLenum textureNum, GLuint data){
	SetUniformData(name, (int)GetTextureNum(textureNum));
	glActiveTexture(textureNum);

	glBindTexture(textureType, data);
}

void Shader::CreateUniform(const GLchar* name){
	//store the name and location of the uniform
	uniforms[name] = glGetUniformLocation(ID, name);
}

bool Shader::ItemExists(std::string name) const{
	return uniforms.find(name) != uniforms.end();
}

GLuint Shader::GetTextureNum(GLenum textureNum){
	//glenums are ordered contiguoisly, so treat GL_TEXTURE0 as 0
	return textureNum - GL_TEXTURE0;
}

