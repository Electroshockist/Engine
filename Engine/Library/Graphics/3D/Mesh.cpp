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
	

	subMesh.material->SetupLocations();
}

void Mesh::Render(ACamera *c, std::vector<glm::mat4> &instances_){
	glUniform1i(diffuseMapLoc, 0);
	glActiveTexture(GL_TEXTURE0);

	Camera *camera = dynamic_cast<Camera *>(c);

	if(camera == nullptr){
		Debug::fatalError("Expected a 3D camera, but didn't find one.", __FILE__, __LINE__);
	}

	SetupUniforms(camera);

	for(size_t i = 0; i < instances_.size(); i++){
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(instances_[i]));
		glDrawArrays(GL_TRIANGLES, 0, subMesh.vertexList.size());
	}

	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Mesh::SetupUniforms(Camera *camera){
	try{
		GLuint diffuse = std::get<GLuint>(subMesh.material->GetParameter("diffuse")->parameter.data);
		glBindTexture(GL_TEXTURE_2D, diffuse);

		//TODO: replace with 
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->getView()));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera->getPerspective()));

		modelLoc = glGetUniformLocation(shaderProgram, "model");
		viewLoc = glGetUniformLocation(shaderProgram, "view");
		projLoc = glGetUniformLocation(shaderProgram, "proj");

		//camera
		camera->SetupParameters();

		//material
		subMesh.material->SetupParameters();

		glBindVertexArray(VAO);
	} catch(const std::bad_variant_access & e){
		Debug::error("Improper variant cast at parameter with name." + std::string(e.what()) + " This error should never occur.", __FILE__, __LINE__);
	}
}
