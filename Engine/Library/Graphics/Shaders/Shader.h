#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <map>

#include <glew/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <map>


struct Shader{
	friend class ShaderManager;

	// Constructor
	Shader(){}

	~Shader(){
		if(!uniforms.empty()) uniforms.clear();
	}

	//ID getter
	inline const GLuint& GetID() const{
		return ID;
	}

	// Sets the current shader as active
	Shader& Use();

	// Utility functions
	void SetUniformData(const GLchar* name, GLfloat value, GLboolean useShader = false);
	void SetUniformData(const GLchar* name, GLint value, GLboolean useShader = false);
	void SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader = false);
	void SetUniformData(const GLchar* name, const glm::vec2& value,  GLboolean useShader = false);
	void SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z,  GLboolean useShader = false);
	void SetUniformData(const GLchar* name, const glm::vec3& value,  GLboolean useShader = false);
	void SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w,  GLboolean useShader = false);
	void SetUniformData(const GLchar* name, const glm::vec4& value,  GLboolean useShader = false);
	void SetUniformData(const GLchar* name, const glm::mat4& matrix,  GLboolean useShader = false);

	void BindTexture(const GLchar* name, GLenum textureType, GLenum textureNum, GLuint data);

private:
	// ID
	GLuint ID;
	//Name
	std::string name;

	void CreateUniform(const GLchar* name);

	GLuint GetTextureNum(GLenum textureNum);

	//helper methods
	bool ItemExists(std::string name);

	//name and location
	std::map<std::string, GLuint> uniforms;


};
#endif // !SHADER_H