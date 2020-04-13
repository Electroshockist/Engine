#include "ShaderManager.h"

std::unique_ptr<ShaderManager> ShaderManager::shaderInstance = nullptr;

std::map<std::string, GLuint> ShaderManager::programs = std::map<std::string, GLuint>();


ShaderManager::ShaderManager(){}

ShaderManager::~ShaderManager(){
	if(programs.size() != 0){
		for(auto index : programs){
			glDeleteProgram(index.second);
		}
		programs.clear();
	}
}

std::string ShaderManager::readShader(const std::string & fileName){
	std::string shaderCode;
	std::ifstream file;
	file.exceptions(std::ifstream::badbit);
	try{
		file.open(fileName.c_str());
		std::stringstream tmpStream;
		tmpStream << file.rdbuf();
		file.close();
		shaderCode = tmpStream.str();
	} catch(const std::ifstream::failure error){
		Debug::error("Could not read shader at " + fileName, __FILE__, __LINE__);
		return "";
	}
	return shaderCode;
}

GLuint ShaderManager::createShader(GLenum shaderType, const std::string & source, const std::string & shaderName){
	GLint compileResult = 0;

	GLuint shader = glCreateShader(shaderType);
	const char* shaderCode = source.c_str();
	const GLint shaderSize = source.size();
	glShaderSource(shader, 1, &shaderCode, &shaderSize);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

	if(!compileResult){
		GLsizei errorLogSize = 0;
		std::string errorLog;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errorLogSize);
		errorLog.resize(errorLogSize);
		glGetShaderInfoLog(shader, errorLogSize, &errorLogSize, &errorLog[0]);
		Debug::error("Shader " + shaderName + " failed to compile. " + errorLog, __FILE__, __LINE__);
		std::cout << "Shader " << shaderName << " failed to compile:\n" << errorLog << std::endl;
	}

	return shader;
}

ShaderManager * ShaderManager::GetInstance(){
	if(shaderInstance.get() == nullptr){
		shaderInstance.reset(new ShaderManager());
	}
	return shaderInstance.get();
}

void ShaderManager::createProgram(const std::string & shaderName, const std::string & vertexShaderFileName, const std::string & fragmentShaderFileName){
	std::string vertexShaderCode = readShader(vertexShaderFileName);
	std::string fragmentShaderCode = readShader(fragmentShaderFileName);

	GLuint vertexShader = createShader(GL_VERTEX_SHADER, vertexShaderCode, shaderName);
	GLuint fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentShaderCode, shaderName);

	GLint linkResult = 0;
	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &linkResult);

	if(!linkResult){
		GLint logLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> programLog(logLength);
		glGetProgramInfoLog(program, logLength, NULL, &programLog[0]);
		std::string logString(programLog.begin(), programLog.end());
		Debug::error("Shader " + shaderName + " failed to link. " + programLog[0], __FILE__, __LINE__);
		return;
	}
	programs[shaderName] = program;
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	int count;
	glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &count);

	std::cout << shaderName << " has " << count << " active uniforms" << std::endl;

	int maxUniformNameLength;
	glGetProgramiv(program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxUniformNameLength);

	char* name = (char*)malloc(sizeof(char) * maxUniformNameLength);

	GLsizei actualLen;
	GLint size;
	GLenum type;

	for(size_t i = 0; i < count; i++){
		glGetActiveUniform(program, i, maxUniformNameLength, &actualLen, &size, &type, name);
		const unsigned int loc = glGetUniformLocation(program, name);

		std::string uniformName = name;

		printf("\"%s\" loc:%d\n", uniformName.c_str(), loc);
	}
	std::cout << std::endl;
}

const GLuint ShaderManager::getShader(const std::string & shaderName){
	if(programs.find(shaderName) != programs.end()){
		return programs[shaderName];
	}
	return 0;
}
