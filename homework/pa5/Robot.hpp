#ifndef ROBOT_H
#define ROBOT_H

#include <string>

class Robot
{
public:
    Robot();
    Robot(int newType, int newStrength, int newHit, std::string newName);
    virtual ~Robot();
    virtual std::string getType();
    virtual int getDamage();
    virtual void setHitpoint(int damage)= 0;//pure virtual not implement
    virtual int getHit()= 0;

protected:
    int strength;
    int hit;
    std::string name;
    int type;
};

#endif 
