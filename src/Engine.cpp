#include "Engine.h"

Engine::Engine()
{
    std::ifstream f("init.in");
    int MapSizeX,MapSizeY;
    f>>MapSizeX>>MapSizeY;
    map=new Map(MapSizeX,MapSizeY);
    f>>AgentNumber>>ArmorNumber>>WeaponNumber;
    if(AgentNumber==-1)
    {
        //RANDOM
    }
    else
    {
        AgentList=new Agent*[AgentNumber+1];
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
        ArmorList=new Armor*[ArmorNumber+1];
        int x,y;
        char type[5];
        for(int i=1;i<=ArmorNumber;i++)
        {
            f>>type;
            f>>x>>y;
            if(!strcmp(type,"MK"))
            {
                ArmorList[i]=new MediumKevlar(ARMOR_ID+i);
                (map->PlayArea)[x][y]=ARMOR_ID+i;
            }
        }
    }

    if(WeaponNumber==-1)
    {
        //RANDOM
    }
    else
    {
        WeaponList=new Weapon*[WeaponNumber+1];
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
    std::cout<<"Step by step? 1=True 0=False ";
    std::cin>>Debug;
    f.close();
}

/*
void Engine::displayMap()//!!!
{
    static int Frame=1;
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
                // comment here

            if((map->PlayArea[i][j])/ID_MULTIPLIER == 3)//armura = litere mari
                std::cout<<char( (map->PlayArea[i][j])%ID_MULTIPLIER +64 )<<" ";
        }
        std::cout<<'\n';
    }
    std::cout<<Frame++<<'\n'<<'\n';
}
*/

Agent* Engine::getAgentByPosition(int PosX,int PosY)
{
    return AgentList[map->PlayArea[PosX][PosY]%AGENT_ID];
}

Armor* Engine::getArmorByPosition(int PosX,int PosY)
{
    return ArmorList[map->PlayArea[PosX][PosY]%ARMOR_ID];
}

Weapon* Engine::getWeaponByPosition(int PosX,int PosY)
{
    return WeaponList[map->PlayArea[PosX][PosY]%WEAPON_ID];
}

void Engine::doThing()
{
    AgentList[2]->modifyHP(-199);
}

void Engine::begin()
{
    int i;
    map->displayMap();
    if(Debug)
    {
        int x;
        std::cin>>x;
    }
    for(i=1;i<=AgentNumber;i++)
    {
        if(AgentList[i]==NULL)
            continue;
        if(AgentList[i]->getHP()<=0)
        {
            int x,y;
            AgentList[i]->getPosition(x,y);
            map->PlayArea[x][y]=int('.');
            delete AgentList[i];
            AgentList[i]=NULL;
        }
    }

    Map aux(map->MapSizeX,map->MapSizeY);
    for(int j=0;j<map->MapSizeX;j++)
        for(int l=0;l<map->MapSizeY;l++)
            aux.PlayArea[j][l]=map->PlayArea[j][l];

    for(i=1;i<=AgentNumber;i++)
    {
        int DeltaX=0,DeltaY=0,TargetID=0;
        Map Surroundings(3,3);
        AgentList[i]->makeTurn(DeltaX,DeltaY,Surroundings,TargetID); //Surroundings se face din Map aux, se apeleaza cu (0,0, Surroundings,0)
    }

    int AgentsAlive=AgentNumber;
    for(i=1;i<=AgentNumber;i++)
    {
        if(AgentList[i]==NULL)
            AgentsAlive--;
    }
    if(AgentsAlive==0)
        std::cout<<"Draw";
    if(AgentsAlive==1)
        for(i=1;i<=AgentNumber;i++)
            if(AgentList[i]!=NULL)
                std::cout<<AGENT_ID+i<<" Wins!";
    if(AgentsAlive>1)
        begin();
}

Engine::~Engine()
{
    int i;
    for(i=1;i<=AgentNumber;i++)
        delete AgentList[i];
    delete AgentList;

    for(i=1;i<=ArmorNumber;i++)
        delete ArmorList[i];
    delete ArmorList;

    for(i=1;i<=WeaponNumber;i++)
        delete WeaponList[i];
    delete[] WeaponList;
}
