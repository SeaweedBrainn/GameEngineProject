#pragma once
#include "Vector3f.h"

class Matrix4f;
class Camera;

class Transform {
private:
    Vector3f translation;
    Vector3f rotation;
    Vector3f scale;
    static float zNear;
    static float zFar;
    static float width;
    static float height;
    static float fov;
    static Camera* camera;
public:
    Transform();
    ~Transform();
    Vector3f getTranslation();
    void setTranslation(Vector3f& value);
    void setTranslation(float x, float y, float z);
    Vector3f getRotation();
    void setRotation(Vector3f& value);
    void setRotation(float x, float y, float z);
    Vector3f getScale();
    void setScale(Vector3f& value);
    void setScale(float x, float y, float z);
    Camera getCamera();
    void setCamera(Camera* value);
    Matrix4f getTransformation();
    Matrix4f getProjectedTransformation();
    static void setProjection(float fov, float width, float height, float zNear, float zFar);
};
