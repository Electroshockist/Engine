#ifndef ITRANSLATABLE_3D
#define ITRANSLATABLE_3D

#include <glm/glm.hpp>

struct ITranslatable3D {
	glm::vec3 position;
	ITranslatable3D(): position(glm::vec3()){}
	ITranslatable3D(glm::vec3 position);
};
#endif //!ITRANSLATABLE_3D
