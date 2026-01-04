#pragma once

#include "Window.h"
#include "Time.h"
#include "Game.h"
#include "Input.h"
#include "RenderUtil.h"
#include <thread>
#include <iostream>

#include <string>
#include "Game.h"
using std::string;

class MainComponent{
    public:
        static int WIDTH;
        static int HEIGHT;
        static string TITLE;
        MainComponent();
        static void main();
        void Start();
        void Stop();

    private:
        static const double FRAME_CAP;
        bool isRunning = false;
        Game *game;
        void Render();
        void Run();
        void CleanUp();
};

