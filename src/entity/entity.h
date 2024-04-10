#ifndef ENTITY_H_
#define ENTITY_H_

#include "../headers/coordinates.h"

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

    // functional methods
    void action() override;
    virtual void move(Direction);
};

// animal class
class Animal : public Entity {
private:
    int timeToLive;

public:
    Animal(Coordinates, int n = 10);
    inline int getTTL() const { return timeToLive; }
    inline void decrementTTL() { --timeToLive; }
    void eat() { ++timeToLive; }
    inline bool isDead() const { return timeToLive == 0; }
    void move(Direction) override;
    void action() override;
};

// plant class
class Plant : public Entity {
private:
    int energy;
    bool isReadyToGrow;

public:
    Plant(Coordinates, int n = 1);
    int getEnergy() const { return energy; }
    inline bool isDead() const { return energy == 0; }
    inline void eated() { --energy; }
    inline void readyToGrow() { isReadyToGrow = true; }
    inline void grow() { ++energy; }
    void growIfYouCan();
    void action() override;
};

#endif // ENTITY_H_