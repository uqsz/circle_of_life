#ifndef MAP_H_
#define MAP_H_

#include "../entity/entity.h"
#include "../headers/coordinates.h"

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using std::vector;

class Map {
private:
    vector<vector<std::set<int>>> board;
    std::unordered_map<int, Entity*> entities;
    int N;

public:
    // constructors
    Map(int);

    // getters
    inline int getMapLenght() const { return N; };
    inline int getAmount(int row, int col) const { return board[row][col].size(); };
    inline const std::unordered_map<int, Entity*>& getHashMap() const { return entities; };

    // operators
    friend std::ostream& operator<<(std::ostream&, const Map&);

    // functional methods
    void addEntity(Entity*);
    void removeEntity(Entity*);
    void removeEntity(int n);
};

#endif // MAP_H_