#include "entity/entity.cpp"
#include "map/map.cpp"
// #include "entity/entity.h"
#include "evolution/evolution.cpp"
#include "evolution/evolution.h"
#include "headers/coordinates.h"
#include <iostream>
using std::cout;

int Entity::currentFreeID = 0;
int Entity::N = 5;

int main()
{
    Map map(Entity::N);
    cout << map;
    Evolution ev(&map);
    ev.evolve();
    cout << map;
    ev.evolve();
    cout << map;
    ev.evolve();
    cout << map;
    ev.evolve();
    cout << map;
    ev.evolve();
    cout << map;
}