#pragma once

#include <SDL2/SDL.h>
#include <ChipM8/System/Interpreter.h>

#include "Renderer.h"

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
    void tick();

    void updateRenderColors(PixelData &fgColor, PixelData &bgColor);
    void updateClockRate(unsigned int frequency);

private:

    // Poll SDL input
    void pollInput();

    void renderFrame();

    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;

    Interpreter mInterpreter;

    unsigned int mClockRate;
    unsigned int mClockPeriod;

    uint32_t mLastExecution;
    uint32_t mLastTimer;

    bool mQuit;

    Renderer mChip8Renderer;
};