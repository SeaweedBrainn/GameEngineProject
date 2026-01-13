#include "Vector3f.h"
#include <cmath>
#include "Quaternion.h"

Vector3f::Vector3f(): x(float()), y(float()), z(float()){

}

Vector3f::Vector3f(float x, float y, float z): x(x), y(y), z(z){
    
}

void Vector3f::setVector3f(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3f::setX(float value){
    x = value;
}

void Vector3f::setY(float value){
    y = value;
}

void Vector3f::setZ(float value){
    z = value;
}

float Vector3f::getX() const{
    return x;
}

float Vector3f::getY() const{
    return y;
}

float Vector3f::getZ() const{
    return z;
}

std::ostream& operator<<(std::ostream& os, const Vector3f& vector3f) {
    os << "(" << vector3f.getX() << "," << vector3f.getY() << "," << vector3f.getZ() << ")";
    return os;
}

float Vector3f::length(){
    return static_cast<float>(std::sqrt(x*x + y*y + z*z));
}

float Vector3f::dot(Vector3f v){
    return (x * v.getX() + y * v.getY() + z * v.getZ());
}

Vector3f Vector3f::rotate(float angle, Vector3f axis)
{
    float rad = angle * M_PI / 180;
    float sinHalfAngle = sin(rad/2);
    float cosHalfAngle = cos(rad/2);

    float rx = axis.getX() * sinHalfAngle;
    float ry = axis.getY() * sinHalfAngle;
    float rz = axis.getZ() * sinHalfAngle;
    float rw = cosHalfAngle;

    Quaternion rotation(rx, ry, rz, rw);
    Quaternion conjugate = rotation.conjugate();

    Quaternion w = rotation * (*this) * conjugate;

    x = w.getX();
    y = w.getY();
    z = w.getZ();

    return *this;
}

Vector3f Vector3f::cross(Vector3f v)
{
    return (*this) * v;
}

Vector3f Vector3f::normalize()
{
    float size = length();
    x /= size;
    y /= size;
    z /= size;

    return *this;
}

Vector3f Vector3f::absl()
{
    return Vector3f(abs(x), abs(y), abs(z));
}

Vector3f Vector3f::operator+(const Vector3f &other) const
{
    return Vector3f(x + other.getX(), y + other.getY(), z + other.getZ());
}

Vector3f Vector3f::operator+(const float &other) const
{
    return Vector3f(x + other, y + other, z + other);
}

Vector3f Vector3f::operator-(const Vector3f &other) const
{
    return Vector3f(x - other.getX(), y - other.getY(), z - other.getZ());
}

Vector3f Vector3f::operator-(const float &other) const
{
    return Vector3f(x - other, y - other, z - other);
}

Vector3f Vector3f::operator*(const Vector3f &v) const
{
    float x_ = y * v.getZ() - z * v.getY();
    float y_ = z * v.getX() - x * v.getZ();
    float z_ = x * v.getY() - y * v.getX();
    return Vector3f(x_, y_, z_);
}

Vector3f Vector3f::operator*(const float &other) const
{
    return Vector3f(x * other, y * other, z * other);
}

Vector3f Vector3f::operator/(const Vector3f &other) const
{
    return Vector3f(x / other.getX(), y / other.getY(), z / other.getZ());
}

Vector3f Vector3f::operator/(const float &other) const
{
    return Vector3f(x / other, y / other, z / other);
}
