#include "Chip8.h"

#include "Graphics.h"

#include <chrono>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define CPU_RATE 500
#define CPU_TIME 1000.0f/CPU_RATE

#define TIMER_RATE 60
#define TIMER_TIME 1000.0f/TIMER_RATE

Chip8::Chip8(){

    // Initialize SDL with all subsystems
    // TODO
    // Check for errors
    // Only initialize the sub systems required
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &mWindow, &mRenderer);

    mInterpreter.loadProgram("games/Pong (alt).ch8");

}

Chip8::~Chip8(){

    // De-allocate/Destroy SDL objects
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);

    // Uninitialize all SDL subsystems
    SDL_Quit();

}

void Chip8::run(){

    bool quit = false;

    uint32_t lastExecution = SDL_GetTicks();
    uint32_t lastTimer = SDL_GetTicks();

    while(!quit){

        uint32_t currentTime = SDL_GetTicks();
        uint32_t cpuDelta = currentTime - lastExecution;
        uint32_t timerDelta = currentTime - lastTimer;

        // Check if we need to update the CPU
        if(cpuDelta > CPU_TIME){
            lastExecution = SDL_GetTicks();

            mInterpreter.tick();

            SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderClear(mRenderer);
        
            renderScreen(mRenderer, mInterpreter.screen);
        
            SDL_RenderPresent(mRenderer);
        }

        // Update the timers
        if(timerDelta > TIMER_TIME){
            mInterpreter.tickTimers();
        }

        // Poll events
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0){
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }


    }

}