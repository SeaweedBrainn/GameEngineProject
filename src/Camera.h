#pragma once
#include "Vector3f.h"
#include "Input.h"
#include "Time.h"

class Camera {
public:
    Camera();
    Camera(Vector3f pos, Vector3f forward, Vector3f up);
    ~Camera();

    Vector3f getPos();
    void setPos(Vector3f& value);
    Vector3f getForward();
    void setForward(Vector3f& value);
    Vector3f getUp();
    void setUp(Vector3f& value);
    void move(Vector3f dir, float amt);
    void rotateX(float angle);
    void rotateY(float angle);
    Vector3f getLeft();
    Vector3f getRight();
    void input();

private:
    Vector3f pos;
    Vector3f forward;
    Vector3f up;

    static const Vector3f yAxis;
};
