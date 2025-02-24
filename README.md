# So Long
A 2D game project that involves collecting items and finding an exit, using the MiniLibX library and implementing basic gameplay elements with proper window and event management.

## Project Description
So Long is a 2D game project that requires implementing a simple game where a player must collect all items on a map before reaching the exit. The project focuses on window management, sprite handling, and event management using the MiniLibX library.

### The Rules
- You have a map file ending with `.ber` extension
- The map contains:
  - Walls (`1`)
  - Empty spaces (`0`)
  - Collectibles (`C`)
  - Exit (`E`)
  - Player starting position (`P`)
- The goal is to collect all collectibles and reach the exit using:
  - `W` or `↑`: Move up
  - `S` or `↓`: Move down
  - `A` or `←`: Move left
  - `D` or `→`: Move right
  - `ESC`: Exit game

## Features
- 2D graphics rendering
- Map validation and parsing
- Player movement handling
- Collision detection
- Window event management
- Movement counter
- Clean exit handling

## Usage
```bash
# Compile the program
make

# Run with a map file
./so_long maps/map.ber

# Example of a valid map file:
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Map Requirements
- Must be rectangular
- Must be surrounded by walls (`1`)
- Must contain:
  - Exactly one exit (`E`)
  - At least one collectible (`C`)
  - Exactly one starting position (`P`)
- Must have a valid path to all collectibles and the exit
- Must only use valid characters: `0`, `1`, `C`, `E`, `P`

## Technical Requirements
- Written in C
- Graphics using MiniLibX
- No memory leaks
- Error handling for:
  - Invalid maps
  - Window management
  - Memory allocation
- Makefile rules:
  - `make`
  - `clean`
  - `fclean`
  - `re`

## External Functions Allowed
- open, close, read, write
- malloc, free
- perror, strerror
- exit
- Math library functions
- MiniLibX functions
- Your own ft_printf or equivalent

## Bonus Features
- Enemy patrols that cause game over on touch
- Sprite animations
- On-screen movement counter
