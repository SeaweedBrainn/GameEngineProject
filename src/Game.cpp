#include "Game.h"

Game::Game(): mesh(Mesh()){
    vertexList vertices {
        Vertex(Vector3f(-1.0f, -0.408f, -0.577f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f( 1.0f, -0.408f, -0.577f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f( 0.0f, -0.408f,  1.155f), Vector2f(0.5f, 1.0f)),
        Vertex(Vector3f( 0.0f,  1.225f,  0.0f),   Vector2f(0.5f, 0.5f)) 
    };

    indexList indices {
        0, 1, 3,
        1, 2, 3,
        2, 0, 3,
        2, 1, 0
    };

    mesh.addVertices(vertices, indices);
    texture.setTexture("../../res/textures/monkeyTexture.png");
    material = Material(texture, Vector3f(1,1,1));

    //mesh.loadMesh("../../res/models/texturedMonkey.obj");

    Transform::setProjection(70.0f, Window::GetWidth(), Window::GetHeight(), 0.1f, 1000.0f);
    transform.setCamera(&camera);
    //FRAMEBUFFER SIZE CALLBACK FUNCTION IS CALLED AS WELL IN THE WINDOW CLASS WHEN WINDOW IS RESIZED

    //shader.addVertexShader("../../res/shaders/vShader.vert");
    //shader.addFragmentShader("../../res/shaders/fShader.frag");
    //shader.linkShaders();

    //shader.addUniform("transform");
}

void Game::input() {
    if(Input::getMouseDown(0)) std::cout << Input::getMousePosition() << std::endl;
    if(Input::getMouseUp(0)) std::cout << "up" << std::endl;
    //transform.setCamera(camera);
    camera.input();
}

void Game::update() {
    transform.setTranslation(0.0f, 0.0f, 5.0f);
    //transform.setRotation(0.0f, sin(glfwGetTime()/2) * 360, 0.0f);
    transform.setScale(1.0f, 1.0f, -1.0f);
}

void Game::render() {
    RenderUtil::setClearColor(Vector3f(0.2f, 0.3f, 0.3f));
    shader.bind();
    shader.updateUniforms(transform.getTransformation(), transform.getProjectedTransformation(), material);
    //shader.setUniform("transform", transform.getProjectedTransformation());
    //texture.bind();
    mesh.draw();
}