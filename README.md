# ChipM8-SDL

Chip-8 Interpreter using SDL2 for graphics

## Dependencies
- SDL2
- CMake
- [ChipM8](https://github.com/airloaf/ChipM8-Core) (my interpreter library)

## Building
Use the accompanying CMake file to build the application

## Usage
To launch a Chip-8 program you will need to pass the program path to the executable. On windows you can simply drag and drop your Chip-8 program onto the executable.

Chip-8 uses a Hexadecimal keypad for input. Modern keyboards do not have such a thing, so a mapping was created. Below is the key mapping for the interpreter. The keys on the right are what you should press on the keyboard. The keys on the left are the hexadecimal keys they map to.

```
1 2 3 C  <=  1 2 3 4
4 5 6 D      q w e r
7 8 9 E      a s d f
A 0 B F      z x c v
```

To quit the interpreter press ```ESC```

## Screenshots
![Brix](https://github.com/airloaf/ChipM8-SDL/blob/master/screenshots/Brix.PNG)
![Tetris](https://github.com/airloaf/ChipM8-SDL/blob/master/screenshots/Tetris.PNG)
![SpaceInvaders](https://github.com/airloaf/ChipM8-SDL/blob/master/screenshots/SpaceInvaders.PNG)
