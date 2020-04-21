#include "Particle.h"

#include "../Graphics/Textures/TextureManager.h"

ParticleGenerator::ParticleGenerator(Shader* shader, std::string textureFile, GLuint amount)
	: shader(shader), amount(amount){

	auto loadTexture = [](std::string file){
		GLuint currentTexture = TextureManager::GetInstance()->GetTexture(file);
		if(currentTexture == 0){
			TextureManager::GetInstance()->CreateTexture(file, "Resources/Textures/" + file + ".jpg");
			currentTexture = TextureManager::GetInstance()->GetTexture(file);
		}
		return currentTexture;
	};

	texture = loadTexture(textureFile);

	this->init();
}

void ParticleGenerator::Update(GLfloat dt, glm::vec3 position, glm::vec3 velocity, GLuint newParticles, glm::vec3 offset){
	// Add new particles 
	for(GLuint i = 0; i < newParticles; ++i){
		int unusedParticle = this->firstUnusedParticle();
		this->respawnParticle(this->particles[unusedParticle], position, offset);
	}
	// Update all particles
	for(GLuint i = 0; i < this->amount; ++i){
		Particle& p = this->particles[i];
		p.Life -= dt; // reduce life
		if(p.Life > 0.0f){	// particle is alive, thus update
			p.Position -= p.Velocity * dt;
			p.Color.a -= dt * 2.5;
		}
	}
}

//// Render all particles
void ParticleGenerator::Draw(){
	// Use additive blending to give it a 'glow' effect
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	shader->Use();
	for(Particle particle : this->particles){
		if(particle.Life > 0.0f){
			shader->BindTexture("sprite", GL_TEXTURE_2D, 0, texture);

			shader->SetUniformData("offset", particle.Position.x, particle.Position.y);
			shader->SetUniformData("color", particle.Color.x, particle.Color.y, particle.Color.z, particle.Color.w);

			//cleanup
			glBindTexture(GL_TEXTURE_2D, 0);
			glBindVertexArray(this->VAO);
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray(0);
		}
	}
	// Don't forget to reset to default blending mode
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void ParticleGenerator::init(){
	// Set up mesh and attribute properties
	GLuint VBO;
	GLfloat particle_quad[] = {
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(this->VAO);

	// Fill mesh buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(particle_quad), particle_quad, GL_STATIC_DRAW);
	// Set mesh attributes
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glBindVertexArray(0);

	// Create this->amount default particle instances
	for(GLuint i = 0; i < this->amount; ++i)
		this->particles.push_back(Particle());
}


GLuint ParticleGenerator::firstUnusedParticle(){
	// Stores the index of the last particle used (for quick access to next dead particle)
	GLuint lastUsedParticle = 0;
	// First search from last used particle, this will usually return almost instantly
	for(GLuint i = lastUsedParticle; i < this->amount; ++i){
		if(this->particles[i].Life <= 0.0f){
			lastUsedParticle = i;
			return i;
		}
	}
	// Otherwise, do a linear search
	for(GLuint i = 0; i < lastUsedParticle; ++i){
		if(this->particles[i].Life <= 0.0f){
			lastUsedParticle = i;
			return i;
		}
	}
	// All particles are taken, override the first one (note that if it repeatedly hits this case, more particles should be reserved)
	lastUsedParticle = 0;
	return 0;
}

void ParticleGenerator::respawnParticle(Particle& particle, glm::vec3 position, glm::vec3 velocity, glm::vec3 offset){
	GLfloat random = ((rand() % 100) - 50) / 10.0f;
	GLfloat rColor = 0.5 + ((rand() % 100) / 100.0f);
	particle.Position = position + random + offset;
	particle.Color = glm::vec4(rColor, rColor, rColor, 1.0f);
	particle.Life = 1.0f;
	particle.Velocity = velocity;
}
