
#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

class Obstacles {
   private:
   public:
    std::vector<sf::RectangleShape> obstacles = {};

    // Default constructor to fall back on default value → Empty vector of
    //  shapes
    Obstacles() = default;
    Obstacles(const std::vector<std::array<float, 4>>& inpRects);
    void validateObjects() const;
    void draw(sf::RenderWindow& target) const;
};

#endif
