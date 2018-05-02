#include "LightKevlar.h"

LightKevlar::LightKevlar(int ID,int PosX,int PosY):Armor(ID,PosX,PosY)
{
    strcpy(Type,"LK");
}

void LightKevlar::applyModifiers(Agent& Wearer)
{
    Wearer.modifyHP(10);
}

void LightKevlar::removeModifiers(Agent& Wearer)
{
    if(Wearer.getHP()>=11)
        Wearer.modifyHP(-10);
    else
        Wearer.modifyHP(-(Wearer.getHP())+1);
}
