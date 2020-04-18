#include "SkyBox.h"

#include <GLEW/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <SDL/SDL_image.h>

#include "../Shaders/ShaderManager.h"

glm::mat4 SkyBox::getTransform(float angle, glm::vec3 rotation){
	return glm::rotate(modelInstance, angle, rotation);
}

void SkyBox::loadModel(){
	subMesh = obj->getSubMeshes()[0];
	GenerateBuffers();

	delete obj;
	obj = nullptr;
}

SkyBox::~SkyBox(){}

bool SkyBox::onCreate(){
	shaderProgram = ShaderManager::getShader("skyShader");
	obj = new ModelLoader();

	obj->loadModel("./Resources/Models/cube.obj");
	this->loadModel();

	glGenTextures(1, &subMesh.material.diffuseMap);
	glBindTexture(GL_TEXTURE_CUBE_MAP, subMesh.material.diffuseMap);

	LoadTextures("./Resources/Textures/CN Tower/posx.jpg",
				 "./Resources/Textures/CN Tower/negx.jpg",
				 "./Resources/Textures/CN Tower/posy.jpg",
				 "./Resources/Textures/CN Tower/negy.jpg",
				 "./Resources/Textures/CN Tower/posz.jpg",
				 "./Resources/Textures/CN Tower/negz.jpg");

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	//unbind texture
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	return true;
}

bool SkyBox::LoadTextures(const char * posX, const char * negX, const char * posY, const char * negY, const char * posZ, const char * negZ){
	//posX
	SDL_Surface *textureSurface = IMG_Load(posX);
	if(textureSurface == nullptr){
		return false;
	}
	int mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);

	//negX
	textureSurface = IMG_Load(negX);
	if(textureSurface == nullptr){
		return false;
	}
	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);

	//posY
	textureSurface = IMG_Load(posY);
	if(textureSurface == nullptr){
		return false;
	}
	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);

	//negY
	textureSurface = IMG_Load(negY);
	if(textureSurface == nullptr){
		return false;
	}
	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);
	//posZ
	textureSurface = IMG_Load(posZ);
	if(textureSurface == nullptr){
		return false;
	}
	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);

	//negZ
	textureSurface = IMG_Load(negZ);
	if(textureSurface == nullptr){
		return false;
	}
	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);

	return true;
}

void SkyBox::createInstance(float angle, glm::vec3 rotation){
	modelInstance = getTransform(angle, rotation);
}

void SkyBox::onMouseMove(int x, int y){

}

void SkyBox::GenerateBuffers(){
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, subMesh.vertexList.size() * sizeof(Vertex), &subMesh.vertexList[0], GL_STATIC_DRAW);

	//POSITION
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), static_cast<GLvoid*>(0));

	//NORMAL
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(offsetof(Vertex, normal)));

	//TEXTURE
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(offsetof(Vertex, texCoords)));

	//COLOR
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(offsetof(Vertex, colour)));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void SkyBox::Render(Camera* camera){
	shaderProgram->Use();

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_CUBE_MAP, subMesh.material.diffuseMap);

	RenderMesh(camera);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	glUseProgram(0);
}

void SkyBox::RenderMesh(Camera * camera){
	shaderProgram->SetUniformData("proj", camera->GetPerspective());
	shaderProgram->SetUniformData("model", modelInstance * camera->GetRotationmatrix());
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, subMesh.vertexList.size());

	glBindVertexArray(0);
}
