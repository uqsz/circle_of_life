#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include "../map/map.h"
#include "../evolution/evolution.h"
#include "../simulation/simulation.h"
#include "../entity/entity.h"
#include "nana/gui/widgets/slider.hpp"
#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <iostream>

using namespace sf;

class GUI {
public:
    // functional methods
    void drawInterface(); // drawing graphic user interface
    void run(int, int, int); // opening interface
};


#endif // GUI_H
