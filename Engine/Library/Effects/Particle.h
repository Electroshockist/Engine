#ifndef PARTICLE_H
#define PARTICLE_H


#include <vector>

#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include "../Graphics/Shaders/Shader.h"
#include "Texture2D.h"

// Represents a single particle and its state
struct Particle{
	glm::vec2 Position, Velocity;
	glm::vec4 Color;
	GLfloat Life;

	Particle() : Position(0.0f), Velocity(0.0f), Color(1.0f), Life(0.0f){}
};

struct ParticleGenerator{
	//// Constructor
	ParticleGenerator(Shader* shader, std::string textureFile, GLuint amount);
	//// Update all particles
	void Update(GLfloat dt, glm::vec3 position, glm::vec3 velocity, GLuint newParticles, glm::vec3 offset);
	// Render all particles
	void Draw();
private:
	// State
	std::vector<Particle> particles;
	GLuint amount;
	// Render state
	Shader* shader;
	GLuint texture;
	GLuint VAO;
	// Initializes buffer and vertex attributes
	void init();
	// Returns the first ParticleGenerator index that's currently unused e.g. Life <= 0.0f or 0 if no particle is currently inactive
	GLuint firstUnusedParticle();
	// Respawns particle
	void respawnParticle(Particle& particle, glm::vec3 position, glm::vec3 velocity, glm::vec3 offset = glm::vec3());
};

#endif