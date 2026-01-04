#pragma once
#include "Vertex.h"
#include <vector>

typedef std::vector<float> floatBuffer;

class Util {
private:

public:
    Util();
    static floatBuffer createBuffer(const vertexList& vertices);
};
