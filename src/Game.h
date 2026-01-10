#pragma once

#include "Input.h"
#include "Mesh.h"
#include "Vertex.h"
#include <iostream>
#include <cmath>
#include "Transform.h"

class Game{
private:
    Mesh mesh;
    Shader shader;
    Transform transform;
public:
    Game();
    void input();
    void update();
    void render();
};