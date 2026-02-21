#pragma once

#include <cstdlib>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

class Window {
public:
    bool init(unsigned int width, unsigned int height, std::string title);
    void mainLoop();
    void cleanup();

private:
    SDL_Window* mWindow = nullptr;
    bool shouldQuit = false;
    void ProcessInputs();
};