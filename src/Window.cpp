#include "Window.h"

GLFWwindow* Window::window = nullptr;

void Window::CreateWindow(int width, int height, string title){
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);  // 0 = disable V-Sync

}

void Window::Render(){
    glfwPollEvents();
    glfwSwapBuffers(window);
}

bool Window::IsCloseRequested(){
    return glfwWindowShouldClose(window);
}

void Window::Dispose(){
    glfwTerminate();
}

int Window::GetHeight(){
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    return height;
}

int Window::GetWidth(){
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    return width;
}