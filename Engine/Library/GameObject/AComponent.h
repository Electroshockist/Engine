#ifndef ACOMPONENT_H
#define ACOMPONENT_H
struct AComponent{
	virtual ~AComponent(){};
};

struct AUpdatable : public AComponent{
	AUpdatable* parent = nullptr;
	virtual void Update(const float deltaTime) = 0;
};

struct ARenderable : public AComponent{
	ARenderable* parent = nullptr;
	virtual void Render(class ACamera* camera) = 0;
};
#endif // !ACOMPONENT_H
