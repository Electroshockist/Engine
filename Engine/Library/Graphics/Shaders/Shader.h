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
	///floats
	///glUniform1f
	void SetUniformData(const GLchar* name, GLfloat value, bool performUniformCheck = true, bool useShader = false);
	///glUniform2f
	void SetUniformData(const GLchar* name, GLfloat x, GLfloat y, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const glm::vec2& value, bool performUniformCheck = true, bool useShader = false);
	///glUinform3f
	void SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const glm::vec3& value, bool performUniformCheck = true, bool useShader = false);
	///glUniform4f
	void SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const glm::vec4& value, bool performUniformCheck = true, bool useShader = false);

	///ints
	///glUniform1i
	void SetUniformData(const GLchar* name, GLint value, bool performUniformCheck = true, bool useShader = false);
	///glUniform2i
	void SetUniformData(const GLchar* name, GLint x, GLint y, bool performUniformCheck = true, bool useShader = false);
	///glUniform3i
	void SetUniformData(const GLchar* name, GLint x, GLint y, GLint z, bool performUniformCheck = true, bool useShader = false);
	///glUniform4i
	void SetUniformData(const GLchar* name, GLint x, GLint y, GLint z, GLint w, bool performUniformCheck = true, bool useShader = false);

	///unsigned ints
	///glUniform1ui
	void SetUniformData(const GLchar* name, GLuint value, bool performUniformCheck = true, bool useShader = false);
	///glUniform2ui
	void SetUniformData(const GLchar* name, GLuint x, GLuint y, bool performUniformCheck = true, bool useShader = false);
	///glUniform3ui
	void SetUniformData(const GLchar* name, GLuint x, GLuint y, GLuint z, bool performUniformCheck = true, bool useShader = false);
	///glUniform4ui
	void SetUniformData(const GLchar* name, GLuint x, GLuint y, GLuint z, GLuint w, bool performUniformCheck = true, bool useShader = false);
	
	void SetUniformData(const GLchar* name, const GLfloat *value, const GLenum type, int vectorSize = 1, GLsizei count = 1, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const GLint *value, const GLenum type, int vectorSize = 1, GLsizei count = 1, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const GLuint *value, const GLenum type, int vectorSize = 1, GLsizei count = 1, bool performUniformCheck = true, bool useShader = false);

	void SetUniformData(const GLchar* name, const glm::mat4& matrix, bool performUniformCheck = true, bool useShader = false);
	/*void glUniform1fv(GLint location,
					  GLsizei count,
					  const GLfloat *value);

	void glUniform2fv(GLint location,
					  GLsizei count,
					  const GLfloat *value);

	void glUniform3fv(GLint location,
					  GLsizei count,
					  const GLfloat *value);

	void glUniform4fv(GLint location,
					  GLsizei count,
					  const GLfloat *value);

	void glUniform1iv(GLint location,
					  GLsizei count,
					  const GLint *value);

	void glUniform2iv(GLint location,
					  GLsizei count,
					  const GLint *value);

	void glUniform3iv(GLint location,
					  GLsizei count,
					  const GLint *value);

	void glUniform4iv(GLint location,
					  GLsizei count,
					  const GLint *value);

	void glUniform1uiv(GLint location,
					   GLsizei count,
					   const GLuint *value);

	void glUniform2uiv(GLint location,
					   GLsizei count,
					   const GLuint *value);

	void glUniform3uiv(GLint location,
					   GLsizei count,
					   const GLuint *value);

	void glUniform4uiv(GLint location,
					   GLsizei count,
					   const GLuint *value);

	void glUniformMatrix2fv(GLint location,
							GLsizei count,
							GLboolean transpose,
							const GLfloat *value);

	void glUniformMatrix3fv(GLint location,
							GLsizei count,
							GLboolean transpose,
							const GLfloat *value);

	void glUniformMatrix4fv(GLint location,
							GLsizei count,
							GLboolean transpose,
							const GLfloat *value);

	void glUniformMatrix2x3fv(GLint location,
							  GLsizei count,
							  GLboolean transpose,
							  const GLfloat *value);

	void glUniformMatrix3x2fv(GLint location,
							  GLsizei count,
							  GLboolean transpose,
							  const GLfloat *value);

	void glUniformMatrix2x4fv(GLint location,
							  GLsizei count,
							  GLboolean transpose,
							  const GLfloat *value);

	void glUniformMatrix4x2fv(GLint location,
							  GLsizei count,
							  GLboolean transpose,
							  const GLfloat *value);

	void glUniformMatrix3x4fv(GLint location,
							  GLsizei count,
							  GLboolean transpose,
							  const GLfloat *value);

	void glUniformMatrix4x3fv(GLint location,
							  GLsizei count,
							  GLboolean transpose,
							  const GLfloat *value);*/

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