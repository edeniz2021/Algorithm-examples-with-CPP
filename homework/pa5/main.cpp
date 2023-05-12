#include <iostream>
#include <ctime>
#include "world.hpp"

int main()
{
    std::srand(std::time(0));
    World world;
    world.initializeRobots();
    world.simulate();
    return 0;
}
