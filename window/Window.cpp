#include "Window.h"
#include "../tools/Logger.h"

bool Window::init(unsigned int width, unsigned int height, std::string title) {
    if (SDL_Init(SDL_INIT_EVENTS) != 0) {
        Logger::log(1, "%s: Unable to initialize SDL: %s\n", __FUNCTION__, SDL_GetError());
        return EXIT_FAILURE;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        Logger::log(1, "%s: Unable to initialize SDL: %s\n", __FUNCTION__, SDL_GetError());
        return EXIT_FAILURE;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        Logger::log(1, "%s: Unable to initialize SDL: %s\n", __FUNCTION__, SDL_GetError());
        return EXIT_FAILURE;
    }

    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        Logger::log(1, "%s: Unable to initialize SDL: %s\n", __FUNCTION__, SDL_GetError());
        return EXIT_FAILURE;
    }

    mWindow = SDL_CreateWindow(
        "plataformSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0
    );

    if (!mWindow) {
        Logger::log(1, "%s: Could not create window\n", __FUNCTION__);
        return EXIT_FAILURE;
        return false;
    }

    Logger::log(1, "%s: Window successfully initialized\n", __FUNCTION__);
    return true;
}

void Window::mainLoop() {
    while (!shouldQuit) {
        ProcessInputs();
    }
}

void Window::cleanup() {
    Logger::log(1, "%s: Terminating Window\n", __FUNCTION__);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Window::ProcessInputs()
{
    SDL_Event event;
    while (SDL_PollEvent(&event) > 0) {
        switch (event.type) {
        case SDL_QUIT: {
            shouldQuit = true;
            return;
        }
        }
    }
}
