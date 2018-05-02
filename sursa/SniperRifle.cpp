#include "SniperRifle.h"

SniperRifle::SniperRifle(int ID,int PosX,int PosY):Weapon(ID,PosX,PosY)
{
    Damage=40;
    Range=12;
    Type=2;
}
