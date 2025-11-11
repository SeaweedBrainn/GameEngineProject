#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

using std::string;

class Window{
    public:
        static GLFWwindow* window;
        static void CreateWindow(int width, int height, string title);
        static void Render();
        static bool IsCloseRequested();
        static void Dispose();
        static int GetWidth();
        static int GetHeight();
        static string GetTitle();
        
};