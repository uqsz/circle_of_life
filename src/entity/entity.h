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
    // constructors
    explicit Entity(Coordinates);

    // getters
    [[nodiscard]] inline int getID() const { return id; }
    [[nodiscard]] const inline Coordinates* getPos() const { return &position; }

    // operators
    friend std::ostream& operator<<(std::ostream&, const Entity&);
};




// animal class
class Animal : public Entity {
private:
    int timeToLive;

public:
    // constructors
    explicit Animal(Coordinates, int n = 1);

    // getters
    [[nodiscard]] inline int getTTL() const { return timeToLive; }
    [[nodiscard]] inline bool isDead() const { return timeToLive == 0; }

    // functional methods
    inline void decrementTTL() { --timeToLive; }
    inline void eat() { ++timeToLive; }
    void move(Direction,int); // update entity position
};




// plant class
class Plant : public Entity {
private:
    int energy;

public:
    // constructors
    explicit Plant(Coordinates, int n = 1);

    // getters
    [[nodiscard]] int getEnergy() const { return energy; }
    [[nodiscard]] inline bool isDead() const { return energy == 0; }

    // functional methods
    inline void eated() { --energy; }
    inline void grow(int n) { energy+=n; }
};

#endif // ENTITY_H_