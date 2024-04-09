#include <algorithm> // Dla std::iota, std::shuffle
#include <iomanip>
#include <random>

#include "map.h"

using std::set;
using std::vector;

Map::Map(int n)
    : N(n)
{
    board = vector<vector<set<int>>>(n, vector<set<int>>(n));
    int amountOfAnimals = n * n / 4;

    std::random_device rd;
    std::mt19937 gen(rd());

    vector<int> indices = vector<int>(n * n);
    std::iota(indices.begin(), indices.end(), 0);
    std::shuffle(indices.begin(), indices.end(), gen);

    for (int i = 0; i < amountOfAnimals; i++) {
        Entity* e = new Animal(Coordinates { int(indices[i] / n), indices[i] % n });
        addEntity(e);
    }
}

Map::~Map()
{
    for (auto& e : entities) {
        delete e.second;
    }
    entities.clear();
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

void Map::moveAnimal(int id,Direction dir){
    board[entities[id]->getPos()->row][entities[id]->getPos()->col].erase(id);
    entities[id]->move(dir);
    board[entities[id]->getPos()->row][entities[id]->getPos()->col].insert(id);
}

std::ostream& operator<<(std::ostream& os, const Map& map)
{
    for (const auto& e : map.getHashMap()) {
        std::cout << std::setw(6) << e.first << "(" << e.second->getPos()->row << "," << e.second->getPos()->col << ")   ";
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