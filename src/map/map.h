#ifndef MAP_H_
#define MAP_H_

#include "../entity/entity.h"
#include "../headers/coordinates.h"

#include <algorithm>
#include <iomanip>

#include <set>
#include <unordered_map>

using std::set;
using std::vector;

class Map {
private:
    vector<vector<set<int>>> animalsBoard;
    std::unordered_map<int, Animal*> animalsHashMap;
    vector<vector<Plant*>> plantsBoard;
    double animalsRatio;
    double plantsRatio;
    int N;

public:
    // constructors
    Map(int,int,int);

    // destructor
    ~Map();

    // getters
    inline int getMapLength() const { return N; };
    inline double getAnimalsRatio() const { return animalsRatio; };
    inline double getPlantsRatio() const { return plantsRatio; };
    inline int getAnimalsAmount(int row, int col) const { return animalsBoard[row][col].size(); };
    inline const std::unordered_map<int, Animal*>& getAnimalsHashMap() const { return animalsHashMap; };
    inline const vector<vector<set<int>>>& getAnimalsBoard() const { return animalsBoard; }
    inline const vector<vector<Plant*>>& getPlantsBoard() const { return plantsBoard; }

    // operators
    friend std::ostream& operator<<(std::ostream&, const Map&);

    // functional methods
    void addEntity(Animal*);
    void removeEntity(Animal*);
    void moveAnimal(int, Direction);
};

#endif // MAP_H_