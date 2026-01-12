#include "Quaternion.h"
#include "Vector3f.h"

Quaternion::Quaternion(): x(float()), y(float()), z(float()), w(float()) {
    
}

Quaternion::Quaternion(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {

}

float Quaternion::getX() const {
    return x;
}
void Quaternion::setX(float& value) {
    x = value;
}
float Quaternion::getY() const {
    return y;
}
void Quaternion::setY(float& value) {
    y = value;
}
float Quaternion::getZ() const {
    return z;
}
void Quaternion::setZ(float& value) {
    z = value;
}
float Quaternion::getW() const {
    return w;
}
void Quaternion::setW(float& value) {
    w = value;
}

float Quaternion::length()
{
    return sqrt(x*x + y*y + z*z + w*w);
}

Quaternion Quaternion::normalize()
{
    float size = length();

    float x_ = x/size;
    float y_ = y/size;
    float z_ = z/size;
    float w_ = w/size;

    return Quaternion(x_, y_, z_, w_);
}

Quaternion Quaternion::conjugate()
{
    return Quaternion(-x, -y, -z, w);
}

Quaternion Quaternion::operator*(const Quaternion &other) const
{
    float w_ = w * other.getW() - x * other.getX() - y * other.getY() - z * other.getZ();
    float x_ = x * other.getW() + w * other.getX() + y * other.getZ() - z * other.getY();
    float y_ = y * other.getW() + w * other.getY() + z * other.getX() - x * other.getZ();
    float z_ = z * other.getW() + w * other.getZ() + x * other.getY() - y * other.getX();

    return Quaternion(x_, y_, z_, w_);
}

Quaternion Quaternion::operator*(const Vector3f &other) const
{
    float w_ = -x * other.getX() - y * other.getY() - z * other.getZ();
    float x_ = w * other.getX() + y * other.getZ() - z * other.getY();
    float y_ = w * other.getY() + z * other.getX() - x * other.getZ();
    float z_ = w * other.getZ() + x * other.getY() - y * other.getX();

    return Quaternion(x_, y_, z_, w_);
}

std::ostream& operator<<(std::ostream& os, const Quaternion& quaternion){
    std::cout << "(" << quaternion.getX() << "," << quaternion.getY() << "," << quaternion.getZ() << "," << quaternion.getW() << ")";
    return os;
}
