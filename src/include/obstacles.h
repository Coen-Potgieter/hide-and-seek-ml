
#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <vector>

class Obstacles {
   private:
   public:
    std::vector<sf::ConvexShape> obstacles = {};

    // Default constructor to fall back on default value → Empty vector of
    //  shapes
    Obstacles() = default;
    Obstacles(const std::vector<std::vector<sf::Vector2f>>& inpShapes);
    void validateObjects() const;
    void draw(sf::RenderWindow& target) const;
};

#endif
