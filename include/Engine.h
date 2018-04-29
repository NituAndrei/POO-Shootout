#ifndef ENGINE_H
#define ENGINE_H
#include "Map.h"
#include "Agent.h"
#include "Armor.h"
#include "Weapon.h"
#include <fstream>
#include <cstring>

class Engine
{
    public:
        Engine();
        ~Engine();
        void displayMap();//!!!
        void begin();
        void doThing();
        Agent* getAgentByPosition(int,int);
        Armor* getArmorByPosition(int,int);
        Weapon* getWeaponByPosition(int,int);
    protected:
        int AgentNumber,ArmorNumber,WeaponNumber,Debug;
        Map *map;
        Agent **AgentList;
        Armor **ArmorList;
        Weapon **WeaponList;
    private:
};

#endif // ENGINE_H
