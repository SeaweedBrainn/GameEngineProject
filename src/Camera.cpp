#include "Camera.h"
#include "Input.h"
#include "Time.h"

const Vector3f Camera::yAxis(0,1,0);

Camera::Camera(): pos(Vector3f()), forward(Vector3f(0,0,1)), up(Vector3f(0,1,0)){}

Camera::Camera(Vector3f pos, Vector3f forward, Vector3f up): pos(pos), forward(forward), up(up)
{
    up.normalize();
    forward.normalize();
}

Camera::~Camera() {
    // Destructor
}

Vector3f Camera::getPos() {
    return pos;
}
void Camera::setPos(Vector3f& value) {
    pos = value;
}
Vector3f Camera::getForward() {
    return forward;
}
void Camera::setForward(Vector3f& value) {
    forward = value;
}
Vector3f Camera::getUp() {
    return up;
}
void Camera::setUp(Vector3f& value) {
    up = value;
}

void Camera::move(Vector3f dir, float amt)
{
    pos = pos + (dir * amt);
}

void Camera::rotateX(float angle)
{
    Vector3f horizontalAxis = Camera::yAxis * forward;
    horizontalAxis.normalize();

    forward.rotate(angle, horizontalAxis);
    forward.normalize();

    up = forward * horizontalAxis;
    up.normalize();
}

void Camera::rotateY(float angle){
    Vector3f horizontalAxis = Camera::yAxis * forward;
    horizontalAxis.normalize();

    forward.rotate(angle, Camera::yAxis);
    forward.normalize();

    up = forward * horizontalAxis;
    up.normalize();
}

Vector3f Camera::getLeft()
{
    Vector3f left = forward * up;
    left.normalize();
    return left;
}

Vector3f Camera::getRight()
{
    Vector3f right = up * forward;
    right.normalize();
    return right;
}

void Camera::input()
{
    float sensitivity = 0.5f;
    float movAmt = static_cast<float>(10 * Time::getDelta());
    //float rotAmt = static_cast<float>(100 * Time::getDelta());

    if(Input::getMouseUp(GLFW_MOUSE_BUTTON_MIDDLE) || Input::getKeyDown(GLFW_KEY_ESCAPE))
    {
        Input::setCursor(true);
        mouseLocked = false;
    }
    if(Input::getMouseDown(GLFW_MOUSE_BUTTON_MIDDLE) || Input::getKeyDown(GLFW_KEY_R))
    {
        Input::setMousePosition(centerPosition);
        Input::setCursor(false);
        mouseLocked = true;
    }
    
    if(Input::getKey(GLFW_KEY_W)){
        move(getForward(), movAmt);
    }
    if(Input::getKey(GLFW_KEY_S)){
        move(getForward(), -movAmt);
    }
    if(Input::getKey(GLFW_KEY_A)){
        move(getLeft(), movAmt);
    }
    if(Input::getKey(GLFW_KEY_D)){
        move(getRight(), movAmt);
    }
    if(Input::getKey(GLFW_KEY_Q)){
        move(getUp(), movAmt);
    }
    if(Input::getKey(GLFW_KEY_E)){
        move(getUp(), -movAmt);
    }

    if(mouseLocked)
    {
        Vector2f deltaPos = Input::getMousePosition() - centerPosition;
        
        bool rotY = deltaPos.getX() != 0;
        bool rotX = deltaPos.getY() != 0;
        
        if(rotY)
            rotateY(deltaPos.getX() * sensitivity);
        if(rotX)
            rotateX(deltaPos.getY() * sensitivity);
            
        if(rotY || rotX)
            Input::setMousePosition(Vector2f(Window::GetWidth()/2, Window::GetHeight()/2));
    }

    if(Input::getKey(GLFW_KEY_L)){
        Vector3f posi(0,0,0);
        Vector3f forw(0,0,1);
        Vector3f upw(0,1,0);
        setPos(posi);
        setForward(forw);
        setUp(upw);
    }

    /*
    if(Input::getKey(GLFW_KEY_UP)){
        rotateX(-rotAmt);
    }
    if(Input::getKey(GLFW_KEY_DOWN)){
        rotateX(rotAmt);
    }
    if(Input::getKey(GLFW_KEY_LEFT)){
        rotateY(-rotAmt);
    }
    if(Input::getKey(GLFW_KEY_RIGHT)){
        rotateY(rotAmt);
    }*/
    
}
