#include "Chip8.h"

#ifdef EMSCRIPTEN
#include <emscripten/emscripten.h>

void emscripten_loop(void *arg)
{
    Chip8 *chip8 = (Chip8 *) arg;
    chip8->tick();
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
    Chip8 chip8("testrom.ch8");
    emscripten_set_main_loop_arg(
        emscripten_loop,
        &chip8,
        0,
        1
    );
#endif

    return 0;
}