#include "Vertex.h"

Vertex::Vertex(): pos(), texCoord() {}

Vertex::Vertex(const Vector3f &posV): pos(posV), texCoord(0,0) {}

Vertex::Vertex(const Vector3f &posV, const Vector2f& texCoordV): pos(posV), texCoord(texCoordV) {}

Vector3f Vertex::getPos() const{
    return pos;
}

void Vertex::setPos(Vector3f& value){
    pos = value;
}

Vector2f Vertex::getTexCoord() const{
    return texCoord;
}
void Vertex::setTexCoord(Vector2f& value) {
    texCoord = value;
}
