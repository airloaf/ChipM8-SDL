#include "Chip8.h"

#include "Constants.h"
#include "Input.h"

#include <chrono>

Chip8::Chip8(std::string filePath)
    : mQuit(false),
      mClockRate(CPU_RATE),
      mClockPeriod(1000.0f / (float) CPU_RATE)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                SDL_WINDOW_SHOWN,
                                &mWindow,
                                &mRenderer);

    mInterpreter.loadProgram(filePath);

    SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(mRenderer);

    mChip8Renderer.init(mRenderer);
}

Chip8::~Chip8()
{
    // De-allocate/Destroy SDL objects
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);

    // Uninitialize all SDL subsystems
    SDL_Quit();
}

void Chip8::run()
{
    while (!mQuit)
    {
        tick();
    }
}

void Chip8::tick()
{
    uint32_t currentTime = SDL_GetTicks();
    uint32_t cpuDelta = currentTime - mLastExecution;
    uint32_t timerDelta = currentTime - mLastTimer;

    // If the interpretre has halted, stop executing
    if (!mInterpreter.hasExecutionHalted())
    {
        // Check if we need to update the CPU
        if (cpuDelta > mClockPeriod)
        {
            int numTicks = ((int)cpuDelta) / ((int)mClockPeriod);
            mLastExecution = SDL_GetTicks();
            for (int i = 0; i < numTicks; i++)
            {
                mInterpreter.tick();
            }
        }
        // Update the timers
        if (timerDelta > TIMER_TIME)
        {
            mLastTimer = SDL_GetTicks();
            mInterpreter.tickTimers();

            renderFrame();
        }
    }

    pollInput();
}

void Chip8::pollInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            mQuit = true;
        }
        else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                mQuit = true;
            }
            handleInput(&event, mInterpreter.input);
        }
    }
}

void Chip8::renderFrame()
{
    SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(mRenderer);
    // renderScreen(mRenderer, mInterpreter.screen);
    mChip8Renderer.renderScreen(mRenderer, mInterpreter.screen);
    SDL_RenderPresent(mRenderer);
}

void Chip8::updateRenderColors(PixelData &fgColor, PixelData &bgColor)
{
    mChip8Renderer.setFGColor(fgColor);
    mChip8Renderer.setBGColor(bgColor);
}

void Chip8::updateClockRate(unsigned int frequency)
{
    mClockRate = frequency;
    mClockPeriod = 1000.0f / ((float) frequency);
}