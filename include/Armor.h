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


class MediumKevlar: public Armor
{
    public:
        MediumKevlar(int,int,int);
        void applyModifiers(Agent&);
        void removeModifiers(Agent&);
    protected:
    private:
};

#endif // ARMOR_H
