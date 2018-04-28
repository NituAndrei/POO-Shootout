#ifndef AGENT_H
#define AGENT_H

#include "Weapon.h"
#include "Map.h"
//#include "Armor.h"

class Agent
{
    public:
        Agent(int,int,int);
        ~Agent();
        int getHP();
        void modifyHP(int);
        int getVisRange();
        void modifyVisRange(int);
        int getMoveRange();
        void modifyMoveRange(int);
        void getPosition(int&,int&);
        void modifyPosition(int,int);
        Weapon* getWeapon();
        virtual int makeTurn(int&,int&,Map,int&);//returneaza cat damage i-a dat lui target
        /*
        verif daca sta pe un item pe care-l vrea
        manhattan distance -> 4 directii de miscare
        daca vede inamic si are arma -> trage
        daca inamicu are STG si el nu are -> se indeparteaza la max rangeul armei lui/VisRange (oricacare e mai mic)
        daca gaseste arma/armura pref in VisRange-> rush la ea

        */
    protected:
        int PositionX,PositionY,id,hp,VisRange,MoveRange;
        char PreferredWeapon[5],PreferredArmor[5],EquippedArmorType[5];
        Weapon *EquippedWeapon;
        //Armor *EquippedArmor;
        //friend class Armor;
    private:
};

//todo mutat in alta clasa
class Soldier: public Agent //de ce nu merge private???
{
    public:
        Soldier(int,int,int);
        //int makeTurn(int,int,Map,int);
    protected:
    private:
};

#endif // AGENT_H
