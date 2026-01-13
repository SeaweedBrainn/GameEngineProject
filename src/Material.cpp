#include "Material.h"

Material::Material(): texture(), color(1,0,1) {

}

Material::Material(Texture &texture, Vector3f color)
{
    this->texture = &texture;
    this->color = color;
}

Material::Material(Vector3f color)
{
    this->color = color;
    this->texture = nullptr;
}

Vector3f Material::getColor() {
    return color;
}
void Material::setColor(Vector3f& value) {
    color = value;
}

Texture* Material::getTexture() {
    return texture;
}
void Material::setTexture(Texture*& value) {
    texture = value;
}
