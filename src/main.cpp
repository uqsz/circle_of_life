#include "entity/entity.cpp"
// #include "entity/entity.h"
#include <iostream>

using std::cout;

int main()
{
    Entity e1(4);
    Entity e2(1);
    Entity e3(2);

    cout << e1 << e2 << e3;
}