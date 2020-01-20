#include "Chip8.h"

int main(int argc, char* argv[]){

    if(argc == 2){
        Chip8 chip8(argv[1]);
        chip8.run();
    }


    return 0;
}