#ifndef MOUSEEVENTLISTENER_H
#define MOUSEEVENTLISTENER_H

#include <SDL/SDL.h>
#include <glm/glm.hpp>

#include "../Event.h"

class Engine;
struct MouseEventHandler {
	MouseEventHandler() = delete;
	MouseEventHandler(const MouseEventHandler&) = delete;
	MouseEventHandler(const MouseEventHandler&&) = delete;
	MouseEventHandler& operator=(const MouseEventHandler&) = delete;
	MouseEventHandler& operator=(MouseEventHandler&&) = delete;
	~MouseEventHandler(){}

	struct MouseButtonEvent : public Event {
		const int& GetValue() const{
			return value;
		}
		friend class MouseEventHandler;
	private:
		int value;
	};

	static MouseButtonEvent mousePress, mouseRelease, mouseScroll;
	static Event mouseMove;

	static void Update(SDL_Event e_);

	static glm::vec2 GetPreviousMousePosition();
	static glm::vec2 GetMousePosition();
	static glm::vec2 GetMouseOffset();
private:
	static int mouseX, mouseY, previousMouseX, previousMouseY;
	static bool firstUpdate;
	static void UpdateMousePosition();
};

#endif // !MOUSEEVENTLISTENER_H