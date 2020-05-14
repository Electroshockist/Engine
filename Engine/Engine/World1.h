#ifndef WORLD1_H
#define WORLD1_H

#include "../Library/World/AWorld.h"
#include "../Library/Graphics/3D/Model.h"
#include "../Library/Graphics/Camera/3D/Camera.h"
#include "../Library/Graphics/3D/SkyBox.h"
#include "../Library/Effects/Particle.h"
#include "../Library/Data Structures/SceneGraph.h"
#include "../Library/Audio/AudioPlayer.h"

GLuint CreateNoise3D();
void DeleteNoise3D();

struct World1 : public AWorld{
	Model * model, *model2, *model3;
	Camera *camera;
	SkyBox* skybox;
	ParticleGenerator* p;

	SceneGraph sceneGraph;

	int noiseID;

	glm::mat3 normalMatrix;

	World1() : camera(nullptr), model(nullptr), model2(nullptr), p(nullptr), skybox(nullptr), elapsedTime(0){}

	~World1(){
		delete camera;
		camera = nullptr;
		DeleteNoise3D();
	}

	// Inherited via AWorld
	virtual bool OnCreate() override;
	virtual bool Update(const float deltaTime_) override;
	virtual bool Render() override;

	void OnMouseMove(int x, int y);
	void OnMouseZoom(int zoom);
private:
	float elapsedTime;
};



#endif // !WORLD1_H

