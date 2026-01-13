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
#include "Texture.h"
#include "RenderUtil.h"
#include "BasicShader.h"

class Game{
private:
    Mesh mesh;
    BasicShader shader;
    Transform transform;
    Camera camera;
    Texture texture;
    Material material;
public:
    Game();
    void input();
    void update();
    void render();
};