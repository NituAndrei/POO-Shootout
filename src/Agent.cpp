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

Soldier::Soldier(int ID, int X, int Y):Agent(ID,X,Y)
{
    hp=100;
    VisRange=4;
}
