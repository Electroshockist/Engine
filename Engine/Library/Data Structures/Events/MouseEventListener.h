#ifndef MOUSEEVENTLISTENER_H
#define MOUSEEVENTLISTENER_H

#include <SDL/SDL.h>
#include <glm/glm.hpp>

class Engine;
class MouseEventListener
{
public:
    MouseEventListener() = delete;
    MouseEventListener(const MouseEventListener&) = delete;
    MouseEventListener(const MouseEventListener&&) = delete;
    MouseEventListener& operator=(const MouseEventListener&) = delete;
    MouseEventListener& operator=(MouseEventListener&&) = delete;
	~MouseEventListener(){}

    static void Update(SDL_Event e_);

    static void NotifyOfMousePressed(int buttonType_);
    static void NotifyOfMouseReleased(int buttonType_);
    static void NotifyOfMouseMove();
    static void NotifyOfMouseScroll(int y_);

    static glm::vec2 GetPreviousMousePosition();
    static glm::vec2 GetMousePosition();
    static glm::vec2 GetMouseOffset();
private:
    static int mouseX, mouseY, previousMouseX, previousMouseY;
    static bool firstUpdate;
    static void UpdateMousePosition();
};

#endif // !MOUSEEVENTLISTENER_H