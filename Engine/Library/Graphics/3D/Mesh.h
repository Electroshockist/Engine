#ifndef MESH_H
#define MESH_H

#include <GLEW/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include "AMesh.h"
#include "../../Graphics/MaterialHandler.h"
#include "../Camera/Camera.h"

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

class Mesh : AMesh{
	void GenerateBuffers();
	GLuint VAO, VBO;
	std::vector<Vertex> vertexList;
	GLuint shaderProgram;
	GLuint modelLoc, viewLoc, projLoc;
	GLuint viewPositionLoc, lightPosLoc, lightAmbientLoc, lightDiffuseLoc, lightColourLoc;
	GLuint diffuseMapLoc, shineLoc, transparencyLoc, ambientLoc, diffuseLoc, specLoc;
	SubMesh subMesh;


public:
	Mesh(SubMesh submesh, GLuint shaderProgram);
	~Mesh();

	void Render(ACamera *camera, std::vector<glm::mat4> &instance) override;
};

#endif // !MESH_H