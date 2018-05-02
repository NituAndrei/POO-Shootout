#include "AssaultRifle.h"

AssaultRifle::AssaultRifle(int ID,int PosX,int PosY):Weapon(ID,PosX,PosY)
{
    Damage=25;
    Range=6;
    Type=1;
}
