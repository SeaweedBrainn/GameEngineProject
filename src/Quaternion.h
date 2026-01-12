#pragma once
#include <cmath>
#include <iostream>

class Vector3f;

class Quaternion {
private:
    float x;
    float y;
    float z;
    float w;
public:
    Quaternion();
    Quaternion(float x, float y, float z, float w);
    float getX() const;
    void setX(float& value);
    float getY() const;
    void setY(float& value);
    float getZ() const;
    void setZ(float& value);
    float getW() const;
    void setW(float& value);
    float length();
    Quaternion normalize();
    Quaternion conjugate();

    Quaternion operator*(const Quaternion& other) const;
    Quaternion operator*(const Vector3f& other) const;

friend std::ostream& operator<<(std::ostream& os, const Quaternion& quaternion);
};
