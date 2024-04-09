#include "entity/entity.cpp"
#include "map/map.cpp"
// #include "entity/entity.h"
#include "headers/coordinates.h"
#include <iostream>
#include <set>

using std::cout;

int main()
{
    Map map(10);
    cout << map;
    map.removeEntity(1);
    map.removeEntity(2);
    Entity* e = new Entity(Coordinates{4,2});
    map.addEntity(e);
    cout << map;
}