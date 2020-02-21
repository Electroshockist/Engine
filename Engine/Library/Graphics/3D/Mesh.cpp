#include "Mesh.h"

#include <glm/gtc/type_ptr.hpp>

Mesh::Mesh(SubMesh subMesh_, GLuint shaderProgram_)
	: VAO(0), VBO(0), shaderProgram(0){
	shaderProgram = shaderProgram_;
	subMesh = subMesh_;
	GenerateBuffers();
}

Mesh::~Mesh(){
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	subMesh.vertexList.clear();
	subMesh.meshIndices.clear();
}

void Mesh::GenerateBuffers(){
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, subMesh.vertexList.size() * sizeof(Vertex), &subMesh.vertexList[0], GL_STATIC_DRAW);

	//POSITION
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), static_cast<GLvoid *>(0));

	//NORMAL
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(offsetof(Vertex, normal)));

	//TEXTURE
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(offsetof(Vertex, texCoords)));

	//COLOR
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(offsetof(Vertex, colour)));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	modelLoc = glGetUniformLocation(shaderProgram, "model");
	viewLoc = glGetUniformLocation(shaderProgram, "view");
	projLoc = glGetUniformLocation(shaderProgram, "proj");

	viewPositionLoc = glGetUniformLocation(shaderProgram, "cameraPos");
	lightPosLoc = glGetUniformLocation(shaderProgram, "light.lightPos");
	lightAmbientLoc = glGetUniformLocation(shaderProgram, "light.ambientValue");
	lightDiffuseLoc = glGetUniformLocation(shaderProgram, "light.diffuseValue");
	lightColourLoc = glGetUniformLocation(shaderProgram, "light.color");

	diffuseMapLoc = glGetUniformLocation(shaderProgram, "material.diffuseMap");
	shineLoc = glGetUniformLocation(shaderProgram, "material.shininess");
	transparencyLoc = glGetUniformLocation(shaderProgram, "material.transparency");
	ambientLoc = glGetUniformLocation(shaderProgram, "material.ambient");
	diffuseLoc = glGetUniformLocation(shaderProgram, "material.diffuse");
	specLoc = glGetUniformLocation(shaderProgram, "material.specular");
}

void Mesh::Render(ACamera *camera, std::vector<glm::mat4> &instances_){
	glUniform1i(diffuseMapLoc, 0);
	glActiveTexture(GL_TEXTURE0);

	try{
		SetupUniforms();

		for(size_t i = 0; i < instances_.size(); i++){
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(instances_[i]));
			glDrawArrays(GL_TRIANGLES, 0, subMesh.vertexList.size());
		}

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, 0);

	} catch(const std::bad_variant_access & e){
		Debug::error("Improper variant cast at parameter with name." + e.what() + " This error should never occur.", __FILE__, __LINE__);
	}
}

void Mesh::SetupUniforms(){

	GLuint diffuse = std::get<GLuint>(subMesh.material.getParameterPair("diffuse")->second.data);
	glBindTexture(GL_TEXTURE_2D, diffuse);

	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->getView()));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera->getPerspective()));

	glm::vec3 copyCamPos = camera->getPosition();
	glm::vec3 copyLightPos = camera->getLightSources()[0]->GetPosition();
	glm::vec3 copyLightColor = camera->getLightSources()[0]->GetColour();

	glUniform3f(viewPositionLoc, copyCamPos.x, copyCamPos.y, copyCamPos.z);
	glUniform3f(lightPosLoc, copyLightPos.x, copyLightPos.y, copyLightPos.z);
	glUniform1f(lightAmbientLoc, camera->getLightSources()[0]->GetAmbientValue());
	glUniform1f(lightDiffuseLoc, camera->getLightSources()[0]->GetDiffuseValue());
	glUniform3f(lightColourLoc, copyLightColor.x, copyLightColor.y, copyLightColor.z);

	//material
	subMesh.material.setupParameters();

	glBindVertexArray(VAO);
}
