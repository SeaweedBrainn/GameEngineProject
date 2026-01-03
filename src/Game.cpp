#include "Game.h"

Game::Game() {}

void Game::input() {
    if(Input::getMouseDown(0)) std::cout << Input::getMousePosition() << std::endl;
    if(Input::getMouseUp(0)) std::cout << "up" << std::endl;
}

void Game::update() {

}

void Game::render() {

}