#ifndef WORLD1_H
#define WORLD1_H

#include "../Library/Worlds/AWorld.h"
#include "../Library/Graphics/3D/Model.h"
#include "../Library/Graphics/Camera/3D/Camera.h"

struct World1 : public AWorld{

	Model m;
	Camera *c;

	World1() : c(nullptr){}

	~World1(){
		delete c;
		c = nullptr;
	}

	// Inherited via AWorld
	virtual bool OnCreate() override;
	virtual bool Update(const float deltaTime_) override;
	virtual bool Render() override;
};



#endif // !WORLD1_H

