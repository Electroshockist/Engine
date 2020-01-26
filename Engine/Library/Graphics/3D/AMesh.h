#ifndef AMESH_H
#define AMESH_H

#include <vector>
#include <glm/glm.hpp>

class ACamera;
class AMesh{
public:
	virtual void Render(ACamera *camera, std::vector<glm::mat4> &instance) = 0;
};

#endif // !AMESH_H

