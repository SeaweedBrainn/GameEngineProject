#pragma once

#include "Vector3f.h"
#include "Vector2f.h"

class Vertex {
private:
    Vector3f pos;
    Vector2f texCoord;
public:
    static const int SIZE = 5;
    Vertex();
    Vertex(const Vector3f& posV);
    Vertex(const Vector3f& posV, const Vector2f& texCoordV);
    Vector3f getPos() const;
    void setPos(Vector3f& value);
    Vector2f getTexCoord() const;
    void setTexCoord(Vector2f& value);
};

typedef std::vector<Vertex> vertexList;
typedef std::vector<unsigned int> indexList;
