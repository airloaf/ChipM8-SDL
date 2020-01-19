#pragma once

#include <SDL2/SDL.h>
#include <ChipM8/System/Interpreter.h>

/**
 * Class used to facilitate the 
 * game loop
 **/
class Chip8{

    public:
        Chip8();
        ~Chip8();

        /**
         * Run the ChipM8 interpreter
         **/ 
        void run();

    private:

        SDL_Window *mWindow;
        SDL_Renderer *mRenderer;

        Interpreter mInterpreter;

};