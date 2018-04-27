#include "Engine.h"

Engine::Engine()
{
    std::ifstream f("init.in");
    int AgentNumber,ArmorNumber,WeaponNumber;
    f>>MapSizeX>>MapSizeY;
    map=new Map(MapSizeX,MapSizeY);

    f>>AgentNumber>>ArmorNumber>>WeaponNumber;
    if(AgentNumber==-1)
    {
        //RANDOM
    }
    else
    {
        AgentList=new Agent*[AgentNumber];
        int x,y;
        char type[20];
        for(int i=1;i<=AgentNumber;i++)
        {
            f>>type;
            f>>x>>y;
            if(!strcmp(type,"soldier"))
            {
                AgentList[i]=new Soldier(AGENT_ID+i,x,y);
                (map->PlayArea)[x][y]=AGENT_ID+i;
            }
        }
    }

    if(ArmorNumber==-1)
    {
        //RANDOM
    }
    else
    {

    }

    if(WeaponNumber==-1)
    {
        //RANDOM
    }
    else
    {
        WeaponList=new Weapon*[WeaponNumber];
        int x,y;
        char type[5];
        for(int i=1;i<=WeaponNumber;i++)
        {
            f>>type;
            f>>x>>y;
            if(!strcmp(type,"AR"))
            {
                WeaponList[i]=new AssaultRifle(WEAPON_ID+i);
                (map->PlayArea)[x][y]=WEAPON_ID+i;
            }
        }
    }
    f.close();
}

void Engine::displayMap()//!!!
{
    for(int i=0;i<MapSizeX;i++)
    {
        for(int j=0;j<MapSizeY;j++)
        {
            if((map->PlayArea[i][j])/ID_MULTIPLIER == 0)
                std::cout<<char(map->PlayArea[i][j])<<" ";

            if((map->PlayArea[i][j])/ID_MULTIPLIER == 1)//agent = cifre
                std::cout<<map->PlayArea[i][j]%ID_MULTIPLIER<<" ";
                //std::cout<<AgentList[map->PlayArea[i][j]%ID_MULTIPLIER]->getHP();

            if((map->PlayArea[i][j])/ID_MULTIPLIER == 2)//arma = litere mici
                std::cout<<char( (map->PlayArea[i][j])%ID_MULTIPLIER +96 )<<" ";
                /*
                {
                    const char *a=WeaponList[map->PlayArea[i][j]%ID_MULTIPLIER]->getType();
                    std::cout<<a[1];
                    std::cout<<WeaponList[map->PlayArea[i][j]%ID_MULTIPLIER]->getType();
                }
                */

            if((map->PlayArea[i][j])/ID_MULTIPLIER == 3)//armura = litere mari
                std::cout<<char( (map->PlayArea[i][j])%ID_MULTIPLIER +64 )<<" ";
        }
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
