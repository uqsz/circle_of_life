#include "evolution.h"

Evolution::Evolution(Map* map_pointer)
    : map(map_pointer)
{
}

void Evolution::evolve()
{
    timeToMove();
    timeToGrow();
    timeToEat();
    timeToReproduce();
    std::cout << *map;
}

void Evolution::timeToMove()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);
    const std::unordered_map<int, Animal*>& animalsHashMap = map->getAnimalsHashMap();

    for (auto& e : map->getAnimalsHashMap()) {
        if (animalsHashMap.at(e.first)->isDead()) {
            map->removeEntity(animalsHashMap.at(e.first));
            continue;
        }
        map->moveAnimal(e.first, Direction(dis(gen) % 4));
    }
}

void Evolution::timeToEat()
{
    const vector<vector<set<int>>>& animalsBoard = map->getAnimalsBoard();
    const vector<vector<Plant*>>& plantsBoard = map->getPlantsBoard();
    const std::unordered_map<int, Animal*>& animalsHashMap = map->getAnimalsHashMap();

    for (int i = 0; i < map->getMapLenght(); i++) {
        for (int j = 0; j < map->getMapLenght(); j++) {
            for (int id : animalsBoard[i][j]) {
                if (!plantsBoard[i][j]->isDead()) {
                    animalsHashMap.at(id)->eat();
                    plantsBoard[i][j]->eated();
                }
            }
        }
    }
}

void Evolution::timeToGrow()
{
    Plant* p;
    int n = map->getMapLenght();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-1, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p = map->getPlantsBoard()[i][j];
            if (p->getEnergy() != 0) {
                map->getPlantsBoard()[(i + dis(gen) + n) % n][(j + dis(gen) + n) % n]->grow();
            }
        }
    }
}

void Evolution::timeToReproduce()
{
    const vector<vector<set<int>>>& animalsBoard = map->getAnimalsBoard();
    for (int i = 0; i < map->getMapLenght(); i++) {
        for (int j = 0; j < map->getMapLenght(); j++) {
            if (map->getAnimalsAmount(i, j) > 1) {
                Animal* a = new Animal(Coordinates { i, j }, 3);
                map->addEntity(a);
            }
        }
    }
}
