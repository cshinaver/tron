// Header for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//

#include "gfx3.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum Orientation{
    left,
    right,
    up,
    down,
};

typedef struct Color {
    int r;
    int g;
    int b;
} Color;

typedef struct LightCycle {
    double x;
    double y;
    enum Orientation orientation;
    int isAlive;
    int radius;
    Color color;
} LightCycle;


void moveBike(LightCycle *cycle, double dt, int board[450][450]);
void plotBike(LightCycle *cycle, Color bikeColor);
void removeOldBike(LightCycle *cycle, double dt, Color colorForReplacing);
void createBoardBoundaries(int xTopLeft, int yTopLeft, int xBottomRight, int yBottomRight, int board[450][450]);
char checkForKeyboardInput(LightCycle *cycle1, LightCycle *cycle2);
