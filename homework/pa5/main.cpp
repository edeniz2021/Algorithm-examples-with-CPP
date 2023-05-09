#include <iostream>
#include <ctime>
#include "world.hpp"

int main() {
    std::srand(std::time(0));
    World world;
    world.initializeRobots();

    while (true) {
        world.displayGrid();
        world.simulateOneStep();

        std::cout << std::endl << "Press enter for the next step" << std::endl;
        std::cin.ignore();
    }

    return 0;
}
