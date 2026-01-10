#include "Transform.h"

Transform::Transform() {
    translation = Vector3f(0.0f, 0.f, 0.0f);
}

Transform::~Transform() {
    // Destructor
}

Vector3f Transform::getTranslation() {
    return translation;
}
void Transform::setTranslation(Vector3f& value) {
    translation = value;
}

void Transform::setTranslation(float x, float y, float z)
{
    translation = Vector3f(x,y,z);
}

Matrix4f Transform::getTransformation()
{
    Matrix4f translationMatrix;
    translationMatrix.initTranslation(translation.getX(), translation.getY(), translation.getZ());
    
    return translationMatrix;
}
