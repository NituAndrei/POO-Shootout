#ifndef ENGINE_H
#define ENGINE_H
#include "Map.h"
#include <fstream>

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
    private:
};

#endif // ENGINE_H
