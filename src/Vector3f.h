#pragma once

#include <iostream>
#include <cmath>

class Vector3f {
private:
    float x;
    float y;
    float z;
public:
    Vector3f();
    Vector3f(float x, float y, float z);
    void setVector3f(float x, float y, float z);
    float getX() const;
    void setX(float value);
    float getY() const;
    void setY(float value);
    float getZ() const;
    void setZ(float value);
    float length();
    float dot(Vector3f v);
    Vector3f cross(Vector3f v);
    Vector3f normalize();
    Vector3f rotate(float angle);
    Vector3f operator+(const Vector3f& other) const;
    Vector3f operator+(const float& other) const;
    Vector3f operator-(const Vector3f& other) const;
    Vector3f operator-(const float& other) const;
    Vector3f operator*(const Vector3f& other) const;
    Vector3f operator*(const float& other) const;
    Vector3f operator/(const Vector3f& other) const;
    Vector3f operator/(const float& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Vector3f& vector3f);
};
