#include "Window.h"

GLFWwindow* Window::window = nullptr;

void Window::CreateWindow(int width, int height, string title){
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        std::exit(-1);
    }
    
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

GLFWwindow* Window::getWindow(){
    return window;
}

void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}
