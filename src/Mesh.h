#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Vertex.h"
#include "Util.h"

class Mesh {
private:
    GLuint vbo, vao, ebo;
    GLsizei size;
public:
    Mesh();
    void addVertices(vertexList vertices, indexList indices);
    void draw();
};
