#include "GameObject.h"

GameObject::GameObject(){}

GameObject::~GameObject(){}

void GameObject::Update(const float deltaTime){
	for(auto& updatable : updatableComponents){
		updatable->Update(deltaTime);
	}
}

void GameObject::Render(ACamera * camera){
	for(auto& renderable : renderableComponents){
		renderable->Render(camera);
	}
}

void GameObject::addComponent(AComponent * component){
	components.push_back(component);

	AUpdatable* u = dynamic_cast<AUpdatable*>(component);
	ARenderable* r = dynamic_cast<ARenderable*>(component);

	if(u != nullptr){
		updatableComponents.push_back(u);
	}

	if(r != nullptr){
		renderableComponents.push_back(r);
	}
}

void GameObject::Update(GameObject * parent, const float deltaTime, ACamera * camera){
	Update(deltaTime);
	Render(camera);
}
