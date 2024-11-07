# Game and Player Management System

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Classes and Structure](#classes-and-structure)
- [Data Files](#data-files)
- [Requirements](#requirements)
- [Setup and Installation](#setup-and-installation)
- [Usage](#usage)
- [Future Enhancements](#future-enhancements)

## Overview
The **Game and Player Management System** is a C++ project designed to manage players and games through a binary search tree (BST) structure. It stores data in a file-based system and uses a dynamic array of `games_played` objects.

## Features
- Manages player and game data using BST for efficient access
- Stores data in files, ensuring persistence between sessions
- Dynamic array of `games_played` objects to keep track of each player’s history

## Classes and Structure
### Main Classes:
- **Player**: Stores and manages player-specific data
- **Game**: Manages game-related data and interactions
- **BSTNode**: Represents each node in the binary search tree
- **BST**: Manages the binary search tree for data storage and retrieval

### Data Structure:
- The project uses a binary search tree to efficiently manage and retrieve game and player data.

## Data Files
- **players.txt**: Stores data on each player
- **games.txt**: Stores game-related data
- **score.txt**: Logs and saves player scores

## Requirements
To run this project, you'll need:
- **Visual Studio Code** with the **C++ extension**
- **GCC** compiler (if you're on Windows, use [MinGW](http://mingw-w64.org/) or WSL with GCC)

## Setup and Installation
1. **Clone this repository**:
   ```bash
   git clone https://github.com/yourusername/repository-name.git
