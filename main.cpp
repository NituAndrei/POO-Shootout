#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Map.h"
#include "Engine.h"

using namespace std;

int main()
{
    //cout<<sizeof(Agent)<<" "<<sizeof(Soldier)<<'\n';
    srand(time(NULL));
    Engine engine;
    //engine.displayMap();
    //engine.doThing();
    engine.begin();
    //cout<<engine.getAgentByPosition(0,0)->getHP();
    //engine.begin();
}
