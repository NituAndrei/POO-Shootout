#include "MediumKevlar.h"

MediumKevlar::MediumKevlar(int ID,int PosX,int PosY):Armor(ID,PosX,PosY)
{
    strcpy(Type,"MK");
}

void MediumKevlar::applyModifiers(Agent& Wearer)
{
    Wearer.modifyMoveRange(-1);
    Wearer.modifyHP(20);
}

void MediumKevlar::removeModifiers(Agent& Wearer)
{
    Wearer.modifyMoveRange(1);
    if(Wearer.getHP()>=21)
        Wearer.modifyHP(-20);
    else
        Wearer.modifyHP(-(Wearer.getHP())+1);
}
