#pragma once

#include <SDL2/SDL.h>

#include <ChipM8/Peripherals/Input.h>

/**
 * Handles an SDL Event
 *
 * When handling the SDL Event,
 * the class must 
 *  
 * @param event - the SDL Event
 * @param input - the ChipM8 input class
 **/
void handleInput(SDL_Event *event, Input &input);