#include "entity.h"

Entity::Entity(Coordinates pos)
    : position(pos)
{
    this->id = Entity::currentFreeID;
    Entity::currentFreeID += 1;
};

void Entity::action()
{
    cout << id << " making action! " << endl;
}

void Entity::move(Direction dir)
{
    cout << "entity move";
}

std::ostream& operator<<(std::ostream& os, const Entity& e)
{
    os << "ID: " << e.getID() << std::endl
       << "Coordinates: (" << e.getPos()->row << "," << e.getPos()->col << ")" << std::endl;
    return os;
}

// animal class
Animal::Animal(Coordinates pos, int n)
    : Entity(pos)
    , timeToLive(n) {

    };

void Animal::move(Direction dir)
{
    switch (dir) {
    case LEFT:
        position.col = (position.col + N - 1) % N;
        decrementTTL();
        break;
    case UP:
        position.row = (position.row + N - 1) % N;
        decrementTTL();
        break;
    case RIGHT:
        position.col = (position.col + 1) % N;
        decrementTTL();
        break;
    case DOWN:
        position.row = (position.row + 1) % N;
        decrementTTL();
        break;
    default:
        break;
    }
}

void Animal::action()
{
    cout << "action!";
}

// plant class
Plant::Plant(Coordinates pos, int n)
    : Entity(pos)
    , energy(n)
    , isReadyToGrow(false)
{
}
void Plant::growIfYouCan()
{
    if (isReadyToGrow) {
        ++energy;
        isReadyToGrow = false;
    }
}

void Plant::action()
{
    cout << "action!";
}