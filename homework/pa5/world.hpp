#ifndef WORLD_H
#define WORLD_H

#include "Robot.hpp"

const int GRID_SIZE = 10;
const int INITIAL_ROBOTS = 5;

class World {
public:
    World();
    void initializeRobots();
    void displayGrid();
    void simulateOneStep();

private:
    Robot* grid[GRID_SIZE][GRID_SIZE];
};

#endif 
