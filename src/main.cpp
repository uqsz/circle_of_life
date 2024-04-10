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
    Evolution ev(&map);

    ev.evolve();
    ev.evolve();
    ev.evolve();
    ev.evolve();
    ev.evolve();

}