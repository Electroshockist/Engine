#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <map>

#include <glew/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


struct Shader{
	// Constructor
	Shader(){}
	//ID getter
	inline const GLuint& GetID() const{
		return ID;
	}
	// Sets the current shader as active
	Shader& Use();
	// Utility functions
	void SetFloat(const GLchar* name, GLfloat value, bool overwrite = false, GLboolean useShader = false);
	void SetInteger(const GLchar* name, GLint value, GLboolean useShader = false);
	void SetVector2f(const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader = false);
	void SetVector2f(const GLchar* name, const glm::vec2& value, GLboolean useShader = false);
	void SetVector3f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader = false);
	void SetVector3f(const GLchar* name, const glm::vec3& value, GLboolean useShader = false);
	void SetVector4f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader = false);
	void SetVector4f(const GLchar* name, const glm::vec4& value, GLboolean useShader = false);
	void SetMatrix4(const GLchar* name, const glm::mat4& matrix, GLboolean useShader = false);

	float* GetFloat(const GLchar* name);
	int* GetInteger(const GLchar* name);
	void SetVector2f(const GLchar* name);
	void SetVector2f(const GLchar* name);
	void SetVector3f(const GLchar* name);
	void SetVector3f(const GLchar* name);
	void SetVector4f(const GLchar* name);
	void SetVector4f(const GLchar* name);
	void SetMatrix4(const GLchar* name);

private:
	// ID
	GLuint ID;
	//Name
	std::string name;

	enum class Type{
		FLOAT,
		INT,
		VEC2,
		VEC3,
		VEC4,
		MAT4
	};

	inline std::string ToString(Type type){
		switch(type){
			case Type::FLOAT:
				return "float";
			case Type::INT:
				return "int";
			default:
				return "error";
		}
	}

	bool Gettable(std::string name, Type type);
	bool Settable(std::string name, Type type, bool overwrite);

	std::map<std::string, Type> contentMap;

	std::map<std::string, float> floats;
	std::map<std::string, int> ints;
	std::map<std::string, glm::vec2> vec2s;
	std::map<std::string, glm::vec3> vec3s;
	std::map<std::string, glm::vec4> vec4s;
	std::map<std::string, glm::mat4> mat4s;


};
#endif // !SHADER_H