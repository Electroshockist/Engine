#ifndef MESH_H
#define MESH_H

#include <vector>

#include "UniformParameter.h"
#include "../../Graphics/Camera/3D/Camera.h"
#include "../../Graphics/Materials/MaterialManager.h"
#include "../Shaders/Shader.h"

struct Vertex{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
	glm::vec3 colour;
};

struct SubMesh{
	std::vector<Vertex> vertexList;
	std::vector<int> meshIndices;
	Material material;
};

class Mesh : public AComponent{
	void GenerateBuffers();
	GLuint VAO, VBO;
	Shader * shaderProgram;
	SubMesh subMesh;

public:
	std::vector<UniformParameter> uniforms;

	Mesh(SubMesh submesh, Shader * shaderProgram);
	~Mesh();

	void Render(Camera* camera, std::vector<glm::mat4> &instances_);
	void Destroy();
};

#endif // !MESH_H