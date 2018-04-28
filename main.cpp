#include <iostream>
#include "Map.h"
#include "Engine.h"

using namespace std;

int main()
{
    //cout<<sizeof(Agent)<<" "<<sizeof(Soldier)<<'\n';
    Engine engine;
    engine.displayMap();
    //cout<<engine.getAgentByPosition(0,0)->getHP();
    //engine.begin();
}
