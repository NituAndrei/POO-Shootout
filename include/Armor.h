#ifndef ARMOR_H
#define ARMOR_H

#include "Agent.h"

class Armor
{
    public:
        Armor(int);
        ~Armor();
        virtual void applyModifiers(Agent&)=0;
        virtual void removeModifiers(Agent&)=0;
        const char* getType();
    protected:
        int id;
        char Type[5];
    private:
};


class MediumKevlar: public Armor
{
    public:
        MediumKevlar(int);
        void applyModifiers(Agent&);
        void removeModifiers(Agent&);
    protected:
    private:
};

#endif // ARMOR_H
