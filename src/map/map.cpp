#include <iomanip>

#include "map.h"

using std::set;
using std::vector;


Map::Map(int n)
    : N(n)
{
    board = vector<vector<set<int>>>(n, vector<set<int>>(n));
    int amountOfAnimals = n * n / 4;

    for (int i = 0; i < amountOfAnimals; i++) {
        Entity* e = new Entity(Coordinates { i % n, i % n });
        addEntity(e);
    }
}

void Map::addEntity(Entity* e)
{
    board[e->getPos()->col][e->getPos()->row].insert(e->getID());
    entities[e->getID()] = e;
}

void Map::removeEntity(Entity* e)
{
    board[e->getPos()->col][e->getPos()->row].erase(e->getID());
    entities.erase(e->getID());
    delete e;
}

void Map::removeEntity(int id)
{
    Entity* e = entities[id];
    if (e != nullptr) {
        board[e->getPos()->col][e->getPos()->row].erase(id);
        entities.erase(id);
        delete e;
    }
}

std::ostream& operator<<(std::ostream& os, const Map& map)
{
    for (const auto& e : map.getHashMap()) {
        std::cout << std::setw(6) << e.first << "(" << e.second->getPos()->row << "," << e.second->getPos()->row << ")   ";
    }
    std::cout << endl;
    for (int i = 0; i < map.getMapLenght(); i++) {
        for (int j = 0; j < map.getMapLenght(); j++) {
            os << map.getAmount(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}