#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class AbstractEntity {
public:
    virtual void action() = 0;
};

class Entity : public AbstractEntity {
private:
protected:
    int id;
    int timeToLive;

public:
    static int numberOfEntities;
    // constructors
    Entity(int n);

    // getters
    inline int getID() const { return id; };
    inline int getTTL() const { return timeToLive; };

    // friends
    friend std::ostream& operator<<(std::ostream&, const Entity&);

    void action() override;
};

class Animal : Entity {
};

#endif // ENTITY_H_