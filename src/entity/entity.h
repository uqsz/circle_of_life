#ifndef ENTITY_H_
#define ENTITY_H_

#include "../headers/coordinates.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// abstract class
class AbstractEntity {
public:
    virtual void action() = 0;
};

// entity class
class Entity : public AbstractEntity {
private:
protected:
    int id;
    int timeToLive;
    Coordinates position;

public:
    static int currentFreeID;
    static int N;
    // constructors
    Entity(Coordinates, int n = 10);

    // getters
    inline int getID() const { return id; }
    inline int getTTL() const { return timeToLive; }
    const inline Coordinates* getPos() const { return &position; }

    // operators
    friend std::ostream& operator<<(std::ostream&, const Entity&);

    // functional methods
    void action() override;
    virtual void move(Direction);
};

// animal class
class Animal : public Entity {
public:
    Animal(Coordinates, int n = 10);
    inline void decrementTTL() { --timeToLive; }
    void move(Direction) override;
    void action() override;
};

// plant class
// class Plant : public Entity {
// private:
//     int energy;
//     void action() override;
// };

#endif // ENTITY_H_