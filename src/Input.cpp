#include "Input.h"

void handleInput(SDL_Event *event, Input &input){

    bool pressed = false;
    uint8_t key = 0;

    // Check if keydown
    if(event->type == SDL_KEYDOWN || event->type == SDL_KEYUP){
        pressed = (event->type == SDL_KEYDOWN);

        switch(event->key.keysym.sym){
            case SDLK_1:
                key = 1;
                break;
            case SDLK_2:
                key = 2;
                break;
            case SDLK_3:
                key = 3;
                break;
            case SDLK_4:
                key = 0xc;
                break;
            case SDLK_q:
                key = 4;
                break;
            case SDLK_w:
                key = 5;
                break;
            case SDLK_e:
                key = 6;
                break;
            case SDLK_r:
                key = 0xD;
                break;
            case SDLK_a:
                key = 7;
                break;
            case SDLK_s:
                key = 8;
                break;
            case SDLK_d:
                key = 9;
                break;
            case SDLK_f:
                key = 0xE;
                break;
            case SDLK_z:
                key = 0xA;
                break;
            case SDLK_x:
                key = 0;
                break;
            case SDLK_c:
                key = 0xB;
                break;
            case SDLK_v:
                key = 0xF;
                break;
        }

        input.setKeyPressed(key, pressed);
    }

}