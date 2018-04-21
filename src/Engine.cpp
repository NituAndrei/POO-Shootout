#include "Engine.h"

Engine::Engine()
{
    std::ifstream f("init.in");
    int AgentNumber,ArmorNumber,WeaponNumber;
    f>>MapSizeX>>MapSizeY;
    map=new Map(MapSizeX,MapSizeY);
    /*
    f>>AgentNumber>>ArmorNumber>>WeaponNumber;
    if(AgentNumber==-1)
    {
        //RANDOM
    }
    else
    if(ArmorNumber==-1)
    {
        //RANDOM
    }
    else
    if(WeaponNumber==-1)
    {
        //RANDOM
    }
    else
    */
    f.close();
}

void Engine::displayMap()//!!!
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            std::cout<<char(map->PlayArea[i][j])<<" ";
        std::cout<<'\n';
    }
}

void Engine::begin()
{

}

Engine::~Engine()
{
    //dtor
}
