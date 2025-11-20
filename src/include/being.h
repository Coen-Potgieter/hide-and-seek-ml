
#ifndef BEING_H
#define BEING_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "./constants.h"

class Being {
   private:
   public:
    sf::CircleShape body;
    sf::Vector2f pos;

    Being();
    ~Being() = default;

    void draw(sf::RenderWindow& target) const;
    void move();
};

#endif
