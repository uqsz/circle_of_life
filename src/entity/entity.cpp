#include "entity.h"

Entity::Entity(Coordinates pos, int n)
    : timeToLive(n)
    , position(pos)
{
    this->id = Entity::currentFreeID;
    Entity::currentFreeID += 1;
};

void Entity::action()
{
    cout << id << " making action! " << endl;
}

std::ostream& operator<<(std::ostream& os, const Entity& e)
{
    os << "ID: " << e.getID() << std::endl
       << "Time to live: " << e.getTTL() << std::endl
       << "Coordinates: (" << e.getPos()->row << "," << e.getPos()->col << ")" << std::endl;
    return os;
}

// animal class
Animal::Animal(Coordinates pos, int n)
    : Entity(pos, n) {};

void Animal::move(Direction dir)
{
    switch (dir) {
    case LEFT:
        (--position.col + N) % N;
        break;
    case UP:
        (--position.row + N) % N;
        break;
    case RIGHT:
        (++position.col) % N;
        break;
    case DOWN:
        (++position.row) % N;
        break;
    default:
        break;
    }
}

void Animal::action()
{
    cout << "action!";
}