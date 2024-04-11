#include "entity/entity.cpp"
#include "map/map.cpp"
#include "entity/entity.h"
#include "evolution/evolution.cpp"
#include "evolution/evolution.h"
#include "headers/coordinates.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;

int Entity::currentFreeID = 0;
int Entity::N = 5;

int main()
{
//    Map map(Entity::N);
//    Evolution ev(&map);
//
//    ev.evolve();
//    ev.evolve();
//    ev.evolve();
//    ev.evolve();
//    ev.evolve();
    // Utwórz okno o rozmiarze 500x500 pikseli
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Grid Example");

    // Utwórz siatkę o wymiarach 5x5
    const int rows = 5;
    const int cols = 5;
    const float cellSize = 100.f;
    sf::RectangleShape gridCell(sf::Vector2f(cellSize, cellSize));
    gridCell.setOutlineColor(sf::Color::Black);
    gridCell.setOutlineThickness(2.f);

    // Utwórz czcionkę i tekst
    sf::Font font;
//    if (!font.loadFromFile("arial.ttf")) {
//        std::cerr << "Failed to load font." << std::endl;
//        return 1;
//    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(2);
    text.setFillColor(sf::Color::Black);

    // Główna pętla programu
    while (window.isOpen())
    {
        // Obsłuż zdarzenia
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Wyczyść ekran
        window.clear(sf::Color::White);

        // Narysuj siatkę i wpisz liczby
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                gridCell.setPosition(i * cellSize, j * cellSize);
                window.draw(gridCell);

                // Ustaw tekst w środku komórki
                text.setString(std::to_string(i * cols + j));
                sf::FloatRect textBounds = text.getLocalBounds();
                text.setOrigin(textBounds.width / 2.f, textBounds.height / 2.f);
                text.setPosition(i * cellSize + cellSize / 2.f, j * cellSize + cellSize / 2.f);
                window.draw(text);
            }
        }

        // Wyświetl zawartość okna
        window.display();
    }

    return 0;


}