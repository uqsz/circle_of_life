#ifndef ENTITY_H_
#define ENTITY_H_

#include "../headers/coordinates.h"

using std::endl;
using std::vector;

// entity class
class Entity {
protected:
    int id;
    Coordinates position;

public:
    static int currentFreeID;
    static int N;
    // constructors
    Entity(Coordinates);

    // getters
    inline int getID() const { return id; }
    const inline Coordinates* getPos() const { return &position; }

    // operators
    friend std::ostream& operator<<(std::ostream&, const Entity&);
};

// animal class
class Animal : public Entity {
private:
    int timeToLive;

public:
    // constructors
    Animal(Coordinates, int n = 10);

    // getters
    inline int getTTL() const { return timeToLive; }
    inline bool isDead() const { return timeToLive == 0; }

    // functional methods
    inline void decrementTTL() { --timeToLive; }
    inline void eat() { ++timeToLive; }
    void move(Direction);
};

// plant class
class Plant : public Entity {
private:
    int energy;

public:
    // constructors
    Plant(Coordinates, int n = 1);

    // getters
    int getEnergy() const { return energy; }
    inline bool isDead() const { return energy == 0; }

    // functional methods
    inline void eated() { --energy; }
    inline void grow() { ++energy; }
};

#endif // ENTITY_H_