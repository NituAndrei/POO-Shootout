#include "Agent.h"
#include <cstddef>
#include <cstring>

Agent::Agent(int ID, int X, int Y)
{
    id=ID;
    PositionX=X;
    PositionY=Y;
}

Agent::~Agent()
{
    //dtor
}

int Agent::getHP()
{
    return hp;
}

void Agent::modifyHP(int Value)
{
    hp+=Value;
}

Soldier::Soldier(int ID, int X, int Y):Agent(ID,X,Y)
{
    hp=100;
    VisRange=6;
    MoveRange=3;
    EquippedArmor=NULL;
    EquippedWeapon=NULL;
    strcpy(PreferredWeapon,"AR");
    strcpy(PreferredArmor,"MK");
}
