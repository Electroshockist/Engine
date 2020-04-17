#ifndef SHADERHANDLER_H
#define SHADERHANDLER_H

#include <sstream>
#include <map>
#include <vector>
#include <memory>
#include <GLEW/glew.h>
#include "Shader.h"

#include "../../Debugging/Debug.h"

class ShaderManager{
	ShaderManager();
	~ShaderManager();

	static std::unique_ptr<ShaderManager> shaderInstance;
	friend std::default_delete<ShaderManager>;
	static std::map<std::string, Shader> programs;

	std::string readShader(const std::string& fileName);

	GLuint createShader(GLenum shadertype,
						const std::string& source,
						const std::string& shaderName
	);

public:
	//delete constructors for singleton
	ShaderManager(const ShaderManager&) = delete;
	ShaderManager(ShaderManager&&) = delete;
	ShaderManager& operator=(const ShaderManager&) = delete;
	ShaderManager& operator=(ShaderManager&&) = delete;
	void createProgram(const std::string& shaderName,
					   const std::string& vertexShaderFileName,
					   const std::string& fragmentShaderFileName);
	static Shader * getShader(const std::string & shaderName);

	static ShaderManager* GetInstance();
};

#endif //SHADERHANDLER_H

