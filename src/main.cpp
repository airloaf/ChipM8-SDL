#include "Chip8.h"

#ifdef EMSCRIPTEN
#include <emscripten/emscripten.h>

Chip8 *chip8 = nullptr;

void emscripten_loop()
{
    if (chip8 != nullptr)
    {
        chip8->tick();
    }
}

extern "C"
{
    EMSCRIPTEN_KEEPALIVE
    void startChip8()
    {
        chip8 = new Chip8("rom.ch8");
    }
}

#include <iostream>
extern "C"
{
    
    EMSCRIPTEN_KEEPALIVE
    void updateSettings(int fgColor, int bgColor, int clockFreq)
    {
        std::cout << "Updating ChipM8 in C++" << std::endl;
        std::cout << "Foreground Color: " << fgColor << std::endl;
        std::cout << "Foreground Color: " << bgColor << std::endl;
        std::cout << "Foreground Color: " << clockFreq << std::endl;

        if(chip8 != nullptr){

            PixelData fgData, bgData;
            fgData.a = bgData.a = 0xFF;

            fgData.r = ((fgColor & 0x00FF0000) >> 16);
            fgData.g = ((fgColor & 0x0000FF00) >> 8);
            fgData.b = ((fgColor & 0x000000FF) >> 0);

            bgData.r = ((bgColor & 0x00FF0000) >> 16);
            bgData.g = ((bgColor & 0x0000FF00) >> 8);
            bgData.b = ((bgColor & 0x000000FF) >> 0);

            chip8->updateRenderColors(fgData, bgData);
            chip8->updateClockRate(clockFreq);
        }

    }
}

#endif

int main(int argc, char *argv[])
{

#ifndef EMSCRIPTEN
    if (argc == 2)
    {
        Chip8 chip8(argv[1]);
        chip8.run();
    }
#else
    emscripten_set_main_loop(
        emscripten_loop,
        0,
        1);
#endif

    return 0;
}