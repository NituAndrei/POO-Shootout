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

const char* Weapon::getType()
{
    return Type;
}

int Weapon::getRange()
{
    return Range;
}

int Weapon::Fire()//todo
{
    return Damage;
}

//Assault Rifle

AssaultRifle::AssaultRifle(int ID,int PosX,int PosY):Weapon(ID,PosX,PosY)
{
    Damage=25;
    Range=6;
    HitChance=70;
    strcpy(Type,"AR");
}
