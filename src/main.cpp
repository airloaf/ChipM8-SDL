#include <ChipM8/System/Interpreter.h>
#include <SDL2/SDL.h>
#include <iostream>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]){

    SDL_Window *window = nullptr;
    SDL_Surface *surface = NULL;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "Could not initialize SDL" << std::endl;
    }else{
        window = SDL_CreateWindow("ChipM8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == nullptr){
            std::cout << "COuld not create window" << std::endl;
        }else{
            surface = SDL_GetWindowSurface(window);
            SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0x00, 0x00));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}