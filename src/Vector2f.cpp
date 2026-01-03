#include "Vector2f.h"

Vector2f::Vector2f(): x(float()), y(float()){

}

Vector2f::Vector2f(float x, float y): x(x), y(y){
    
}

void Vector2f::setVector2f(float x, float y){
    this->x = x;
    this->y = y;
}

void Vector2f::setX(float value){
    x = value;
}

void Vector2f::setY(float value){
    y = value;
}

float Vector2f::getX() const{
    return x;
}

float Vector2f::getY() const{
    return y;
}

std::ostream& operator<<(std::ostream& os, const Vector2f& vector2f) {
    os << "(" << vector2f.getX() << "," << vector2f.getY() << ")";
    return os;
}

float Vector2f::length(){
    return static_cast<float>(std::sqrt(x*x + y*y));
}

float Vector2f::dot(Vector2f v){
    return (x * v.getX() + y * v.getY());
}

Vector2f Vector2f::normalize()
{
    float size = length();
    x /= size;
    y /= size;

    return *this;
}

Vector2f Vector2f::rotate(float angle)
{
    double rad = angle * M_PI / 180;
    double cosine = cos(rad);
    double sine = sin(rad);

    float xVal = static_cast<float>(x * cosine - y * sine);
    float yVal = static_cast<float>(x * sine + y * cosine);

    return Vector2f(xVal, yVal);
}

Vector2f Vector2f::operator+(const Vector2f &other) const
{
    return Vector2f(x + other.getX(), y + other.getY());
}

Vector2f Vector2f::operator+(const float &other) const
{
    return Vector2f(x + other, y + other);
}

Vector2f Vector2f::operator-(const Vector2f &other) const
{
    return Vector2f(x - other.getX(), y - other.getY());
}

Vector2f Vector2f::operator-(const float &other) const
{
    return Vector2f(x - other, y - other);
}

Vector2f Vector2f::operator*(const Vector2f &other) const
{
    return Vector2f(x * other.getX(), y * other.getY());
}

Vector2f Vector2f::operator*(const float &other) const
{
    return Vector2f(x * other, y * other);
}

Vector2f Vector2f::operator/(const Vector2f &other) const
{
    return Vector2f(x / other.getX(), y / other.getY());
}

Vector2f Vector2f::operator/(const float &other) const
{
    return Vector2f(x / other, y / other);
}
