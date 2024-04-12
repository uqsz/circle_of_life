#ifndef EVOLUTION_H_
#define EVOLUTION_H_

#include "../headers/coordinates.h"
#include "../map/map.h"

class Evolution {
private:
    Map* map;

public:
    // constructors
    explicit Evolution(Map*);

    //getters
    inline const Map* getMap() const { return map;}

    // functional methods
    void evolve();
    void timeToMove(); // animals moving on map
    void timeToEat(); // animals eating plant
    void timeToGrow(); // plants growing
    void timeToReproduce(); // animals are reproducing
};

#endif // EVOLUTION_H_