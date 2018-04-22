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

    }
    f.close();
}

void Engine::displayMap()//!!!
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if((map->PlayArea[i][j])/ID_MULTIPLIER == 0)
                std::cout<<char(map->PlayArea[i][j])<<" ";

            if((map->PlayArea[i][j])/ID_MULTIPLIER == 1)//agent = cifre
                std::cout<<map->PlayArea[i][j]%ID_MULTIPLIER<<" ";

            if((map->PlayArea[i][j])/ID_MULTIPLIER == 2)//arma = litere mici
                std::cout<<char( (map->PlayArea[i][j])%ID_MULTIPLIER +96 )<<" ";

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
