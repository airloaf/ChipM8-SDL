#pragma once

#include <SDL2/SDL.h>
#include <ChipM8/System/Interpreter.h>

/**
 * Class used to facilitate the 
 * game loop
 **/
class Chip8
{

public:
    Chip8(std::string filePath);
    ~Chip8();

    void run();

private:
    
    // Single tick of the ChipM8 interpreter
    void tick();

    // Poll SDL input
    void pollInput();

    void renderFrame();

    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;

    Interpreter mInterpreter;

    uint32_t mLastExecution;
    uint32_t mLastTimer;

    bool mQuit;
};