#include "world.hpp"
#include "bulldozer.hpp"
#include "roomba.hpp"
#include "humanic.hpp"
#include "optimusprime.hpp"
#include "robocop.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

World::World() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j] = nullptr;
        }
    }
}
void World::displayGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == nullptr) {
                cout << ".";
            } else {
                cout << grid[i][j]->getSymbol();
            }
        }
        cout << endl;
    }
}