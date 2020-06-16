#ifndef PARTICLE_H
#define PARTICLE_H


#include <vector>

#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include "../Graphics/Shaders/Shader.h"
#include "../GameObject/AComponent.h"
//#include "Texture2D.h"

// Represents a single particle and its state
struct Particle{
	glm::vec3  velocity;
	GLfloat	lifeTime;	//total time allowed to live

	Particle() : velocity(0.0f), lifeTime(0.0f){}
};

struct ParticleGenerator: public AComponent{
	// Constructor
	ParticleGenerator(glm::vec3 position, GLuint amount, std::string texture);
	//Destructor
	~ParticleGenerator();

	// Render all vertices
	void Render(class Camera* c, const float elapsedTime);

	glm::vec3 position;
private:
	// State
	std::vector<Particle> vertices;
	//amount of vertices
	GLuint amount;
	// Render state
	Shader* shader;
	//GLuint texture;
	GLuint VAO, VBO;
	//Texture
	GLuint texture;

	Particle newParticle(const int offset = 0) const;
	void GenerateBuffers();
};

#endif