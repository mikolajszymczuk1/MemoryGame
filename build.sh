#!/bin/bash

# Simple script to compile all app
g++ -c main.cpp
g++ main.o -o MemoryGameApp -lsfml-graphics -lsfml-window -lsfml-system
