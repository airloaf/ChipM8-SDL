#include "Renderer.h"

#include "Constants.h"

Renderer::Renderer()
    : mFrameTexture(nullptr)
{
    mLitPixel.r = 0xFF;
    mLitPixel.g = 0xFF;
    mLitPixel.b = 0xFF;
    mLitPixel.a = 0xFF;

    mUnlitPixel.r = 0x00;
    mUnlitPixel.g = 0x00;
    mUnlitPixel.b = 0x00;
    mUnlitPixel.a = 0xFF;
}

Renderer::~Renderer()
{
    if (mFrameTexture != nullptr)
    {
        SDL_DestroyTexture(mFrameTexture);
        mFrameTexture = nullptr;
    }
}

void Renderer::init(SDL_Renderer *renderer)
{
    mFrameTexture = SDL_CreateTexture(renderer,
                                      SDL_PIXELFORMAT_RGBA8888,
                                      SDL_TEXTUREACCESS_STREAMING,
                                      CHIP8_WIDTH,
                                      CHIP8_HEIGHT);
}

void Renderer::writeFrameToTexture(Screen &screen)
{
    // Lock the texture
    SDL_LockTexture(mFrameTexture, nullptr, (void **)&mPixelData, (int *)&mPitch);

    // Write pixel values to the texture
    for (int row = 0; row < 32; row++)
    {
        for (int col = 0; col < 64; col++)
        {
            mPixelData[row * CHIP8_WIDTH + col] =
                screen.getPixel(row, col) ? mLitPixel : mUnlitPixel;
        }
    }

    // Unlock the texture
    SDL_UnlockTexture(mFrameTexture);
}

void Renderer::renderScreen(SDL_Renderer *renderer, Screen &screen)
{
    // Update texture
    writeFrameToTexture(screen);

    // Render texture
    SDL_RenderCopy(renderer, mFrameTexture, nullptr, nullptr);
}
    
void Renderer::setFGColor(const PixelData &fg)
{
    mLitPixel = fg;
}

void Renderer::setBGColor(const PixelData &bg)
{
    mUnlitPixel = bg;
}