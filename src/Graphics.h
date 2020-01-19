#pragma once

#include <SDL2/SDL.h>

#include <ChipM8/Peripherals/Screen.h>

/**
 * Renders the Chip8
 * 
 * Renders the screen using the renderer.
 * 
 * @param renderer - SDL Renderer
 * @param screen - the screen to render
 **/
void renderScreen(SDL_Renderer *renderer, Screen &screen);