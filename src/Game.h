#pragma once

#include "Input.h"
#include "Mesh.h"
#include "Vertex.h"
#include <iostream>
#include <cmath>
#include "Transform.h"
#include "Shader.h"
#include "ResourceLoader.h"
#include "Camera.h"

class Game{
private:
    Mesh mesh;
    Shader shader;
    Transform transform;
    Camera camera;
public:
    Game();
    void input();
    void update();
    void render();
};