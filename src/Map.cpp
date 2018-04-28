#include "Map.h"

Map::Map()
{
    //ctor
}

Map::Map(int SizeX, int SizeY)
{
    MapSizeX=SizeX;
    MapSizeY=SizeY;
    PlayArea=new int*[SizeX];
    for(int i=0;i<SizeX;i++)
        PlayArea[i]=new int[SizeY];
    for(int i=0;i<SizeX;i++)
        for(int j=0;j<SizeY;j++)
            PlayArea[i][j]=int('.');

}

Map::~Map()
{
    delete[] PlayArea;
}

void Map::displayMap()//!!!
{
    static int Frame=1;
    for(int i=0;i<MapSizeX;i++)
    {
        for(int j=0;j<MapSizeY;j++)
        {
            if((PlayArea[i][j])/ID_MULTIPLIER == 0)
                std::cout<<char(PlayArea[i][j])<<" ";

            if((PlayArea[i][j])/ID_MULTIPLIER == 1)//agent = cifre
                std::cout<<PlayArea[i][j]%ID_MULTIPLIER<<" ";
                //std::cout<<AgentList[map->PlayArea[i][j]%ID_MULTIPLIER]->getHP();

            if((PlayArea[i][j])/ID_MULTIPLIER == 2)//arma = litere mici
                std::cout<<char( (PlayArea[i][j])%ID_MULTIPLIER +96 )<<" ";
                /*
                {
                    const char *a=WeaponList[map->PlayArea[i][j]%ID_MULTIPLIER]->getType();
                    std::cout<<a[1];
                    std::cout<<WeaponList[map->PlayArea[i][j]%ID_MULTIPLIER]->getType();
                }
                */

            if((PlayArea[i][j])/ID_MULTIPLIER == 3)//armura = litere mari
                std::cout<<char( (PlayArea[i][j])%ID_MULTIPLIER +64 )<<" ";
        }
        std::cout<<'\n';
    }
    std::cout<<Frame++<<'\n'<<'\n';
}

/*
Map* Map::operator=(const Map *Source)
{
    PlayArea=new int*[Source.MapSizeX];
    for(int i=0;i<Source.MapSizeX;i++)
        PlayArea[i]=new int[Source.MapSizeY];
    for(int i=0;i<Source.MapSizeX;i++)
        for(int j=0;j<Source.MapSizeY;j++)
            PlayArea[i][j]=Source.PlayArea[i][j];

}*/
