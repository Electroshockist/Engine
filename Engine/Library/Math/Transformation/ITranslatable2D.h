#ifndef ITRANSLATABLE2D_H
#define ITRANSLATABLE2D_H

#include <glm/glm.hpp>

struct ITranslatable2D {
	glm::vec2 position;
	ITranslatable2D(glm::vec2 position);
};
#endif // !ITRANSLATABLE2D_H
