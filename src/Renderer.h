#pragma once

#include <SDL2/SDL.h>
#include <ChipM8/Peripherals/Screen.h>

struct PixelData
{
    uint8_t a;
    uint8_t b;
    uint8_t g;
    uint8_t r;
};

class Renderer
{
public:
    Renderer();
    ~Renderer();

    void init(SDL_Renderer *renderer);

    void renderScreen(SDL_Renderer *renderer, Screen &screen);

private:
    void writeFrameToTexture(Screen &screen);

    SDL_Texture *mFrameTexture;
    
    PixelData *mPixelData;
    PixelData mLitPixel, mUnlitPixel;

    int *mPitch;
};