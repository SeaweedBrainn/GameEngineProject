#include "Util.h"

Util::Util() {
    // Constructor
}

floatBuffer Util::createBuffer(const vertexList& vertices)
{
    floatBuffer buffer;
    for(int i = 0; i < vertices.size(); i++){
        buffer.push_back(vertices[i].getPos().getX());
        buffer.push_back(vertices[i].getPos().getY());
        buffer.push_back(vertices[i].getPos().getZ());
        buffer.push_back(vertices[i].getTexCoord().getX());
        buffer.push_back(vertices[i].getTexCoord().getY());
    }
    return buffer;
}
