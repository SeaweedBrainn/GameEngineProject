#include "Vertex.h"

Vertex::Vertex() {
    
}

Vertex::Vertex(const Vector3f &value): pos(Vector3f(value)) {}

Vector3f Vertex::getPos() const{
    return pos;
}

void Vertex::setPos(Vector3f& value){
    pos = value;
}
