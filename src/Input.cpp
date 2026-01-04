#include "Input.h"

bool Input::lastKeys[Input::NUM_KEYCODES] = {};
bool Input::lastMouse[Input::NUM_MOUSEBUTTONS] = {};

Input::Input(){
    
}

void Input::update(){
    for(int i = 0; i < NUM_KEYCODES; i++){
        lastKeys[i] = getKey(i);
    }

    for(int i = 0; i < NUM_MOUSEBUTTONS; i++){
        lastMouse[i] = getMouse(i);
    }
}

bool Input::getKey(int keyCode){
    return glfwGetKey(Window::getWindow(),keyCode) == GLFW_PRESS;
}

bool Input::getKeyDown(int keyCode){
    return getKey(keyCode) && !lastKeys[keyCode];
}

bool Input::getKeyUp(int keyCode){
    return !getKey(keyCode) && lastKeys[keyCode];
}

bool Input::getMouse(int mouseButton){
    return glfwGetMouseButton(Window::getWindow(),mouseButton) == GLFW_PRESS;
}

bool Input::getMouseDown(int mouseButton){
    return getMouse(mouseButton) && !lastMouse[mouseButton];
}
bool Input::getMouseUp(int mouseButton){
    return !getMouse(mouseButton) && lastMouse[mouseButton];
}

Vector2f Input::getMousePosition(){
    double mouseX, mouseY;
    glfwGetCursorPos(Window::getWindow(), &mouseX, &mouseY);
    return Vector2f(mouseX, mouseY);
}