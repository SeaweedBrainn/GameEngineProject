#pragma once
#include "Texture.h"
#include "Vector3f.h"

class Material {
private:
    Texture texture;
    Vector3f color;
public:
    Material();
    Material(Texture&& texture, Vector3f color);
    Material(Vector3f color);
    const Texture& getTexture() const;
    void setTexture(Texture&& value);
    const Vector3f getColor() const;
    void setColor(Vector3f value);
};

