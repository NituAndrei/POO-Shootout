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
                (map->PlayArea)[x][y]=AGENT_ID+1;
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
                ArmorList[i]=new MediumKevlar(ARMOR_ID+i,x,y);
                (map->PlayArea)[x][y]=ARMOR_ID+2;
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
                WeaponList[i]=new AssaultRifle(WEAPON_ID+i,x,y);
                (map->PlayArea)[x][y]=WEAPON_ID+1;
            }
            if(!strcmp(type,"SR"))
            {
                WeaponList[i]=new SniperRifle(WEAPON_ID+i,x,y);
                (map->PlayArea)[x][y]=WEAPON_ID+1;
            }
            if(!strcmp(type,"STG"))
            {
                WeaponList[i]=new Shotgun(WEAPON_ID+i,x,y);
                (map->PlayArea)[x][y]=WEAPON_ID+1;
            }
        }
    }
    std::cout<<"Step by step? 1=True 0=False ";
    std::cin>>Debug;
    f.close();
}

Agent* Engine::getAgentByPosition(int PosX,int PosY)
{
    int x,y;
    for(int i=1;i<=AgentNumber;i++)
    {
        AgentList[i]->getPosition(x,y);
        if(x==PosX && y==PosY)
            return AgentList[i];
    }
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
    AgentList[1]->modifyHP(50);
}

struct Point
{
    int X,Y;
};

int getDistance(int x1,int y1,int x2,int y2)
{
    int d=0;
    if(x1>x2)
        d+=x1-x2;
    else
        d+=x2-x1;
    if(y1>y2)
        d+=y1-y2;
    else
        d+=y2-y1;
    return d;
}

void Engine::begin()
{
    int i,Exit=0;
    if(Debug)
    {
        int x;
        std::cin>>x;
    }
    map->displayMap();
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
    int AgentsAlive=AgentNumber;
    for(i=1;i<=AgentNumber;i++)
    {
        if(AgentList[i]==NULL)
            AgentsAlive--;
    }
    if(AgentsAlive==0)
    {
        Exit=1;
        map->displayMap();
        std::cout<<"Draw";
        return;
    }
    if(AgentsAlive==1)
        for(i=1;i<=AgentNumber;i++)
            if(AgentList[i]!=NULL)
            {
                map->displayMap();
                Exit=1;
                std::cout<<AGENT_ID+i<<" Wins!";
                return;
            }
    Map aux(map->MapSizeX,map->MapSizeY);
    for(int j=0;j<map->MapSizeX;j++)
        for(int l=0;l<map->MapSizeY;l++)
            aux.PlayArea[j][l]=map->PlayArea[j][l];

    for(i=1;i<=AgentNumber;i++)
    {
        if(AgentList[i]==NULL)
            continue;
        int DeltaX=0,DeltaY=0,TargetID=0,CurrentVisRange=AgentList[i]->getVisRange(),DamageDealt=0;
        Point CurrentPosition;
        Map Surroundings(2*CurrentVisRange+1,2*CurrentVisRange+1);

        AgentList[i]->getPosition(CurrentPosition.X,CurrentPosition.Y);
        for(int j=-CurrentVisRange;j<=CurrentVisRange;j++)
        {
            for(int l=-CurrentVisRange;l<=CurrentVisRange;l++)
            {
                if(getDistance(CurrentPosition.X,CurrentPosition.Y,CurrentPosition.X+j,CurrentPosition.Y+l) > AgentList[i]->getVisRange())
                {
                    Surroundings.PlayArea[j+CurrentVisRange][l+CurrentVisRange]='0';
                    continue;
                }
                if(CurrentPosition.X+j<0)
                {
                    Surroundings.PlayArea[j+CurrentVisRange][l+CurrentVisRange]='0';
                    continue;
                }
                if(CurrentPosition.X+j>(map->MapSizeX)-1)
                {
                    Surroundings.PlayArea[j+CurrentVisRange][l+CurrentVisRange]='0';
                    continue;
                }
                if(CurrentPosition.Y+l<0)
                {
                    Surroundings.PlayArea[j+CurrentVisRange][l+CurrentVisRange]='0';
                    continue;
                }
                if(CurrentPosition.Y+l>(map->MapSizeY)-1)
                {
                    Surroundings.PlayArea[j+CurrentVisRange][l+CurrentVisRange]='0';
                    continue;
                }
                Surroundings.PlayArea[j+CurrentVisRange][l+CurrentVisRange]=aux.PlayArea[CurrentPosition.X+j][CurrentPosition.Y+l];
            }
        }
        DamageDealt=AgentList[i]->makeTurn(DeltaX,DeltaY,Surroundings,TargetID); //Surroundings se face din Map aux, se apeleaza cu (0,0, Surroundings,0)
        if(TargetID==0)
        {
            if(DeltaX!=0 || DeltaY!=0)
            {
                if( (map->PlayArea[CurrentPosition.X+DeltaX][CurrentPosition.Y+DeltaY]/ID_MULTIPLIER) == 1)
                {
                    Agent *Enemy=getAgentByPosition(CurrentPosition.X+DeltaX,CurrentPosition.Y+DeltaY);
                    int j=(Enemy->getID())%AGENT_ID;
                    if(AgentList[i]->getHP() > Enemy->getHP())
                    {
                        AgentList[i]->modifyHP(-AgentList[j]->getHP());
                        AgentList[j]->modifyHP(-AgentList[j]->getHP());
                    }
                    if(AgentList[i]->getHP() < Enemy->getHP())
                    {
                        AgentList[j]->modifyHP(-AgentList[i]->getHP());
                        AgentList[i]->modifyHP(-AgentList[i]->getHP());
                    }
                    if(AgentList[i]->getHP() == Enemy->getHP())
                    {
                        AgentList[i]->modifyHP(-AgentList[i]->getHP());
                        AgentList[j]->modifyHP(-AgentList[j]->getHP());
                        map->PlayArea[CurrentPosition.X][CurrentPosition.Y]='.';
                        map->PlayArea[CurrentPosition.X+DeltaX][CurrentPosition.Y+DeltaY]='.';
                        continue;
                    }
                }
                if(AgentList[i]->getHP()>0)
                    map->PlayArea[CurrentPosition.X+DeltaX][CurrentPosition.Y+DeltaY]=map->PlayArea[CurrentPosition.X][CurrentPosition.Y];
                map->PlayArea[CurrentPosition.X][CurrentPosition.Y]='.';
            }
        }
        else
        {
            AgentList[TargetID%AGENT_ID]->modifyHP(DamageDealt);
        }
    }
    for(i=1;i<=AgentNumber;i++)
    {
        if(AgentList[i]==NULL)
            continue;
        if(AgentList[i]->getHP())
        {
            int X,Y;
            AgentList[i]->getPosition(X,Y);
            map->PlayArea[X][Y]=aux.PlayArea[X][Y];
            if((map->PlayArea[X][Y])/ARMOR_ID==1)
            {
                AgentList[i]->equipArmor( getArmorByPosition(X,Y)->getType() );
                getArmorByPosition(X,Y)->applyModifiers(*AgentList[i]);
            }
            if(map->PlayArea[X][Y]/ID_MULTIPLIER==2)
            {
                AgentList[i]->equipWeapon(getWeaponByPosition(X,Y));
            }
            if(!strcmp(AgentList[i]->getType(),"soldier"))
                map->PlayArea[X][Y]=AGENT_ID+1;
        }
        else
        {
            delete AgentList[i];
            AgentList[i]=NULL;
        }
    }
    AgentsAlive=AgentNumber;
    for(i=1;i<=AgentNumber;i++)
    {
        if(AgentList[i]==NULL)
            AgentsAlive--;
    }
    if(!Exit)
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
