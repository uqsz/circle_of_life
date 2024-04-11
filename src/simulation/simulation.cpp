#include <thread>
#include "simulation.h"


Simulation::Simulation(Evolution* pt_evolution) : evol(pt_evolution), mapLength(pt_evolution->getMap()->getMapLength()){
    window = new RenderWindow(VideoMode(mapLength*40, mapLength*40), "Simulation");
    gridTemplate = this->drawGrid();
}

VertexArray* Simulation::drawGrid(){
    // initialize values
    int numLines = mapLength+mapLength-2;
    auto* grid = new VertexArray(sf::Lines, 2*(numLines));

    window->setView(window->getDefaultView());
    auto size = window->getView().getSize();
    float rowH = size.y/mapLength;
    float colW = size.x/mapLength;

    // row separators
    for(int i=0; i < mapLength-1; i++){
        int r = i+1;
        float rowY = rowH*r;
        (*grid)[i*2].position = {0, rowY};
        (*grid)[i*2+1].position = {size.x, rowY};
    }

    // column separators
    for(int i=mapLength-1; i < numLines; i++){
        int c = i-mapLength+2;
        float colX = colW*c;
        (*grid)[i*2].position = {colX, 0};
        (*grid)[i*2+1].position = {colX, size.y};
    }
    return grid;
}

void Simulation::drawEntities() {
    float centerX;
    float centerY;
    sf::CircleShape dot(5);
    auto size = window->getView().getSize();
    float rowH = size.y/mapLength;
    float colW = size.x/mapLength;
    for (int i = 0; i<mapLength ; i++){
        for (int j = 0; j<mapLength ; j++){
            if (evol->getMap()->getAnimalsAmount(i,j)!=0) {
                centerX = j * colW + colW / 4;
                centerY = i * rowH + rowH / 4;
                dot.setFillColor(Color::Red);
                dot.setOrigin(dot.getRadius(), dot.getRadius());
                dot.setPosition(centerX, centerY);
                window->draw(dot);
            }
            if(!evol->getMap()->getPlantsBoard()[i][j]->isDead()) {
                centerX = j * colW + 3*colW / 4;
                centerY = i * rowH + 3*rowH / 4;
                dot.setFillColor(Color::Green);
                dot.setOrigin(dot.getRadius(), dot.getRadius());
                dot.setPosition(centerX, centerY);
                window->draw(dot);
            }
        }
    }
}

void Simulation::run() {
    sf::Clock timer;
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            break;
        }
        if (timer.getElapsedTime().asSeconds() >= 0.05f) {
            window->clear();
            window->draw(*gridTemplate);
            drawEntities();
            evol->evolve();
            window->display();
            timer.restart();
        }
    }
}
