#ifndef LIGHTKEVLAR_H
#define LIGHTKEVLAR_H
#include "Armor.h"

class LightKevlar: public Armor
{
    public:
        LightKevlar(int,int,int);
        void applyModifiers(Agent&);
        void removeModifiers(Agent&);
    protected:
    private:
};
#endif // LIGHTKEVLAR_H
