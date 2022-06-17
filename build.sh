#!/bin/bash

# Simple script to compile all app
g++ -c main.cpp
g++ -c Classes/Tile/Tile.cpp
g++ Tile.o main.o -o MemoryGameApp -lsfml-graphics -lsfml-window -lsfml-system
