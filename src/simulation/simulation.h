#ifndef SIMULATION_H
#define SIMULATION_H

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
    //constructor
    explicit Simulation(Evolution*);

    // destructor
    ~Simulation(){delete gridTemplate;};

    // functional methods
    VertexArray* drawGrid(); // setting a grid used in window
    void drawEntities(); // updating entities position on grid
    void run(); // opening window and running simulation
};


#endif // SIMULATION_H
