#include "Agent.h"

Agent::Agent(int ID, int X, int Y)
{
    id=ID;
    PositionX=X;
    PositionY=Y;
}

Agent::~Agent()
{
    //dtor
}

int Agent::getID()
{
    return id;
}

int Agent::getHP()
{
    return hp;
}

void Agent::modifyHP(int Value)
{
    hp+=Value;
}

int Agent::getVisRange()
{
    return VisRange;
}

void Agent::modifyVisRange(int Value)
{
    VisRange+=Value;
}

int Agent::getMoveRange()
{
    return MoveRange;
}

void Agent::modifyMoveRange(int Value)
{
    MoveRange+=Value;
}

void Agent::getPosition(int &CoordX,int &CoordY)
{
    CoordX=PositionX;
    CoordY=PositionY;
}

void Agent::modifyPosition(int CoordX,int CoordY)
{
    PositionX+=CoordX;
    PositionY+=CoordY;
}

Weapon* Agent::getWeapon()
{
    return EquippedWeapon;
}

struct Point
{
    int X,Y,Distance;
};

int Agent::makeTurn(int &DeltaX, int &DeltaY, Map map, int &target)
{
    int DX[4]={-1,0,1,0},DY[4]={0,1,0,-1},X,Y;
    Point Current;
    std::list<Point> Queue;

    map.getMapSize(X,Y);
    int Visited[X][Y];
    for(int i=0;i<X;i++)
        for(int j=0;j<Y;j++)
            Visited[i][j]=0;
    Visited[PositionX][PositionY]=1;

    Current.X=X/2;
    Current.Y=Y/2;
    Current.Distance=0;
    //Queue.push_back(Current);
    //map.displayMap();
    for(int i=0;i<4;i++)
    {
        if((Current.X+DX[i]>=0) && (Current.X+DX[i]<X) && (Current.Y+DY[i]>=0) && (Current.Y+DY[i]<Y) && Visited[Current.X+DX[i]][Current.Y+DY[i]]==0 && (map.PlayArea[Current.X+DX[i]][Current.Y+DY[i]])!='0')
        {
            Point aux=Current;
            aux.X+=DX[i];
            aux.Y+=DY[i];
            aux.Distance++;
            Queue.push_back(aux);
            Visited[Current.X+DX[i]][Current.Y+DY[i]]=1;
        }
    }
    while(!Queue.empty())
    {
        Current=Queue.front();
        Queue.pop_front();
        for(int i=0;i<4;i++)//map.PlayArea[Current.X+DX[i]][Current.Y+DY[i]]
        {
            if((Current.X+DX[i]>=0) && (Current.X+DX[i]<X) && (Current.Y+DY[i]>=0) && (Current.Y+DY[i]<Y) && Visited[Current.X+DX[i]][Current.Y+DY[i]]==0 && map.PlayArea[Current.X+DX[i]][Current.Y+DY[i]]!='0')
            {
                Point aux=Current;
                aux.X+=DX[i];
                aux.Y+=DY[i];
                aux.Distance++;
                Queue.push_back(aux);
                Visited[Current.X+DX[i]][Current.Y+DY[i]]=1;
            }
        }
        //std::cout<<'\n'<<Current.X<<" "<<Current.Y<<" distance "<<Current.Distance;
        if((map.PlayArea[Current.X][Current.Y]/ARMOR_ID)==1)
        {
            if(EquippedArmorType[0]==NULL)
            {
                if(MoveRange<=Current.Distance)
                {
                    DeltaX=Current.X-(X/2);
                    DeltaY=Current.Y-(Y/2);
                    PositionX+=DeltaX;
                    PositionY+=DeltaY;
                    return 0;
                }
            }
        }
    }
    //if(EquippedArmorType[0]==NULL)
    return 0;
}

void Agent::equipWeapon(Weapon *weapon)
{
    EquippedWeapon=weapon;
}

void Agent::equipArmor(const char* ArmorType)
{
    strcpy(EquippedArmorType,ArmorType);

}

const char* Agent::getType()
{
    return Type;
}

//Soldier

Soldier::Soldier(int ID, int X, int Y):Agent(ID,X,Y)
{
    hp=100;
    VisRange=6;
    MoveRange=3;
    EquippedArmorType[0]='\0';
    EquippedWeapon=NULL;
    strcpy(PreferredWeapon,"AR");
    strcpy(PreferredArmor,"MK");
    strcpy(Type,"soldier");
}

/*
int Soldier::makeTurn(int DeltaX, int DeltaY, Map map, int target)
{
    return 1;
}
*/
