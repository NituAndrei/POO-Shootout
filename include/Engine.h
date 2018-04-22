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
    protected:
        int MapSizeX,MapSizeY;
        Map *map;
        Agent **AgentList;
        Armor **ArmorList;
        Weapon **WeaponList;
    private:
};

#endif // ENGINE_H
