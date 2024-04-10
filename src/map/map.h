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

    
    int N;

public:
    vector<vector<Plant*>> plantsBoard;
    // constructors
    Map(int);

    // destructor
    ~Map();

    // getters
    inline int getMapLenght() const { return N; };
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