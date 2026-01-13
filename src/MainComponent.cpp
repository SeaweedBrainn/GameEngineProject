#include "MainComponent.h"

#include "Window.h"
#include "Time.h"
#include "Input.h"
#include "RenderUtil.h"
#include <thread>
#include <iostream>
#include <string>

int MainComponent::WIDTH = 800;
int MainComponent::HEIGHT = 600;
std::string MainComponent::TITLE = "3D Game Engine";
const double MainComponent::FRAME_CAP = 5000.0;

int main(){
    MainComponent::main();
}

MainComponent::MainComponent(): isRunning(false) {
    game = new Game();
}

void MainComponent::main(){
    Window::CreateWindow(WIDTH, HEIGHT, TITLE);
    RenderUtil::initGraphics();
    MainComponent *gameEngine = new MainComponent();
    gameEngine->Start();
}


void MainComponent::Start(){
    if(isRunning) return;
    Run();
}

void MainComponent::Stop(){
    if(!isRunning) return;
    isRunning = false;
}

void MainComponent::Run(){
    isRunning = true;

    int frames = 0;
    tUnit frameCounter = 0;

    const double frameTime = 1.0 / FRAME_CAP;

    tUnit lastTime = Time::getTime();
    double unProcessedTime = 0;

    while(isRunning){
        bool render  = false;
        tUnit startTime = Time::getTime();
        tUnit passedTime = startTime - lastTime;
        lastTime = startTime;

        unProcessedTime += passedTime / static_cast<double>(Time::SECOND);
        frameCounter += passedTime;

        while (unProcessedTime >= frameTime){
            render = true;
            unProcessedTime -= frameTime;
            if(Window::IsCloseRequested()) Stop();

            Time::setDelta(frameTime);
            
            game->input();
            Input::update();
            
            game->update();

            if (frameCounter >= Time::SECOND){
                std::cout << "FPS: " << frames << std::endl;
                frames = 0;
                frameCounter = 0;
            }
        }
        if(render) {
            Render();
            frames++;
        }
        else std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    CleanUp();
}

void MainComponent::Render(){
    RenderUtil::clearScreen();
    game->render();
    Window::Render();
}

void MainComponent::CleanUp(){
    Window::Dispose();
}

