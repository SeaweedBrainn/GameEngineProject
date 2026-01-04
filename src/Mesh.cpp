#include "Mesh.h"

Mesh::Mesh() {
    glGenBuffers(1, &vbo);
    size = 0;
}

void Mesh::addVertices(vertexList vertices)
{
    size = vertices.size();
    floatBuffer buffer = Util::createBuffer(vertices);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float), buffer.data(), GL_STATIC_DRAW);
}

void Mesh::draw(){
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Vertex::SIZE * sizeof(float), 0);

    glDrawArrays(GL_TRIANGLES, 0, size);

    glDisableVertexAttribArray(0);
}