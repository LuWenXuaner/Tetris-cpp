# Tetris Game - Qt/C++ Implementation

![C++](https://img.shields.io/badge/Language-C++11-00599C?logo=c%2B%2B) ![Qt](https://img.shields.io/badge/Framework-Qt-41CD52?logo=qt) ![OOP](https://img.shields.io/badge/Design-Object--Oriented%20Programming-blue) ![License](https://img.shields.io/badge/License-MIT-green)

## Overview

This is a multi-mode Tetris game developed with **C++** and **Qt framework**, completed as a course project for Object-Oriented Programming Practice. The project strictly follows object-oriented design principles (encapsulation, inheritance, polymorphism), implements 3 innovative gameplay modes, and features a complete GUI interactive system, real-time game state management, and audio-visual optimization.

This project demonstrates proficiency in C++ OOP development, Qt framework application, game logic design, and software engineering practices, making it a solid portfolio project for technical resumes.

## Key Features

### 3 Gameplay Modes

1. Classic Basic Mode
   - Standard 7 types of 4-block tetrominoes with complete classic Tetris rules
   - Real-time display of score, level, eliminated lines, and survival time
   - Adjustable difficulty levels (Easy/Hard) with dynamic block falling speed
   - Complete game state control: Start, Pause/Resume, Game Over
2. Advanced Fusion Block Mode
   - Innovative 7 custom 8-block tetrominoes for more complex gameplay
   - Larger game board with extended game mechanics
   - Reused core logic via OOP inheritance from base classes
3. Number Puzzle Mode
   - Innovative gameplay combining number matching with classic Tetris
   - Extended elimination rules for more diverse and challenging gameplay

### Complete GUI System

- Multi-window architecture: Main Game Window, Settings Window, Gameplay Selection Window, and independent mode windows
- Smooth window switching and data synchronization based on Qt Signal & Slot mechanism
- Real-time next block preview area for all game modes
- Customized UI styling with Qt Style Sheet

### Audio & Interactive System

- Background music and rich sound effects (block moving, line elimination, game over)
- Full keyboard control support for all game operations
- Cheat function for unconditional line elimination (with score penalty)
- Random encouragement prompts after line elimination

## Tech Stack

- **Core Language**: C++11 and above
- **GUI Framework**: Qt (Qt Widgets, Qt Multimedia, Qt Core, Qt GUI)
- **Core Mechanism**: Qt Signal & Slot
- **Design Principle**: Object-Oriented Programming (OOP)
- **Build System**: QMake (native Qt build system)
- **Development Tool**: Qt Creator

## Project Structure

*Fully consistent with the actual project file structure*

plaintext

```
tetris-cpp/
├── assets/                   # Static resource files
│   ├── audio/                # Audio files (.wav, .mp3 for BGM and sound effects)
│   ├── icon/                 # Icon files (.ico for window and UI elements)
│   └── ui/                   # Qt Designer UI files (.ui)
├── include/                  # All header files (.h)
│   ├── CBoard.h              # Base class for game board logic
│   ├── cboard_expand.h       # Derived class for advanced mode board
│   ├── cboard_number.h       # Derived class for number mode board
│   ├── CTetrimino.h          # Base class for tetromino
│   ├── ctetrimino_expand.h   # Derived class for advanced mode tetromino
│   ├── ctetrimino_number.h   # Derived class for number mode tetromino
│   ├── mainwindow.h          # Main window class
│   ├── setwindow.h           # Settings window class
│   ├── waychoice.h           # Gameplay selection window class
│   ├── higherplay.h          # Advanced mode window class
│   ├── numberplay.h          # Number mode window class
│   └── ...                   # Other auto-generated ui header files
├── src/                      # All source code files (.cpp)
│   ├── CBoard.cpp            # Core game board logic implementation
│   ├── cboard_expand.cpp     # Advanced mode board logic implementation
│   ├── cboard_number.cpp     # Number mode board logic implementation
│   ├── CTetrimino.cpp        # Base tetromino logic implementation
│   ├── ctetrimino_expand.cpp # Advanced mode tetromino implementation
│   ├── ctetrimino_number.cpp # Number mode tetromino implementation
│   ├── mainwindow.cpp        # Main window logic and signal-slot connection
│   ├── setwindow.cpp         # Settings window implementation
│   ├── waychoice.cpp         # Gameplay selection window implementation
│   ├── higherplay.cpp        # Advanced mode window implementation
│   ├── numberplay.cpp        # Number mode window implementation
│   └── ...
├── image.qrc                 # Qt resource collection file for image resources
├── res.qrc                   # Qt resource collection file for general resources
├── sounds.qrc                # Qt resource collection file for audio resources
├── tetris-cpp.pro            # Qt QMake project configuration file
└── README.md                 # Project documentation
```

## Core OOP Architecture

The project is built on a highly modular object-oriented architecture, with two core base classes and extended inherited classes, fully demonstrating OOP features:

1. `CTetrimino` Base Class
   - Encapsulates all core attributes of a tetromino: shape type, coordinate system of blocks
   - Implements core methods: shape setting, random shape generation, boundary calculation, clockwise/counterclockwise rotation (based on matrix rotation formula)
   - Base class for `CTetrimino_Expand` and `CTetrimino_Number`, realizing code reuse via inheritance
2. `CBoard` Base Class
   - Inherits from `QFrame`, encapsulates the entire game board and game loop logic
   - Implements core game mechanics: block movement, collision detection, line elimination algorithm, keyboard event handling, score/level system, and game state management
   - Manages UI rendering of the game board via Qt `paintEvent`
   - Base class for `CBoard_Expand` and `CBoard_Number`, with polymorphic implementation of different gameplay logic
3. Window Module Classes
   - `MainWindow`, `SetWindow`, `WayChoice` and other window classes, realizing multi-window jump and data interaction via Qt Signal & Slot mechanism

## Game Controls

| Key   | Function                                                     |
| :---- | :----------------------------------------------------------- |
| ←     | Move block left                                              |
| →     | Move block right                                             |
| ↑     | Rotate block counterclockwise (90°)                          |
| Shift | Rotate block clockwise (90°)                                 |
| ↓     | Soft drop (move down one line)                               |
| Space | Hard drop (drop to the bottom immediately)                   |
| X     | Unconditional line elimination (cheat function, -10 score penalty) |

## How to Build & Run

### Prerequisites

- Qt 5.15 / Qt 6.0 or above (with Qt Widgets, Qt Multimedia components installed)
- C++ compiler supporting C++11 and above (MSVC, GCC, MinGW)
- Qt Creator (recommended)

### Build with Qt Creator (Recommended)

1. Clone or download this repository
2. Open `tetris-cpp.pro` in Qt Creator
3. Configure the project with a compatible Qt kit
4. Click the **Run** button to build and launch the game directly

### Build with QMake (Command Line)

1. Clone or download this repository

2. Open the terminal and enter the project root directory

3. Run QMake to generate Makefile:

   bash

   运行

   ```
   qmake tetris-cpp.pro
   ```

4. Build the project:

   bash

   运行

   ```
   # For Windows MinGW
   mingw32-make -j4
   
   # For Linux/macOS
   make -j4
   ```

5. Run the generated executable file in the output directory

## Screenshots

*You can replace the links below with your actual project screenshots*

- Main Game Interface
- Settings Interface
- Gameplay Selection Interface
- Advanced Fusion Mode Interface
- Number Puzzle Mode Interface

## Project Highlights (For Resume)

1. Strictly follows object-oriented programming principles, completes class abstraction, encapsulation, inheritance and polymorphism design, with clear code structure, low coupling and high scalability
2. Independently designed and implemented 2 innovative game modes (Advanced Fusion Mode, Number Puzzle Mode), realizing gameplay innovation on the basis of traditional Tetris
3. Proficient in using the core features of the Qt framework, including signal and slot mechanism, 2D drawing with `QPainter`, event handling, multimedia playback, etc., to complete a complete GUI interactive design
4. Implemented a complete closed-loop game logic, including random block generation, collision detection, line elimination algorithm, score and level system, game state management, etc.
5. Completed the architecture design of multiple interfaces, and realized smooth jump and data synchronization between the main interface, setting interface, gameplay selection interface, and multi-mode game interface

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.