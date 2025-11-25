
#ifndef BEING_H
#define BEING_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "./being.h"
#include "./constants.h"

class Hider : public Being {
   public:
    Hider(Controller* ctrl) : Being(ctrl) {
        this->body.setFillColor(sf::Color::Blue);
    }
};

#endif
