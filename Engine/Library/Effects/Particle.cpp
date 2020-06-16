#include "Particle.h"

#include <time.h>

#include "../Graphics/Textures/TextureManager.h"
#include "../Graphics/Camera/3D/Camera.h"
#include "../Graphics/Shaders/ShaderManager.h"
#include "../Math/Randomizer.h"

ParticleGenerator::ParticleGenerator(glm::vec3 position, GLuint amount, std::string texture)
	: amount(amount), position(position){

	//set shader
	shader = ShaderManager::GetInstance()->getShader("particleShader");

	this->texture = TextureManager::GetInstance()->LoadTexture(texture);

	//create vertices
	for(size_t i = 0; i < amount; i++){
		Particle p = newParticle(i);
		for(size_t j = 0; j < 4; j++){
			vertices.push_back(p);
		}
	}

	GenerateBuffers();
}

ParticleGenerator::~ParticleGenerator(){
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

// Render all vertices
void ParticleGenerator::Render(Camera* c, const float elapsedTime){
	shader->Use();

	shader->BindTexture("image", GL_TEXTURE_2D, GL_TEXTURE0, texture);

	shader->SetUniformData("cameraMat", c->GetPerspective() * c->GetView());
	shader->SetUniformData("position", position);
	shader->SetUniformData("elapsedTime", elapsedTime);

	glBindVertexArray(VAO);

	glDrawArrays(GL_QUADS, 0, vertices.size());

	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0);
}

Particle ParticleGenerator::newParticle(const int offset) const{
	Particle p;
	GLuint i = offset;

	#define R(i) Randomizer(time(nullptr) + i)
	p.velocity = glm::vec3(R(i++).rand(-1.0f, 1.0f), R(i++).rand(1.0f, 3.0f), R(i++).rand(-1.0f, 1.0f));
	p.lifeTime = R(i++).rand(2.0f, 5.0f);
	#undef R

	return p;
}

void ParticleGenerator::GenerateBuffers(){
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//tell the gpu where to draw each vertex, the size of each vertex, the list of vertices and how to draw it
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Particle), &vertices[0], GL_STATIC_DRAW);

	//Initial Velocity
	//the initial velocity is at the 0th vertex index in the gpu, is a vec3(float), each one is offset by the entire size of a particle and is the first item in a particle
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Particle), static_cast<void*>(0));

	//LifeTime
	//the lifetime is at the 1st vertex index in the gpu, is a vec3(float), each one is offset by the entire size of a particle and is the variable called "lifetime"
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)(offsetof(Particle, lifeTime)));

	//stop editing the VBO and VAO
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}