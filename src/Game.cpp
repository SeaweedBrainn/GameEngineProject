#include "Game.h"

Game::Game(): mesh(Mesh()){
    vertexList data {
                     Vertex(Vector3f(0,0.5,0)),
                     Vertex(Vector3f(0.5,-0.5,0)),
                     Vertex(Vector3f(-0.5,-0.5,0))
                    };

    mesh.addVertices(data);
}

void Game::input() {
    if(Input::getMouseDown(0)) std::cout << Input::getMousePosition() << std::endl;
    if(Input::getMouseUp(0)) std::cout << "up" << std::endl;
}

void Game::update() {

}

void Game::render() {
    mesh.draw();
}