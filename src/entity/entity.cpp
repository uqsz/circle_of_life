#include "entity.h"

// entity class
Entity::Entity(Coordinates pos)
    : position(pos)
{
    this->id = Entity::currentFreeID;
    Entity::currentFreeID += 1;
};

std::ostream& operator<<(std::ostream& os, const Entity& e)
{
    os << "ID: " << e.getID() << std::endl
       << "Coordinates: (" << e.getPos()->row << "," << e.getPos()->col << ")" << std::endl;
    return os;
}

// animal class
Animal::Animal(Coordinates pos, int n)
    : Entity(pos)
    , timeToLive(n)
{
}

void Animal::move(Direction dir)
{
    switch (dir) {
    case LEFT:
        position.col = (position.col + N - 1) % N;
        break;
    case UP:
        position.row = (position.row + N - 1) % N;
        break;
    case RIGHT:
        position.col = (position.col + 1) % N;
        break;
    case DOWN:
        position.row = (position.row + 1) % N;
        break;
    }
    decrementTTL();
}

// plant class
Plant::Plant(Coordinates pos, int n)
    : Entity(pos)
    , energy(n)
{
}
