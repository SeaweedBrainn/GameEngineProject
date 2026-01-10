#include "Game.h"

Game::Game(): mesh(Mesh()){
    vertexList data {
                     Vertex(Vector3f(-1,-1,0)),
                     Vertex(Vector3f(0,1,0)),
                     Vertex(Vector3f(1,-1,0))
                    };

    mesh.addVertices(data);

    shader.addVertexShader("../../res/shaders/vShader.vs");
    shader.addFragmentShader("../../res/shaders/fShader.fs");
    shader.linkShaders();

    shader.addUniform("transform");
}

void Game::input() {
    if(Input::getMouseDown(0)) std::cout << Input::getMousePosition() << std::endl;
    if(Input::getMouseUp(0)) std::cout << "up" << std::endl;
}

void Game::update() {
    transform.setTranslation(sin(glfwGetTime()), 0.0f, 0.0f);
}

void Game::render() {
    shader.bind();
    shader.setUniform("transform", transform.getTransformation());
    mesh.draw();
}