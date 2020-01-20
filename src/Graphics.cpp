#include "Graphics.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define WIDTH SCREEN_WIDTH/64
#define HEIGHT SCREEN_HEIGHT/32

void renderScreen(SDL_Renderer *renderer, Screen &screen){

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    for(std::size_t row = 0; row < 32; row++){
        for(std::size_t col = 0; col < 64; col++){
            // Check if the given pixel is lit
            if(screen.getPixel(row, col)){

                std::size_t xCoord = WIDTH * col;
                std::size_t yCoord = HEIGHT * row;                

                // Create the rectangle
                SDL_Rect fillRect = {xCoord, yCoord, WIDTH, HEIGHT};
                SDL_RenderFillRect(renderer, &fillRect);
            }
        }
    }

}