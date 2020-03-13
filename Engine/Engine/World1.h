#ifndef WORLD1_H
#define WORLD1_H

#include "../Library/Worlds/AWorld.h"
#include "../Library/Graphics/3D/Model.h"
struct World1 : public AWorld {

	Model m;

	World1(){}

	~World1(){}

	// Inherited via AWorld
	virtual bool OnCreate() override;
	virtual bool Update(const float deltaTime_) override;
	virtual bool Render() override;
};



#endif // !WORLD1_H

