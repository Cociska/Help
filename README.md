# My Radar

## ✈️ Description
My Radar is a 2D air traffic simulation panel based on the CSFML library.
The goal is to manage aircraft simulation including takeoff, landing, constant speed movement, and collision detection, while visualizing control tower areas where collisions are suppressed.

This project is part of the Graphics module

## 🛠️ Usage

### Compilation

```bash
make
```
Running the simulation

The program takes exactly one argument: the path to the script file defining the entities.

```Bash
./my_radar path_to_script
```

Example:
```Bash
./my_radar scripts/example.rdr
```

Controls / User Interactions

    'L' key: Show/Hide hitboxes and control areas.

    'S' key: Show/Hide entity sprites.

📂 Project Structure

```bash
.
├── algo/          # Generators or python scripts
├── assets/        # Sprites (planes, towers)
├── includes/      # Header files (.h)
├── src/           # Source code (.c)
├── tests/         # Unit tests
└── Makefile       # Compilation rules
```

🚧 Development Log & Progress

```
Phase 1: Initialization & Parsing

[X] Makefile: Implement all, clean, fclean, re rules.

[X] Window: Open a 1920x1080 CSFML window.

[X] Event Handling: Handle window closing (ESC or Close button).

[ ] Parsing: Read the script file supplied as an argument.

    [ ] Handle 'A' (Aircraft) data storage.

    [ ] Handle 'T' (Tower) data storage.

    [ ] Error handling (File not found / Bad format -> exit 84).

Phase 2: Core Simulation Logic

[ ] Data Structures: Create linked lists (or arrays) to manage entities.

[ ] Movement: Update aircraft position based on speed and direction vectors.

[ ] Timing: Implement start delay for aircrafts.

[ ] Lifecycle:

    [ ] Spawn aircrafts at the correct time.

    [ ] Remove aircrafts when they reach their destination.

Phase 3: Hitboxes & Collisions

[ ] Hitboxes: Implement axis-aligned bounding boxes (20x20 for planes).

[ ] Collision Detection: Detect intersection between two aircraft hitboxes.

[ ] Destruction: Destroy both aircrafts upon collision.

[ ] Control Towers:

    [ ] Implement circular control areas.

    [ ] Disable collision logic for planes inside a tower`s radius.

Phase 4: Graphics & Rendering

[ ] Sprites: Render plane and tower textures.

[ ] Rotation: Rotate aircraft sprites to match their direction vector.

[ ] Debug View:

    [ ] Draw hitboxes (Rectangles) and Areas (Circles).

    [ ] Implement the 'L' toggle switch.

    [ ] Implement the 'S' toggle switch.

[ ] Timer: Display a timer in seconds at the top-right corner.

Phase 5: Cleanup & Polish

[ ] Memory: Ensure all malloc'd memory is freed and CSFML objects destroyed.

[X] Flags: Implement the -h flag for usage display.

[ ] Norm: Ensure code complies with Epitech coding style.
```