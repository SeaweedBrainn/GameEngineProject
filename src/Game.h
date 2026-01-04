#pragma once

#include "Input.h"
#include "Mesh.h"
#include "Vertex.h"
#include <iostream>

class Game{
private:
    Mesh mesh;
public:
    Game();
    void input();
    void update();
    void render();
};