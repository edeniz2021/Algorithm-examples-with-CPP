#include "world.hpp"
#include "bulldozer.hpp"
#include "roomba.hpp"
#include "humanic.hpp"
#include "optimusprime.hpp"
#include "robocop.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

World::World()
{
    // Initialize the grid with null pointers
    for (int i = 0; i < GRID_SIZE; ++i)
    {
        for (int j = 0; j < GRID_SIZE; ++j)
        {
            grid[i][j] = nullptr;
        }
    }
}
World::~World()
{
    // Iterate over each element in the grid
    int i, j;
    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j] != NULL)
                delete (grid[i][j]);
        }
    }
}
// This function initializes a certain number of robots of different types
// by creating objects of the corresponding classes and placing them randomly
void World::initializeRobots()
{
    for (int i = 0; i < INITIAL_ROBOTS; i++)
    {
        placeRobotRandomly(new optimusprime(i));
        placeRobotRandomly(new robocop(i));
        placeRobotRandomly(new roomba(i));
        placeRobotRandomly(new bulldozer(i));
    }
}
// on the grid using the placeRobotRandomly() function. The number of robots of each
// type is determined by the INITIAL_ROBOTS constant.
void World::placeRobotRandomly(Robot *robot)
{
    int x, y;
    do
    {
        x = rand() % GRID_SIZE;
        y = rand() % GRID_SIZE;
    } while (grid[x][y] != nullptr);
    grid[x][y] = robot;
}
void World::simulate()
{
    int damage = 0;
    int dead = 0;
    int i = 0;
    int j = 0;
    int end_game = 0;
    while (i < GRID_SIZE && end_game == 0)
    {
        j = 0;
        while (j < GRID_SIZE)
        {
            if (i == 9 && j == 9)//The condition to finish the game so that it does not go into an infinite loop
            {
                j++;
                end_game = 1;
            }

            if (end_game != 1)
            {
                dead = 0;
                if (grid[i][j] == nullptr)//If the cell it controls is nullptr, it goes to the next step.
                    j++;
                else
                {
                    if (grid[i][j + 1] == nullptr)//if next step is nullptr proceed
                    {
                        grid[i][j + 1] = grid[i][j];//changed cell 
                        grid[i][j] = nullptr;
                        j++;
                    }
                    else
                    {
                        while (dead != 1)
                        {    //hit_message
                            damage = grid[i][j]->getDamage();
                            std::cout << grid[i][j]->getType() << "(" << grid[i][j]->getHit() << ") hits "
                                      << grid[i][j + 1]->getType() << "(" << grid[i][j + 1]->getHit() << ") with " << damage << std::endl;
                            grid[i][j + 1]->setHitpoint(damage);
                            std::cout << "The new hitpoints of " << grid[i][j + 1]->getType() << " is " << grid[i][j + 1]->getHit() << std::endl;
                            if (grid[i][j + 1]->getHit() <= 0)
                            {
                                grid[i][j + 1] = nullptr;
                                dead = 1;
                                j--;
                            }
                            if (dead != 1)//check dead
                            {
                                damage = grid[i][j + 1]->getDamage();
                                std::cout << grid[i][j + 1]->getType() << "(" << grid[i][j + 1]->getHit() << ") hits "
                                          << grid[i][j]->getType() << "(" << grid[i][j]->getHit() << ") with " << damage << std::endl;
                                grid[i][j]->setHitpoint(damage);
                                std::cout << "The new hitpoints of " << grid[i][j]->getType() << " is " << grid[i][j]->getHit() << std::endl;
                                if (grid[i][j]->getHit() <= 0)
                                {
                                    grid[i][j] = nullptr;
                                    dead = 1;
                                }
                            }
                        }
                        if (i != GRID_SIZE - 1 && j == GRID_SIZE - 1)
                        {
                            if (grid[i + 1][0] != nullptr)//control if it comes to the edges
                            {
                                while (dead != 1)
                                {
                                    damage = grid[i][j]->getDamage();
                                    std::cout << grid[i][j]->getType() << "(" << grid[i][j]->getHit() << ") hits "
                                              << grid[i + 1][0]->getType() << "(" << grid[i + 1][0]->getHit() << ") with " << damage << std::endl;
                                    grid[i + 1][0]->setHitpoint(damage);
                                    std::cout << "The new hitpoints of " << grid[i + 1][0]->getType() << " is " << grid[i + 1][0]->getHit() << std::endl;
                                    if (grid[i + 1][0]->getHit() <= 0)
                                    {
                                        grid[i + 1][0] = nullptr;
                                        dead = 1;
                                        j++;
                                    }
                                    if (dead != 1)
                                    {
                                        damage = grid[i + 1][0]->getDamage();
                                        std::cout << grid[i + 1][0]->getType() << "(" << grid[i + 1][0]->getHit() << ") hits "
                                                  << grid[i][j]->getType() << "(" << grid[i][j]->getHit() << ") with " << damage << std::endl;
                                        grid[i][j]->setHitpoint(damage);
                                        std::cout << "The new hitpoints of " << grid[i][j]->getType() << " is " << grid[i][j]->getHit() << std::endl;
                                        if (grid[i][j]->getHit() <= 0)
                                        {
                                            grid[i][j] = nullptr;
                                            dead = 1;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                grid[i + 1][0] = grid[i][j];
                                grid[i][j] = nullptr;
                            }
                        }
                    }
                }
            }
        }
        i++;
    }
}