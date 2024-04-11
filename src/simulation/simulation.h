#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include "../map/map.h"
#include "../evolution/evolution.h"

using namespace sf;

class Simulation {
private:
    RenderWindow* window;
    Evolution* evol;
    VertexArray* gridTemplate;
    int mapLength;
public:
    explicit Simulation(Evolution*);
    ~Simulation(){delete gridTemplate;};
    VertexArray* drawGrid();
    void drawEntities();
    void run();
};


#endif // GUI_H
