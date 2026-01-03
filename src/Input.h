#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Vector2f.h"
#include <algorithm>
#include <list>

class Input{
    public:
        Input();
        const static int NUM_KEYCODES = 256;
        const static int NUM_MOUSEBUTTONS = 8;
        static bool getKey(int keyCode);
        static bool getKeyDown(int keyCode);
        static bool getKeyUp(int keyCode);
        static bool getMouse(int mouseButton);
        static bool getMouseDown(int mouseButton);
        static bool getMouseUp(int mouseButton);
        static void update();
        static Vector2f getMousePosition();
    private:
        static std::list<int> currentKeys;
        static std::list<int> downKeys;
        static std::list<int> upKeys;

        static std::list<int> currentMouse;
        static std::list<int> downMouse;
        static std::list<int> upMouse;
};