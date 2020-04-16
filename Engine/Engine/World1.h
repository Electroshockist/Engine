#ifndef WORLD1_H
#define WORLD1_H

#include "../Library/Worlds/AWorld.h"
#include "../Library/Graphics/3D/Model.h"
#include "../Library/Graphics/Camera/3D/Camera.h"
#include "../Library/Graphics/3D/SkyBox.h"
#include "../Library/Effects/Particle.h"

struct World1 : public AWorld {
	Model * model, *model2;
	Camera *camera;
	SkyBox* skybox;
	ParticleGenerator* p;

	glm::mat3 normalMatrix;

	World1() : camera(nullptr), model(nullptr), model2(nullptr),p(nullptr),skybox(nullptr){}

	~World1(){
		delete camera;
		camera = nullptr;
	}

	// Inherited via AWorld
	virtual bool OnCreate() override;
	virtual bool Update(const float deltaTime_) override;
	virtual bool Render() override;

	void OnMouseMove(int x, int y);
};



#endif // !WORLD1_H

