## 🎮 so_long - 1337 School Project
Welcome to my so_long repository! 🚀
The so_long project is an exciting introduction to graphical programming in C. This project combines basic game mechanics, 2D rendering, and algorithmic problem-solving, providing a foundation for creating interactive applications.

---

## 📊 Project Overview
The so_long project involves creating a small 2D game using the MiniLibX library. The goal is to render a map, implement player movements, and add interactive elements like collectibles and exit points. This project emphasizes working with graphical libraries, handling user input, and applying pathfinding algorithms.

---

## 🔧 Key Features
- Map Rendering: Display a grid-based map using textures for walls, floor, collectibles, and exits.
- Player Movement: Allow the player to navigate the map using keyboard inputs.
- Interactive Elements: Collectibles and exit points to complete the game.
- Pathfinding Validation: Ensure that the map is solvable, with a valid path to all collectibles and the exit.
- Error Handling: Validate the map format and handle invalid inputs gracefully.

---

## 📋 Project Structure
The project is structured as follows:
```
so_long/  
├── src/          # Source files for game logic and rendering  
├── include/      # Header files with function prototypes  
|   └── so_long.h # Main header file  
├── assets/       # Game assets (textures, sprites, etc.)  
├── maps/         # Example maps for testing  
├── Makefile      # Makefile to compile the project  
└── README.md     # Project documentation
```


---

## 🛠️ Installation

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/samir-ouaammou/1337-so_long  
   ```

2. Navigate to the project directory:
   ```bash
   cd 1337-so_long/Projects
   ```

3. Compile the source files using `make`:
   ```bash
   make 
   ```

4. Clean up compiled files:
   ```bash
   make clean
   ```

5. To remove all object files and the executable:
   ```bash
   make fclean
   ```

6. To recompile the project from scratch:
   ```bash
   make re
   ```


---

## 📂 Usage
1️⃣ Compile the Program
Run the following command to compile the program:
```bash
make
```

2️⃣ Run the Game
Execute the program with a map file as an argument:
```bash
./so_long maps/map3.ber
```

3️⃣ Controls
- Arrow Keys/WASD: Move the player.
- ESC: Exit the game.

4️⃣ Map Format
- The map file must have a .ber extension.
- The map must be rectangular, surrounded by walls, and contain at least:
    - One player (P)
    - One exit (E)
    - One collectible (C)
- Additional elements:
    - 1: Wall
    - 0: Floor
    - x: Enemy

Example map (map.ber):
```
111111  
1P0C01  
10X0E1  
111111
```

---

## 🏆 Key Features
MiniLibX Integration: Used MiniLibX to render the game window and textures.
Keyboard Input Handling: Implemented player movement using keyboard events.
Pathfinding: Validated the map using pathfinding algorithms to ensure playability.
Error Management: Detected and reported invalid maps or missing components.

---

## 🎯 Challenges Overcome
Learning and integrating the MiniLibX library for the first time.
Handling edge cases for map validation and ensuring proper error reporting.
Implementing smooth player movement and collision detection.
Debugging graphical glitches and optimizing rendering performance.

---

## 🚀 Next Steps
With so_long completed, I am now focused on:

Exploring advanced graphical programming with libraries like SDL or OpenGL.
Adding new features to the game, such as enemies or advanced mechanics.
Experimenting with more complex pathfinding algorithms.

---

## 🌟 Reflection
The so_long project was an enjoyable and challenging experience. It provided a solid introduction to graphical programming and game mechanics. I look forward to building more interactive applications and expanding my knowledge in this field.

---

Thank you for checking out my so_long project! 🎮 Feel free to explore the repository and reach out with any feedback or suggestions.
