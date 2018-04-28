#include "Armor.h"
#include "Agent.h"
#include <cstring>

Armor::Armor(int ID)
{
    id=ID;
}

Armor::~Armor()
{
    //dtor
}

const char* Armor::getType()
{
    return Type;
}

//MediumKevlar

MediumKevlar::MediumKevlar(int ID):Armor(ID)
{
    strcpy(Type,"MK");
}

void MediumKevlar::applyModifiers(Agent& Wearer)
{
    //Wearer.VisRange+=0;
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
