#include "entity/entity.cpp"
#include "map/map.cpp"
// #include "entity/entity.h"
#include "headers/coordinates.h"
#include <iostream>
#include <set>

using std::cout;

int n = 10;

int Entity::currentFreeID = 0;
int Entity::N = 10;

int main()
{
    Map map(n);
    cout << map;
    map.moveAnimal(1, RIGHT);
    map.moveAnimal(1, RIGHT);
    map.moveAnimal(1, RIGHT);
    cout << map;
}