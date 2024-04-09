#include "entity.h"

int Entity::currentFreeID = 0;

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