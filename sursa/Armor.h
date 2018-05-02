#ifndef ARMOR_H
#define ARMOR_H

#include "Agent.h"

class Armor
{
    public:
        Armor(int,int,int);
        ~Armor();
        virtual void applyModifiers(Agent&)=0;
        virtual void removeModifiers(Agent&)=0;
        const char* getType();
    protected:
        int id,PositionX,PositionY;
        char Type[5];
    private:
};
#endif // ARMOR_H
