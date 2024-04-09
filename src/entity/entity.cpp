#include "entity.h"

int Entity::numberOfEntities = 0;

Entity::Entity(int n = 10)
    : timeToLive(n)
{
    this->id = Entity::numberOfEntities;
    Entity::numberOfEntities += 1;
};

void Entity::action()
{
    cout << id << " making action! " << endl;
}

std::ostream& operator<<(std::ostream& os, const Entity& e)
{
    os << "ID: " << e.getID() << std::endl
       << "Time to live: " << e.getTTL() << std::endl;
    return os;
}