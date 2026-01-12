#include "Game.h"

Game::Game(): mesh(Mesh()){
    vertexList vertices {
                     Vertex(Vector3f(-1,-1,0)),
                     Vertex(Vector3f(0,1,0)),
                     Vertex(Vector3f(1,-1,0)),
                     Vertex(Vector3f(0,-1,1))
                    };

    indexList indices{
                    0,1,3,
                    3,1,2,
                    2,1,0,
                    0,2,3
                    };

    //mesh.addVertices(vertices, indices);

    ResourceLoader::loadMesh("../../res/models/monkey.obj", mesh);

    Transform::setProjection(70.0f, Window::GetWidth(), Window::GetHeight(), 0.1f, 1000.0f);
    transform.setCamera(&camera);
    //FRAMEBUFFER SIZE CALLBACK FUNCTION IS CALLED AS WELL IN THE WINDOW CLASS WHEN WINDOW IS RESIZED

    shader.addVertexShader("../../res/shaders/vShader.vs");
    shader.addFragmentShader("../../res/shaders/fShader.fs");
    shader.linkShaders();

    shader.addUniform("transform");
}

void Game::input() {
    if(Input::getMouseDown(0)) std::cout << Input::getMousePosition() << std::endl;
    if(Input::getMouseUp(0)) std::cout << "up" << std::endl;
    //transform.setCamera(camera);
    camera.input();
}

void Game::update() {
    transform.setTranslation(0.0f, 0.0f, 5.0f);
    transform.setRotation(0.0f, sin(glfwGetTime()/2) * 360, 0.0f);
    //transform.setScale(0.5f, 0.5f, -0.5f);
}

void Game::render() {
    shader.bind();
    shader.setUniform("transform", transform.getProjectedTransformation());
    mesh.draw();
}