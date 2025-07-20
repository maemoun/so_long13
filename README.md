_______________________________________________________
🗺️ SO_LONG :
_______________________________________________________

The so_long project at 42/1337 is a graphical project where you build a simple 2D game using the MiniLibX (MLX) graphics library.

_______________________________________________________
🎯 Goal of the Project:
_______________________________________________________

Create a small game where the player moves on a map to:

  * Collect all collectibles.

  * Find the exit.

  * Avoid enemies (in bonus).

All using basic keyboard input, image rendering, and file parsing.

_______________________________________________________
🧱 Project Overview:
_______________________________________________________

[Element] ------> [Description]

  * [Map] ---------> [A .ber file representing the game world in a rectangular grid].

  * [Player] -------> [Can move in 4 directions using the keyboard].

  * [Collectibles] ---> [Must be collected before reaching the exit].

  * [Exit] ------------> [The level ends when the player collects all items and exits].

  * [Walls] -----------> [Block the player].

  * [Enemies] ---------> [(Bonus)	Kill the player if touched].

________________________________________________________
🗺️ Map File Format (.ber):
________________________________________________________

The map is made up of characters:

    111111
    1P0C1E
    111111

[Symbol] -> [Meaning]:

  * [1] ----> [Wall].

  * [0] ----> [Floor (empty space)].

  * [P] ----> [Player start].

  * [C] ----> [Collectible item].

  * [E] ----> [Exit].

__________________________________________________________
🧩 Mandatory Requirements
__________________________________________________________

  * Load and parse a .ber map file.

  * Render the map using MLX.

  * Move the player with WASD or arrow keys.

  * Count and display number of moves.

  * Only allow exiting the level after all collectibles are gathered.

  * Handle map errors:

      -> Not rectangular.

      -> No player/start.

      -> No exit.

      -> Not enclosed by walls.

      -> Unreachable paths (flood fill to validate).

__________________________________________________________
📦 How It Works:
__________________________________________________________

1. Parsing the Map :
  _________________

   Read the map file, validate:

  * File ends with .ber.

  * All rows are the same length.

  * Walls surround the map.

  * Contains exactly:

    -> 1 player P.

    -> 1+ collectible C.

    -> 1+ exit E.

3. Graphics with MLX:
   __________________

  Use MiniLibX (MLX) to:

  * Load .xpm or .png images for each tile (player, wall, floor, etc.).

  * Display them in a window.

  * Handle keyboard input to move the player.

3. Movement:
   _________

Use key hooks to move:

  * [W] = up.

  * [S] = down.

  * [A] = left.

  * [D] = right.

Update the game state:

  * Block movement into walls.

  * Pick up collectibles.

  * Exit if all collectibles are picked.

_______________________________________________________________________________
🧠 Bonus Features (Optional):
_______________________________________________________________________________

[Feature] -----> [Description]:

  * [Enemies] --------> [Move or patrol, kill player on contact].

  * [Animations] -----> [Player/enemy/exit tiles animate].

  * [Mouse control] -----> [Handle mouse clicks].

  * [Score display] -----> [Show on-screen stats].

  * [Multi-levels] ------> [Load and cycle through multiple .ber maps].

_______________________________________________________________________________
🧪 Evaluation Checklist:
_______________________________________________________________________________

   * Map file is valid and well parsed.

   * Game runs with valid .ber file.

   * Player can move, collect items, exit.

   * All error cases handled.

   * No memory leaks or crashes.

   * Bonus (if included) works correctly.

______________________________________________________________________________
🏗️ Typical File Structure:
______________________________________________________________________________

    so_long/
    ├── maps/
    │   └── level1.ber
    ├── src/
    │   ├── main.c
    │   ├── map.c
    │   ├── render.c
    │   ├── input.c
    │   ├── utils.c
    ├── images/
    │   ├── player.xpm
    │   ├── wall.xpm
    │   ├── exit.xpm
    │   └── ...
    ├── so_long.h
    └── Makefile

  📦 Example Map (level1.ber):
  
    1111111
    1P0C0E1
    1111111
   
