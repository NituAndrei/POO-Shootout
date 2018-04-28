#ifndef MAP_H
#define MAP_H
#include <iostream>

#define AGENT_ID 10000 //"prefix" ca sa stie ce fel de obiect e
#define WEAPON_ID 20000
#define ARMOR_ID 30000
#define ID_MULTIPLIER 10000

class Map
{
    public:
        Map();
        Map(int, int);
        ~Map();
        void displayMap();
    protected:
        int **PlayArea,MapSizeX,MapSizeY;
        friend class Engine;
    private:
};

#endif // MAP_H
