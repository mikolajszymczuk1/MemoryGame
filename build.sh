#!/bin/bash

# Simple script to compile all app
g++ -c main.cpp
g++ -c Classes/Tile/Tile.cpp
g++ -c Classes/Board/Board.cpp
g++ Tile.o Board.o main.o -o MemoryGameApp -lsfml-graphics -lsfml-window -lsfml-system
