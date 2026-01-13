#pragma once

#include "Window.h"

class RenderUtil {
private:

public:
    RenderUtil();
    static void clearScreen();
    static void setClearColor(Vector3f color = Vector3f(0,0,0));
    static void initGraphics();
    static void unbindTextures();
};
