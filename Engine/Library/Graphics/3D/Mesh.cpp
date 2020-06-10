//#include "Mesh.h"
//
//#include <glm/gtc/type_ptr.hpp>
//
//Mesh::Mesh(SubMesh subMesh_, GLuint shaderProgram_)
//	: VAO(0), VBO(0), shaderProgram(0){
//	shaderProgram = shaderProgram_;
//	subMesh = subMesh_;
//	GenerateBuffers();
//}
//
//Mesh::~Mesh(){
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	subMesh.vertexList.clear();
//	subMesh.meshIndices.clear();
//}
//
//void Mesh::GenerateBuffers(){
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//	glBufferData(GL_ARRAY_BUFFER, subMesh.vertexList.size() * sizeof(Vertex), &subMesh.vertexList[0], GL_STATIC_DRAW);
//
//	//POSITION
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), static_cast<GLvoid *>(0));
//
//	//NORMAL
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(offsetof(Vertex, normal)));
//
//	//TEXTURE
//	glEnableVertexAttribArray(2);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(offsetof(Vertex, texCoords)));
//
//	//COLOR
//	glEnableVertexAttribArray(3);
//	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(offsetof(Vertex, colour)));
//
//	glBindVertexArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);	
//
//	subMesh.material->SetupLocations();
//}
//
//void Mesh::Render(Camera* camera, std::vector<glm::mat4> &instances_){
//	SetupUniforms(camera);
//	glActiveTexture(GL_TEXTURE0);
//
//	for(size_t i = 0; i < instances_.size(); i++){
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(instances_[i]));
//		glDrawArrays(GL_TRIANGLES, 0, subMesh.vertexList.size());
//	}
//
//	glBindVertexArray(0);
//
//	glBindTexture(GL_TEXTURE_2D, 0);
//}
//
//void Mesh::SetupUniforms(Camera* camera){
//	try{
//		GLuint diffuse = std::get<GLuint>(subMesh.material->GetParameter("diffuse")->parameter.data);
//		glBindTexture(GL_TEXTURE_2D, diffuse);
//
//		//TODO: replace with 
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->GetView()));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera->getPerspective()));
//
//		modelLoc = glGetUniformLocation(shaderProgram, "model");
//		viewLoc = glGetUniformLocation(shaderProgram, "view");
//		projLoc = glGetUniformLocation(shaderProgram, "proj");
//
//		//camera
//		camera->SetupParameters();
//
//		//material
//		subMesh.material->SetupParameters();
//
//		glBindVertexArray(VAO);
//	} catch(const std::bad_variant_access & e){
//		Debug::error("Improper variant cast at parameter with name." + std::string(e.what()) + " This error should never occur.", __FILE__, __LINE__);
//	}
//}

#include "Mesh.h"

Mesh::Mesh(SubMesh subMesh_, Shader * shaderProgram_)
	: VAO(0), VBO(0), shaderProgram(nullptr){
	shaderProgram = shaderProgram_;
	subMesh = subMesh_;
	GenerateBuffers();
}

Mesh::~Mesh(){
	OnDestroy();
}

void Mesh::GenerateBuffers(){
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//tell the gpu where to draw each vertex, the size of each vertex, the list of vertices and how to draw it
	glBufferData(GL_ARRAY_BUFFER, subMesh.vertexList.size() * sizeof(Vertex), &subMesh.vertexList[0], GL_STATIC_DRAW);

	//POSITION
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), static_cast<void*>(0));

	//NORMAL
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, normal)));

	//TEXTURE
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, texCoords)));

	//COLOR
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, colour)));

	//stop editing the VBO and VAO
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::Render(Camera* camera, std::vector<glm::mat4> &instances_){
	shaderProgram->Use();
	shaderProgram->BindTexture("material.diffuseMap", GL_TEXTURE_2D, GL_TEXTURE0, subMesh.material.diffuseMap);

	shaderProgram->SetUniformData("view", camera->GetView());
	shaderProgram->SetUniformData("proj", camera->GetPerspective());

	//camera
	shaderProgram->SetUniformData("cameraPos", camera->GetPosition());
	shaderProgram->SetUniformData("light.lightPos", camera->GetLightSources()[0]->GetPosition());
	shaderProgram->SetUniformData("light.color", camera->GetLightSources()[0]->GetColour());
	shaderProgram->SetUniformData("material.ambient", camera->GetLightSources()[0]->GetAmbientValue());
	shaderProgram->SetUniformData("material.diffuse", camera->GetLightSources()[0]->GetDiffuseValue());

	//material
	shaderProgram->SetUniformData("material.shininess", subMesh.material.shine);
	shaderProgram->SetUniformData("material.transparency", subMesh.material.transparency);
	shaderProgram->SetUniformData("material.ambient", subMesh.material.ambient);
	shaderProgram->SetUniformData("material.diffuse", subMesh.material.diffuse);
	shaderProgram->SetUniformData("material.specular", subMesh.material.specular);

	glBindVertexArray(VAO);

	for(int i = 0; i < instances_.size(); i++){
		shaderProgram->SetUniformData("model", instances_[i]);
	}

	glDrawArrays(GL_TRIANGLES, 0, subMesh.vertexList.size());

	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Mesh::OnDestroy(){
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	subMesh.vertexList.clear();
	subMesh.meshIndices.clear();
}
