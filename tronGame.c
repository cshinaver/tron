// Driver for Tron
// Maintainer: Charles Shinaver, Jared Rodgers
//
//
#include "func.h"

int main()
{
    int i;
    int deadBikeNumber;
    char c;
    double dt = .1;
    Color black = {0, 0, 0};
    Color white = {255, 255, 255};
    Color bike1Color = {255, 255, 0};
    Color bike2Color = {0, 102, 204};
    // Box Dimensions
    int offset = 50;
    int xsize = 800;
    int ysize = 800;
    int xBoxSize = xsize - offset;
    int yBoxSize = ysize - offset;
    int board[750][750] = {0};

    int xInitialCycle1 = 425;
    int yInitialCycle1 = 70;
    // Create cycle1
    LightCycle *cycle1 = malloc(sizeof(LightCycle));
    cycle1->x = 425;
    cycle1->y = 70;
    cycle1->orientation = left;
    cycle1->isAlive = 1;
    cycle1->radius = 2;
    cycle1->color = bike1Color;

    int xInitialCycle2 = 225;
    int yInitialCycle2 = 220;
    // Create cycle2
    LightCycle *cycle2 = malloc(sizeof(LightCycle));
    cycle2->x = 225;
    cycle2->y = 220;
    cycle2->orientation = right;
    cycle2->isAlive = 1;
    cycle2->radius = 2;
    cycle2->color = bike2Color;


    gfx_open(xsize, ysize, "Tron");

    // Plot boundaries and add to board
    createBoardBoundaries(offset, offset, xBoxSize, yBoxSize, white, board);


    while(1)
    {
        // Check if game has ended
        deadBikeNumber = isBikeDead(cycle1, cycle2);
        if (deadBikeNumber)
        {
            incrementScoreboard(deadBikeNumber, scoreboard);
            if (!isDesiringNewGame(cycle1, cycle2, xInitialCycle1, yInitialCycle1, xInitialCycle2, yInitialCycle2))
            {
                return 0;
            }
            else
            {
                gfx_clear();
                clearBoard(board);
                createBoardBoundaries(offset, offset, xBoxSize, yBoxSize, white, board);
                deadBikeNumber = 0;
            }
        }

        if (checkForKeyboardInput(cycle1, cycle2) == 'q')
        {
            return 0;
        }

        // moveBike
        moveBike(cycle1, dt, board);
        plotBike(cycle1, cycle1->color);
        moveBike(cycle2, dt, board);
        plotBike(cycle2, cycle2->color);

        usleep(500);
        
    }


    //    plotBike(cycle2);
    return 0;
}

