#ifndef WORLD1_H
#define WORLD1_H

#include "../Library/Worlds/AWorld.h"
#include "../Library/Graphics/3D/Model.h"
#include "../Library/Graphics/Camera/3D/Camera.h"
#include "../Library/Graphics/3D/SkyBox.h"
#include "../Library/Effects/Particle.h"

struct World1 : public AWorld {
	Model * model;
	Camera *camera;
	SkyBox* skybox;
	ParticleGenerator* p;

	World1() : camera(nullptr), model(nullptr), skybox(nullptr){}

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

