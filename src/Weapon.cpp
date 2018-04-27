#include "Weapon.h"
#include <cstring>

Weapon::Weapon(int ID)
{
    id=ID;
}

Weapon::~Weapon()
{
    //dtor
}

const char* Weapon::getType()
{
    return Type;
}

int Weapon::Fire()
{
    //random(0,100), daca<HitChance => deal dmg
    return Damage;
}

AssaultRifle::AssaultRifle(int ID):Weapon(ID)
{
    Damage=25;
    Range=6;
    HitChance=70;
    strcpy(Type,"AR");
}
