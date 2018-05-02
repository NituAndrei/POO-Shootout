#include "Weapon.h"
#include <cstring>

Weapon::Weapon(int ID,int PosX, int PosY)
{
    id=ID;
    PositionX=PosX;
    PositionY=PosY;
}

Weapon::~Weapon()
{
    //dtor
}

int Weapon::getType()
{
    return Type;
}

int Weapon::getRange()
{
    return Range;
}

int Weapon::Fire()
{
    return -Damage;
}
