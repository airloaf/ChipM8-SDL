# ChipM8-SDL

Chip-8 Interpreter using SDL2 for graphics

## Dependencies
- SDL2
- CMake
- [ChipM8](https://github.com/airloaf/ChipM8-Core) (my interpreter library)

## Building
Use the accompanying CMake file to build the application

## Usage
Here is the key mapping for the interpreter. The keys on the right are what you should press on the keyboard. The keys on the left are what they map to. Chip-8 uses a hexadecimal keypad, this is the best mapping I could think of to replicate it on a modern day keyboard.

```
1 2 3 C  <=  1 2 3 4
4 5 6 D      q w e r
7 8 9 E      a s d f
A 0 B F      z x c v
```

To quit the interpreter press ```ESC```

## Screenshots
![Brix](screenshots/Brix.png)
![Tetris](screenshots/Tetris.png)
![SpaceInvaders](screenshots/SpaceInvaders.png)