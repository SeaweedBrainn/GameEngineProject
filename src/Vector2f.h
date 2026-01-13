#pragma once

#include <iostream>

class Vector2f{
    private:
        float x;
        float y;
    public:
        Vector2f();
        Vector2f(float x, float y);
        void setVector2f(float x, float y);
        float getX() const;
        void setX(float value);
        float getY() const;
        void setY(float value);
        float length();
        float dot(Vector2f v);
        Vector2f normalize();
        Vector2f rotate(float angle);
        Vector2f absl();
        Vector2f operator+(const Vector2f& other) const;
        Vector2f operator+(const float& other) const;
        Vector2f operator-(const Vector2f& other) const;
        Vector2f operator-(const float& other) const;
        Vector2f operator*(const Vector2f& other) const;
        Vector2f operator*(const float& other) const;
        Vector2f operator/(const Vector2f& other) const;
        Vector2f operator/(const float& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Vector2f& vector2f);
};
