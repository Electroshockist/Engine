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

	//create particles
	for(size_t i = 0; i < amount; i++){
		particles.push_back(newParticle(i));
	}

	GenerateBuffers();
}

ParticleGenerator::~ParticleGenerator(){
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

// Render all particles
void ParticleGenerator::Render(Camera* c, const float elapsedTime){
	shader->Use();

	shader->SetUniformData("view", c->GetView());
	shader->SetUniformData("proj", c->GetPerspective());
	shader->SetUniformData("position", position);
	shader->SetUniformData("elapsedTime", elapsedTime);

	//camera
	shader->SetUniformData("cameraPos", c->GetPosition());
	shader->SetUniformData("light.lightPos", c->GetLightSources()[0]->GetPosition());
	shader->SetUniformData("light.color", c->GetLightSources()[0]->GetColour());
	shader->SetUniformData("material.ambient", c->GetLightSources()[0]->GetAmbientValue());
	shader->SetUniformData("material.diffuse", c->GetLightSources()[0]->GetDiffuseValue());

	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, amount);

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
	glBufferData(GL_ARRAY_BUFFER, amount * sizeof(Particle), &particles[0], GL_STATIC_DRAW);

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