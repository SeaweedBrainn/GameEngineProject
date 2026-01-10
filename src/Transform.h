#pragma once
#include "Vector3f.h"
#include "Matrix4f.h"

class Transform {
private:
    Vector3f translation;

public:
    Transform();
    ~Transform();
    Vector3f getTranslation();
    void setTranslation(Vector3f& value);
    void setTranslation(float x, float y, float z);
    Matrix4f getTransformation();
};
