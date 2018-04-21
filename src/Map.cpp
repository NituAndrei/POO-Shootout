#include "Map.h"

Map::Map()
{
    //ctor
}

Map::Map(int sizeX, int sizeY)
{
    PlayArea=new int*[sizeX];
    for(int i=0;i<sizeX;i++)
        PlayArea[i]=new int[sizeY];
    for(int i=0;i<sizeX;i++)
        for(int j=0;j<sizeY;j++)
            PlayArea[i][j]=int('.');

}

Map::~Map()
{
    delete[] PlayArea;
}
