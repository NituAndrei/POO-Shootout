#include "Armor.h"
#include "Agent.h"
#include <cstring>

Armor::Armor(int ID, int PosX, int PosY)
{
    id=ID;
    PositionX=PosX;
    PositionY=PosY;
}

Armor::~Armor()
{
    //dtor
}

const char* Armor::getType()
{
    return Type;
}
