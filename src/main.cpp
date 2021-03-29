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