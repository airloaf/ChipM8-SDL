#include "Graphics.h"

#include "Constants.h"

#include <cstddef>

void renderScreen(SDL_Renderer *renderer, Screen &screen)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    for (std::size_t row = 0; row < 32; row++)
    {
        for (std::size_t col = 0; col < 64; col++)
        {
            // Check if the given pixel is lit
            if (screen.getPixel(row, col))
            {

                std::size_t xCoord = PIXEL_WIDTH * col;
                std::size_t yCoord = PIXEL_HEIGHT * row;

                // Create the rectangle
                SDL_Rect fillRect = {static_cast<int>(xCoord), static_cast<int>(yCoord),
                                     PIXEL_WIDTH,
                                     PIXEL_HEIGHT};
                SDL_RenderFillRect(renderer, &fillRect);
            }
        }
    }
}