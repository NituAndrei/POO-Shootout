#include "HeavyKevlar.h"

HeavyKevlar::HeavyKevlar(int ID,int PosX,int PosY):Armor(ID,PosX,PosY)
{
    strcpy(Type,"HK");
}

void HeavyKevlar::applyModifiers(Agent& Wearer)
{
    Wearer.modifyVisRange(-1);
    Wearer.modifyMoveRange(-2);
    Wearer.modifyHP(30);
}

void HeavyKevlar::removeModifiers(Agent& Wearer)
{
    Wearer.modifyVisRange(1);
    Wearer.modifyMoveRange(2);
    if(Wearer.getHP()>=31)
        Wearer.modifyHP(-30);
    else
        Wearer.modifyHP(-(Wearer.getHP())+1);
}
