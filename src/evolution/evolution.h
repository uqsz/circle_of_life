#ifndef EVOLUTION_H_
#define EVOLUTION_H_

#include "../headers/coordinates.h"
#include "../map/map.h"

class Evolution {
private:
    Map* map;

public:
    // constructors
    Evolution(Map*);

    // functional methods
    void evolve();
    void timeToMove();
    void timeToEat();
    void timeToGrow();
    void timeToReproduce();
};

#endif // EVOLUTION_H_