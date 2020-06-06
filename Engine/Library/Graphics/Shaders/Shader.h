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
	void SetUniformData(const GLchar* name, GLfloat value, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, GLint value, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, GLfloat x, GLfloat y, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const glm::vec2& value, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const glm::vec3& value, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const glm::vec4& value, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const glm::mat4& matrix, bool performUniformCheck = true, bool useShader = false);

	void BindTexture(const GLchar* name, GLenum textureType, GLenum textureNum, GLuint data);

private:
	// ID
	GLuint ID;
	//Name
	std::string name;

	void CreateUniform(const GLchar* name);

	static GLuint GetTextureNum(GLenum textureNum);

	//helper methods
	bool ItemExists(std::string name) const;

	//name and location
	std::map<std::string, GLuint> uniforms;


};
#endif // !SHADER_H