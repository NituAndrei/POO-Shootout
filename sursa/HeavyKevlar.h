#ifndef HEAVYKEVLAR_H
#define HEAVYKEVLAR_H
#include "Armor.h"

class HeavyKevlar: public Armor
{
    public:
        HeavyKevlar(int,int,int);
        void applyModifiers(Agent&);
        void removeModifiers(Agent&);
    protected:
    private:
};

#endif // HEAVYKEVLAR_H
