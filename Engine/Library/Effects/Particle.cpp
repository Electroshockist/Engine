#include "Particle.h"

#include <time.h>

#include "../Graphics/Textures/TextureManager.h"
#include "../Graphics/Camera/3D/Camera.h"
#include "../Graphics/Shaders/ShaderManager.h"
#include "../Math/Randomizer.h"

ParticleGenerator::ParticleGenerator(const std::string& objPath_, const std::string& matPath_, GLuint amount, glm::vec3 position, GLfloat gravityScale)
	: amount(amount), position(position), gravityScale(gravityScale){

	//auto loadTexture = [](std::string file){
	//	GLuint currentTexture = TextureManager::GetInstance()->GetTexture(file);
	//	if(currentTexture == 0){
	//		TextureManager::GetInstance()->CreateTexture(file, "Resources/Textures/" + file + ".jpg");
	//		currentTexture = TextureManager::GetInstance()->GetTexture(file);
	//	}
	//	return currentTexture;
	//};

	//texture = loadTexture(textureFile);

	//this->init();

	shader = ShaderManager::GetInstance()->getShader("basicShader");
	model = new Model(objPath_, matPath_, shader);

	for(size_t i = 0; i < amount; i++){
		particles.push_back(newParticle());
	}
}

void ParticleGenerator::Update(GLfloat deltaTime){

	for(size_t i = 0; i < particles.size(); i++){
		Particle& p = particles[i];
		p.aliveTime += deltaTime;

		//if particle needs to die, replace it with new random particle
		if(p.aliveTime >= p.totalLife){
			p = newParticle();
		}
	}
	//// Add new particles 
	//for(GLuint i = 0; i < newParticles; ++i){
	//	int unusedParticle = this->firstUnusedParticle();
	//	this->respawnParticle(this->particles[unusedParticle], position, offset);
	//}
	//// Update all particles
	//for(GLuint i = 0; i < this->amount; ++i){
	//	Particle& p = this->particles[i];
	//	p.Life += dt; // reduce aliveTime
	//	if(p.Life > 0.0f){	// particle is alive, thus update
	//		p.Position -= p.Velocity * dt;
	//		p.Color.a -= dt * 2.5;
	//	}
	//}
}

//// Render all particles
void ParticleGenerator::Render(Camera* c){
	// Use additive blending to give it a 'glow' effect
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	shader->Use();

	//each particle's base offset is the particle emmiter's position
	shader->SetUniformData("offset", position);
	shader->SetUniformData("gravityScale", gravityScale);

	int i = 0;
	for(Particle& particle : this->particles){
		//shader->BindTexture("sprite", GL_TEXTURE_2D, 0, texture);
		std::cout << i++ << std::endl;
		//shader->SetUniformData("projection", c->GetPerspective());
		//shader->SetUniformData("offset", particle.Position.x, particle.Position.y);
		//shader->SetUniformData("color", particle.Color.x, particle.Color.y, particle.Color.z, particle.Color.w);

		shader->SetUniformData("elapsedTime", particle.aliveTime);
		shader->SetUniformData("initialVelocity", particle.velocity);

		model->Render(dynamic_cast<ACamera*>(c));

		//cleanup
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindVertexArray(this->VAO);
		glDrawArrays(GL_QUADS, 0, 6);
		glBindVertexArray(0);
	}
	// Don't forget to reset to default blending mode
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

//void ParticleGenerator::init(){
//	// Set up mesh and attribute properties
//	GLuint VBO;
//	GLfloat particle_quad[] = {
//		 -0.5f, -0.5f, 0.0f,
//		 0.5f, -0.5f, 0.0f,
//		 -0.5f, 0.5f, 0.0f,
//		 0.5f, 0.5f, 0.0f,
//	};
//
//	glGenVertexArrays(1, &this->VAO);
//	glGenBuffers(1, &VBO);
//	glBindVertexArray(this->VAO);
//
//	// Fill mesh buffer
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(particle_quad), particle_quad, GL_STATIC_DRAW);
//	// Set mesh attributes
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
//	glBindVertexArray(0);
//
//	// Create this->amount default particle instances
//	for(GLuint i = 0; i < this->amount; ++i)
//		this->particles.push_back(Particle());
//}


GLuint ParticleGenerator::firstUnusedParticle(){
	//// Stores the index of the last particle used (for quick access to next dead particle)
	//GLuint lastUsedParticle = 0;
	//// First search from last used particle, this will usually return almost instantly
	//for(GLuint i = lastUsedParticle; i < this->amount; ++i){
	//	if(this->particles[i].Life <= 0.0f){
	//		lastUsedParticle = i;
	//		return i;
	//	}
	//}
	//// Otherwise, do a linear search
	//for(GLuint i = 0; i < lastUsedParticle; ++i){
	//	if(this->particles[i].Life <= 0.0f){
	//		lastUsedParticle = i;
	//		return i;
	//	}
	//}
	//// All particles are taken, override the first one (note that if it repeatedly hits this case, more particles should be reserved)
	//lastUsedParticle = 0;
	return 0;
}


Particle ParticleGenerator::newParticle(){
	Particle p;
	GLuint i = 0;

	#define R(i) Randomizer(time(nullptr) + i)
	p.velocity = glm::vec3(R(i++).rand(-1.0f, 1.0f), R(i++).rand(1.0f, 3.0f), R(i++).rand(-1.0f, 1.0f));
	p.totalLife = R(i++).rand(2.0f, 5.0f);
	#undef R

	return p;
}
