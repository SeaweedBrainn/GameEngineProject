#pragma once

#include "Mesh.h"
#include "Transform.h"
#include "Shader.h"
#include "Camera.h"
#include "Texture.h"
#include "BasicShader.h"

class Game{
private:
    Mesh mesh;
    //Shader shader;
    BasicShader basicShader;
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