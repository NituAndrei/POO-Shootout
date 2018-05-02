#ifndef MEDIUMKEVLAR_H
#define MEDIUMKEVLAR_H
#include "Armor.h"

class MediumKevlar: public Armor
{
    public:
        MediumKevlar(int,int,int);
        void applyModifiers(Agent&);
        void removeModifiers(Agent&);
    protected:
    private:
};
#endif // MEDIUMKEVLAR_H
