**PACMAN GAME – A PROJECT OF OBJECT-ORIENTED PROGRAMMING**

# GROUP MEMBER

SHAHIRA KHAN 24K-0639

MEHAK ZAINAB 24K-0508

BASHAIR YAQOOB 24K-0810

# Submission Date

24th April 2025

# Executive Summary

### **• Overview:**

This project aims to design and develop a 2D Pacman game using Object-Oriented Programming (OOP) concepts in C++. The game includes core gameplay elements such as a player-controlled Pacman, ghosts (enemies), score-increasing dots, booster dots for speed enhancement, and a red dot that affects ghost behavior. The movement is controlled using keyboard inputs ("W", "A", "S", "D"), and wall collisions are implemented to restrict player movement. The player has 3 lives to survive and the game stops after he loses all 3 of them. If the player survives and eats all the dots, the _player wins_.

### **• Key Findings:**

The project successfully demonstrated key OOP concepts like abstraction, and encapsulation. Interactive gameplay features like speed changes, real-time collision detection, and ghost behavior added depth and complexity to the game.

# 2\. Introduction

**• Background:**

This project was selected to apply OOP principles in a practical and engaging way. Games like Pacman offer a structured yet creative platform to implement real-world programming logic using object interactions, and data encapsulation. C++ is used worldwide to create game, thus it was an attempt to make a mark in the gaming world as well.

**• Project Objectives:**

- To implement a playable version of Pacman in C++ using OOP.
- To incorporate features like scoring, boosters, and enemy behavior.
- To ensure smooth user interaction and game mechanics through keyboard controls and real-time feedback.

# 3\. Project Description

**• Scope:**

**Included Features:**

- Static map design with walls and walkable paths
- Player-controlled Pacman
- Multiple ghosts
- Addition of SFML
- Dots (score points), green booster dots (increase player speed)
- One red dot that increases ghost speed when consumed.
- Collision detection with walls
- Keyboard controls using “W”, “A”, “S”, “D”

**Excluded Features:**

- Sound effects or music
- Advanced AI pathfinding for ghosts
- Save/load game functionality

**• Technical Overview:**

- **Language:** C++
- **IDE:** Visual Studio Code
- **Other Tools:** SFML for graphics, YouTube, Github

# 4\. Methodology

**• Approach:**

The project was developed using weekly milestones, starting with planning, and brainstorming, followed by basic implementation, adding features incrementally, and finally testing and debugging.

**• Roles and Responsibilities (until now):**

- **Shahira Khan:** Map design & Game class & main.cpp (SFML setup)
- **Mehak Zainab:** Player & booster class & collision logic
- **Bashair Yaqoob:** Ghost class & Wall class & Dot class

# 5\. Project Implementation

**• Design and Structure:**

- **Classes Used:**
  - Game
  - Player, Ghost, Dot, Wall, Booster, map
  - Game class to manage the game loop, rendering, and interactions
- **Layout:** The map is a 2D grid where each tile can be a wall, empty space, or contain a dot.

**• Functionalities Developed:**

- Real-time player movement via “W”, “A”, “S”, “D”
- Ghosts move independently with simple logic.
- Eating the green booster increases Pacman's speed temporarily.
- Eating the red dot increases ghost speed temporarily.
- Collision detection prevents players from walking through walls
- Score system increments when dots are eaten.

**• Challenges Faced:**

- Handling real-time input and smooth movement without lag
- Integrating SFML without any prior knowledge.
- Ensuring player and ghost do not glitch into walls
- Implementing temporary speed boosts without bugs
- Balancing game difficulty with changing ghost speed

**• Solutions:**

- Implemented frame-based timing for consistent speed.
- Used bounding box logic for wall collision detection.
- Created timers for temporary speed effects.

# 6\. Results

**• Project Outcomes:**

All initial objectives were achieved. The game is fully playable, responsive to keyboard inputs, and includes the required boosters and behavior changes for both the player and the ghosts.

**• Screenshots and Illustrations:**

1<sup>st</sup> step learning SFML & displaying our first output:

!<img width="261" alt="1" src="https://github.com/user-attachments/assets/8a3c8f95-0bd7-44cd-9177-e1d19c40e1ca" />


Illustration of our maze map:


!<img width="244" alt="2" src="https://github.com/user-attachments/assets/95f4d4c9-4f99-4b57-a4c4-f8c2bd6b2e2c" />



Final maze map & correcting booster placement:


!<img width="247" alt="3" src="https://github.com/user-attachments/assets/6e905222-98e8-4d63-bc69-f49b3730e218" />



**• Testing and Validation:**

- All features tested through trial runs
- Game played on different systems for compatibility
- Each function and class was unit-tested to ensure proper operation

# 7\. Conclusion

**• Summary of Findings:**

The Pacman project effectively demonstrates core OOP principles and how they can be applied in game development. The team successfully created a playable game with dynamic interactions, demonstrating real-time behavior changes and object interactions.

**• Final Remarks:**

This project deepened our understanding of C++ and OOP. We recommend future iterations to include advanced AI, sound integration, and better UI for enhanced gameplay experience.
