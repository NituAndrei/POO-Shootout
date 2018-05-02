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

int abs(int a)
{
    if(a<0)
        return -a;
    return a;
}

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
        for(int i=0;i<4;i++)
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
        if((map.PlayArea[Current.X][Current.Y]/ARMOR_ID)==1)
        {
            if(EquippedArmorType==0 || (EquippedArmorType!=PreferredArmorID  && map.PlayArea[Current.X][Current.Y]%ARMOR_ID)==PreferredArmorID)
            {
                if(MoveRange<=Current.Distance)
                {
                    DeltaX=Current.X-(X/2);
                    DeltaY=Current.Y-(Y/2);
                    PositionX+=DeltaX;
                    PositionY+=DeltaY;
                    return 0;
                }
                else
                {
                    int n=MoveRange;
                    if(abs(Current.X-(X/2))<=n && n)
                    {
                        DeltaX=Current.X-(X/2);
                        PositionX+=DeltaX;
                        n-=DeltaX;
                    }
                    if(abs(Current.Y-(Y/2))<=n && n)
                    {
                        DeltaY=Current.Y-(Y/2);
                        PositionY+=DeltaY;
                        n-=DeltaY;
                    }
                    if(abs(Current.X-(X/2))>n && n)
                    {
                        DeltaX=n*((Current.X-(X/2))%1);
                        PositionX=n*((Current.X-(X/2))%1);
                        return 0;
                    }
                    if(abs(Current.Y-(Y/2))>n && n)
                    {
                        DeltaY=n*((Current.Y-(Y/2))%1);
                        PositionY=n*((Current.Y-(Y/2))%1);
                        return 0;
                    }
                }
            }
        }
        if((map.PlayArea[Current.X][Current.Y]/ID_MULTIPLIER)==2)//e arma
        {
            if(EquippedWeapon==NULL || (EquippedWeapon->getType()!=PreferredWeaponID && map.PlayArea[Current.X][Current.Y]%WEAPON_ID==PreferredWeaponID))
            {
                if(MoveRange<=Current.Distance)
                {
                    DeltaX=Current.X-(X/2);
                    DeltaY=Current.Y-(Y/2);
                    PositionX+=DeltaX;
                    PositionY+=DeltaY;
                    return 0;
                }
                else
                {
                    int n=MoveRange;
                    if(abs(Current.X-(X/2))<=n && n)
                    {
                        DeltaX=Current.X-(X/2);
                        PositionX+=DeltaX;
                        n-=DeltaX;
                    }
                    if(abs(Current.Y-(Y/2))<=n && n)
                    {
                        DeltaY=Current.Y-(Y/2);
                        PositionY+=DeltaY;
                        n-=DeltaY;
                    }
                    if(abs(Current.X-(X/2))>n && n)
                    {
                        DeltaX=n*((Current.X-(X/2))%1);
                        PositionX=n*((Current.X-(X/2))%1);
                        return 0;
                    }
                    if(abs(Current.Y-(Y/2))>n && n)
                    {
                        DeltaY=n*((Current.Y-(Y/2))%1);
                        PositionY=n*((Current.Y-(Y/2))%1);
                        return 0;
                    }
                }
            }
        }
        if((map.PlayArea[Current.X][Current.Y]/ID_MULTIPLIER)==1)//e agent
        {
            if(EquippedWeapon!=NULL)
            {
                if((EquippedWeapon->getRange())>=(Current.Distance))
                {
                    target=map.PlayArea[Current.X][Current.Y];
                    return EquippedWeapon->Fire();
                }
                else
                {
                    int n=MoveRange;
                    if(abs(Current.X-(X/2))<=n && n)
                    {
                        DeltaX=Current.X-(X/2);
                        PositionX+=DeltaX;
                        n-=DeltaX;
                    }
                    if(abs(Current.Y-(Y/2))<=n && n)
                    {
                        DeltaY=Current.Y-(Y/2);
                        PositionY+=DeltaY;
                        n-=DeltaY;
                    }
                    if(abs(Current.X-(X/2))>n && n)
                    {
                        DeltaX=n*((Current.X-(X/2))%1);
                        PositionX=n*((Current.X-(X/2))%1);
                        return 0;
                    }
                    if(abs(Current.Y-(Y/2))>n && n)
                    {
                        DeltaY=n*((Current.Y-(Y/2))%1);
                        PositionY=n*((Current.Y-(Y/2))%1);
                        return 0;
                    }
                }

            }
        }
    }
    //RANDOM position
    return 0;
}

void Agent::equipWeapon(Weapon *weapon)
{
    EquippedWeapon=weapon;
}

void Agent::equipArmor(const char* ArmorType)
{
    if(!strcmp("MK",ArmorType))
        EquippedArmorType=1;
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
    EquippedArmorType=0;
    EquippedWeapon=NULL;
    PreferredWeaponID=1;
    PreferredArmorID=2;
    strcpy(Type,"soldier");
}
