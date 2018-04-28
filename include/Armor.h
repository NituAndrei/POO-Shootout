#ifndef ARMOR_H
#define ARMOR_H

#include "Agent.h"

class Armor
{
    public:
        Armor();
        ~Armor();
        virtual void applyModifiers()=0;
        virtual void removeModifiers()=0;
    protected:
        char Type[5];
    private:
};


class MediumKevlar: public Armor
{
    public:
        void applyModifiers(Agent&);
        void removeModifiers(Agent&);
    protected:
    private:
};

#endif // ARMOR_H
