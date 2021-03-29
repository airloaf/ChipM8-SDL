#pragma once

#include <SDL2/SDL.h>
#include <ChipM8/Peripherals/Screen.h>

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

    struct PixelData
    {
        uint8_t a;
        uint8_t b;
        uint8_t g;
        uint8_t r;
    } * mPixelData;

    PixelData mLitPixel, mUnlitPixel;

    int *mPitch;
};