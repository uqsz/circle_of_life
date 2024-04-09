#ifndef MAP_H_
#define MAP_H_

#include "../entity/entity.h"
#include <iostream>
#include <vector>

using std::vector;


class Map {
private:
    vector<vector<Entity>>* map;
    int size;

public:
    Map(int); // construct n x n map
    int getMapLenght() { return size; };
};

#endif // MAP_H_