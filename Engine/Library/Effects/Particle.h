#ifndef PARTICLE_H
#define PARTICLE_H


#include <vector>

#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include "../Graphics/Shaders/Shader.h"
#include "../GameObject/AComponent.h"
#include "../Graphics/3D/Model.h"
#include "Texture2D.h"

// Represents a single particle and its state
struct Particle{
	glm::vec3  velocity;
	GLfloat aliveTime;	//time spent alive
	GLfloat	totalLife;	//total time allowed to live

	Particle() : velocity(0.0f), aliveTime(0.0f), totalLife(0.0f){}
};

struct ParticleGenerator : public AComponent{
	//// Constructor
	ParticleGenerator(const std::string& objPath_, const std::string& matPath_, GLuint amount, glm::vec3 position = glm::vec3(), GLfloat gravityScale = 1.0f);
	//// Update all particles
	void Update(GLfloat deltaTime);
	// Render all particles
	void Render(class Camera* c);

	glm::vec3 position;
	GLfloat gravityScale;
private:
	// State
	std::vector<Particle> particles;

	GLuint amount;
	// Render state
	Shader* shader;
	//GLuint texture;
	GLuint VAO;

	//Model
	Model* model;

	//// Initializes buffer and vertex attributes
	//void init();
	// Returns the first ParticleGenerator index that's currently unused e.g. Life <= 0.0f or 0 if no particle is currently inactive
	GLuint firstUnusedParticle();

	Particle newParticle();
};

#endif