#pragma once
#include "Vertex.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Mesh {
private:
    GLuint vbo, vao, ebo;
    GLsizei size;
public:
    Mesh();
    void addVertices(vertexList vertices, indexList indices);
    void draw();
    void loadMesh(const char* meshPath);
};
