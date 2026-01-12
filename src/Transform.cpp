#include "Transform.h"
#include "Camera.h"

float Transform::fov;
float Transform::width;
float Transform::height;
float Transform::zNear;
float Transform::zFar;
Camera* Transform::camera;

Transform::Transform() {
    translation = Vector3f(0.0f, 0.f, 0.0f);
    rotation = Vector3f(0.0f, 0.0f, 0.0f);
    scale = Vector3f(1.0f, 1.0f, 1.0f);
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

Vector3f Transform::getRotation() {
    return rotation;
}
void Transform::setRotation(Vector3f& value) {
    rotation = value;
}

void Transform::setRotation(float x, float y, float z){
    rotation = Vector3f(x,y,z);
}

Vector3f Transform::getScale() {
    return scale;
}
void Transform::setScale(Vector3f& value) {
    scale = value;
}

void Transform::setScale(float x, float y, float z){
    scale = Vector3f(x,y,z);
}

Camera Transform::getCamera() {
    return *camera;
}
void Transform::setCamera(Camera* value) {
    camera = value;
}

Matrix4f Transform::getTransformation()
{
    Matrix4f translationMatrix;
    Matrix4f rotationMatrix;
    Matrix4f scaleMatrix;

    translationMatrix.initTranslation(translation.getX(), translation.getY(), translation.getZ());
    rotationMatrix.initRotation(rotation.getX(), rotation.getY(), rotation.getZ());
    scaleMatrix.initScale(scale.getX(), scale.getY(), scale.getZ());

    return translationMatrix * rotationMatrix * scaleMatrix;
}

Matrix4f Transform::getProjectedTransformation(){
    Matrix4f transformationMatrix(getTransformation());
    Matrix4f projectionMatrix;
    Matrix4f cameraRotation;
    Matrix4f cameraTranslation;

    projectionMatrix.initProjection(fov, width, height, zNear, zFar);
    cameraRotation.initCamera(camera->getForward(), camera->getUp());
    cameraTranslation.initTranslation(-camera->getPos().getX(), -camera->getPos().getY(), -camera->getPos().getZ());

    return projectionMatrix * cameraRotation * cameraTranslation * transformationMatrix;
}

void Transform::setProjection(float fov, float width, float height, float zNear, float zFar)
{
    Transform::fov = fov;
    Transform::width = width;
    Transform::height = height;
    Transform::zNear = zNear;
    Transform::zFar = zFar;
}
