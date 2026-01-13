#include "Material.h"

Material::Material(): texture(), color(1,0,1) {

}

Material::Material(Texture&& texture, Vector3f color)
{
    this->texture = std::move(texture);
    this->color = color;
}

Material::Material(Vector3f color)
{
    this->color = color;
}

const Vector3f Material::getColor() const{
    return color;
}
void Material::setColor(Vector3f value) {
    color = value;
}

const Texture& Material::getTexture() const{
    return texture;
}

void Material::setTexture(Texture&& value) {
    texture = std::move(value);
}
