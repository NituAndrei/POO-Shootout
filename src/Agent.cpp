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

int Agent::getVisRange()
{
    return VisRange;
}

void Agent::modifyVisRange(int Value)
{
    VisRange+=Value;
}

int Agent::getMoveRange()
{
    return MoveRange;
}

void Agent::modifyMoveRange(int Value)
{
    MoveRange+=Value;
}

void Agent::getPosition(int &CoordX,int &CoordY)
{
    CoordX=PositionX;
    CoordY=PositionY;
}

void Agent::modifyPosition(int CoordX,int CoordY)
{
    PositionX+=CoordX;
    PositionY+=CoordY;
}

Weapon* Agent::getWeapon()
{
    return EquippedWeapon;
}

int Agent::makeTurn(int &DeltaX, int &DeltaY, Map map, int &target)
{
    return 0;
}

//Soldier

Soldier::Soldier(int ID, int X, int Y):Agent(ID,X,Y)
{
    hp=100;
    VisRange=6;
    MoveRange=3;
    //EquippedArmor=NULL;
    EquippedWeapon=NULL;
    strcpy(PreferredWeapon,"AR");
    strcpy(PreferredArmor,"MK");
}

/*
int Soldier::makeTurn(int DeltaX, int DeltaY, Map map, int target)
{
    return 1;
}
*/
