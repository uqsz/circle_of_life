#include "map.h"

using std::set;
using std::vector;

Map::Map(int n, int animalsRatio, int plantsRatio)
    : N(n)
    , animalsBoard(vector<vector<set<int>>>(n, vector<set<int>>(n)))
    , plantsBoard(vector<vector<Plant*>>(n, vector<Plant*>(n)))
    , animalsRatio(animalsRatio)
    , plantsRatio(plantsRatio)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    vector<int> indices = vector<int>(N * N);
    std::iota(indices.begin(), indices.end(), 0);
    std::shuffle(indices.begin(), indices.end(), gen);

    for (int i = 0; i < N*N/4; i++) {
        Animal* e = new Animal(Coordinates { int(indices[i] / N), indices[i] % N }, 3);
        addEntity(e);
    }

    std::uniform_int_distribution<> dis(0, plantsRatio);

    for (int i = 0; i < N * N; i++) {
        Plant* e = new Plant(Coordinates { i / N, i % N }, dis(gen));
        plantsBoard[i / N][i % N] = e;
    }
}

Map::~Map()
{
    for (auto& e : animalsHashMap) {
        delete e.second;
    }
    animalsHashMap.clear();
}

void Map::addEntity(Animal* e)
{
    if (e != nullptr) {
        animalsBoard[e->getPos()->row][e->getPos()->col].insert(e->getID());
        animalsHashMap.emplace(e->getID(), e);
    }
}

void Map::removeEntity(Animal* e)
{
    if (e != nullptr) {
        auto it = animalsHashMap.find(e->getID());
        if (it != animalsHashMap.end()) {
            animalsBoard[e->getPos()->row][e->getPos()->col].erase(e->getID());
            // delete e;
            // animalsHashMap.erase(it);
        }
    }
}

void Map::moveAnimal(int id, Direction dir)
{
    animalsBoard[animalsHashMap.at(id)->getPos()->row][animalsHashMap.at(id)->getPos()->col].erase(id);
    animalsHashMap.at(id)->move(dir,N);
    animalsBoard[animalsHashMap.at(id)->getPos()->row][animalsHashMap.at(id)->getPos()->col].insert(id);
}

std::ostream& operator<<(std::ostream& os, const Map& map)
{
    for (const auto& e : map.getAnimalsHashMap()) {
        // std::cout << std::setw(6) << e.first << "(" << e.second->getPos()->row << "," << e.second->getPos()->col << ")   ";
        // std::cout << *e.second;
    }
    std::cout << endl;
    for (int i = 0; i < map.getMapLength(); i++) {
        for (int j = 0; j < map.getMapLength(); j++) {
            os << map.getAnimalsAmount(i, j) << " ";
        }
        os << "   ";
        for (int j = 0; j < map.getMapLength(); j++) {
            os << map.plantsBoard[i][j]->getEnergy() << " ";
        }
        os << std::endl;
    }
    return os;
}