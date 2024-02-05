# so_long

## Overview

`so_long` is a simple 2D game project implemented in the C programming language using the **Minilibx**, a graphical library. The game involves navigating a character through a map, collecting items, and avoiding obstacles. This README provides comprehensive information to understand, implement, and enjoy the `so_long` project.

## Project Structure

The project consists of several components:

- **Map**: A file specifying the layout of the game, including walls, the player, collectible items, and the exit door.

- **Player**: A character that the user can control to navigate through the map.

- **Collectibles**: Items that the player can pick up to score points.

- **Exit Door**: The target location the player must reach to complete the game.

## Compilation

Compile the program using the provided Makefile:

```bash
make
```

This will generate the `so_long` executable.

## Usage

Run the game with a map file:

```bash
./so_long [map_file]
```

Replace `[map_file]` with the path to the map file you want to use.

## Map Format

Create maps using the following characters:

- **`1`**: Wall
- **`0`**: Empty space
- **`C`**: Collectible item
- **`E`**: Exit door
- **`P`**: Player's starting position

Example map:

```
111111
1001EP
10001C
10001C
1P000C
111111
```

## Controls

- **W / Up Arrow**: Move the player up.
- **A / Left Arrow**: Move the player left.
- **S / Down Arrow**: Move the player down.
- **D / Right Arrow**: Move the player right.
- **ESC**: Exit the game.

## Features

- **Graphics**: Utilizes the Minilibx library for graphical rendering.

- **Game Loop**: Implements a game loop to handle user input, update game state, and render frames.

- **Collectibles and Exit**: Adds scoring functionality through collectible items and a goal of reaching the exit door.

- **Player Movements**: Allows the player to navigate through the map using keyboard inputs.

## Error Handling

- Ensure that the map file is valid and follows the specified format.

- Check for any compilation errors or missing dependencies.

## Contributions

Contributions to enhance the game features, graphics, or documentation are welcome. Feel free to submit issues or pull requests.
