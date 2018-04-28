#include "Armor.h"
#include "Agent.h"

Armor::Armor()
{
    //ctor
}

Armor::~Armor()
{
    //dtor
}

//MediumKevlar

void MediumKevlar::applyModifiers(Agent& Wearer)
{
    //Wearer.VisRange+=0;
    Wearer.modifyMoveRange(-1);
    Wearer.modifyHP(20);
}

void MediumKevlar::removeModifiers(Agent& Wearer)
{
    Wearer.modifyMoveRange(1);
    Wearer.modifyHP(-20);
}
