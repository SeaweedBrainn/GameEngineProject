#pragma once

#include "Game.h"

class MainComponent{
    public:
        static int WIDTH;
        static int HEIGHT;
        static std::string TITLE;
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

