#pragma once
#include "Texture.h"
#include "Vector3f.h"

class Material {
private:
    Texture* texture;
    Vector3f color;
public:
    Material();
    Material(Texture& texture, Vector3f color);
    Material(Vector3f color);
    Texture* getTexture();
    void setTexture(Texture*& value);
    Vector3f getColor();
    void setColor(Vector3f& value);
};

