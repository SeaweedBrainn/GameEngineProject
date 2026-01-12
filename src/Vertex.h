#pragma once

#include "Vector3f.h"

class Vertex {
private:
    Vector3f pos;
public:
    static const int SIZE = 3;
    Vertex();
    Vertex(const Vector3f& value);
    Vector3f getPos() const;
    void setPos(Vector3f& value);
};

typedef std::vector<Vertex> vertexList;
typedef std::vector<unsigned int> indexList;
