#include "Shotgun.h"

Shotgun::Shotgun(int ID,int PosX,int PosY):Weapon(ID,PosX,PosY)
{
    Damage=50;
    Range=3;
    Type=3;
}
