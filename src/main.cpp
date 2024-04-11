#include "entity/entity.h"
#include "gui/gui.h"

int Entity::currentFreeID = 0;

int main()
{
    GUI gui;
    gui.drawInterface();
    return 0;
}

