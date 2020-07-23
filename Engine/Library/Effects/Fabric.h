#ifndef FABRIC_H
#define FABRIC_H

#include <GLEW/glew.h>
#include <vector>

#include "../GameObject/AComponent.h"
#include "../Graphics/Shaders/Shader.h"
#include "../Graphics/Materials/MaterialManager.h"
#include "../Graphics/Camera/3D/Camera.h"
#include "../Graphics/3D/Mesh.h"

namespace Fabric{
	struct Vertex;
	struct Spring{
		float elasticity;
		float displacement;

		Vertex* vertices[2];
	};

	struct Vertex{

		std::vector<Spring> springs;

		//connect two vertices together with a spring
		void Connect(Vertex* v){
			Spring s;
			s.vertices[0] = this;
			s.vertices[1] = v;

			springs.push_back(s);
			v->springs.push_back(s);
		}
	};

	class Fabric : public AUpdatable, public Mesh{
		void Destroy();

		// Inherited via AUpdatable
		virtual void Update(const float deltaTime) override;
	};
}
#endif //!FABRIC_H
