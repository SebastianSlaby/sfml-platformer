#!/bin/bash
clear
g++ -c main.cpp playercontroller.cpp
g++ main.o playercontroller.o -o app/sfml-app -lsfml-graphics -lsfml-window -lsfml-system
rm main.o
app/sfml-app