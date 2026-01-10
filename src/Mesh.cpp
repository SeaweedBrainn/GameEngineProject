#include "Mesh.h"

Mesh::Mesh() {
    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);
    size = 0;
}

void Mesh::addVertices(vertexList vertices)
{
    size = vertices.size();
    floatBuffer buffer = Util::createBuffer(vertices);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float), buffer.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Vertex::SIZE * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void Mesh::draw(){
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, size);
    glBindVertexArray(vao);
}