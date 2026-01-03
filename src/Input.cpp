#include "Input.h"

std::list<int> Input::currentKeys;
std::list<int> Input::downKeys;
std::list<int> Input::upKeys;

std::list<int> Input::currentMouse;
std::list<int> Input::downMouse;
std::list<int> Input::upMouse;

Input::Input(){
    
}

void Input::update(){
    
    upKeys.clear();

    for(int i = 0; i < NUM_KEYCODES; i++){
        if(!getKey(i) && std::find(currentKeys.begin(), currentKeys.end(),i) != currentKeys.end()){
            upKeys.push_back(i);
        }
    }

    downKeys.clear();

    for(int i = 0; i < NUM_KEYCODES; i++){
        if(getKey(i) && std::find(currentKeys.begin(), currentKeys.end(),i) == currentKeys.end()){
            downKeys.push_back(i);
        }
    }

    currentKeys.clear();

    for(int i = 0; i < NUM_KEYCODES; i++){
        if(getKey(i)){
            currentKeys.push_back(i);
        }
    }

    upMouse.clear();

    for(int i = 0; i < NUM_MOUSEBUTTONS; i++){
        if(!getMouse(i) && std::find(currentMouse.begin(), currentMouse.end(),i) != currentMouse.end()){
            upMouse.push_back(i);
        }
    }

    downMouse.clear();

    for(int i = 0; i < NUM_MOUSEBUTTONS; i++){
        if(getMouse(i) && std::find(currentMouse.begin(), currentMouse.end(),i) == currentMouse.end()){
            downMouse.push_back(i);
        }
    }

    currentMouse.clear();

    for(int i = 0; i < NUM_MOUSEBUTTONS; i++){
        if(getMouse(i)){
            currentMouse.push_back(i);
        }
    }
}

bool Input::getKey(int keyCode){
    return glfwGetKey(Window::getWindow(),keyCode) == GLFW_PRESS;
}

bool Input::getKeyDown(int keyCode){
    return std::find(downKeys.begin(), downKeys.end(), keyCode) != downKeys.end();
}

bool Input::getKeyUp(int keyCode){
    return std::find(upKeys.begin(), upKeys.end(), keyCode) != upKeys.end();
}

bool Input::getMouse(int mouseButton){
    return glfwGetMouseButton(Window::getWindow(),mouseButton) == GLFW_PRESS;
}

bool Input::getMouseDown(int mouseButton){
    return std::find(downMouse.begin(), downMouse.end(), mouseButton) != downMouse.end();
}

bool Input::getMouseUp(int mouseButton){
    return std::find(upMouse.begin(), upMouse.end(), mouseButton) != upMouse.end();
}

Vector2f Input::getMousePosition(){
    double mouseX, mouseY;
    glfwGetCursorPos(Window::getWindow(), &mouseX, &mouseY);
    return Vector2f(mouseX, mouseY);
}