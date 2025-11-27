

#include "../include/obstacles.h"

Obstacles::Obstacles(const std::vector<std::array<float, 4>>& inpRects) {
    for (const std::array<float, 4>& rect : inpRects) {
        sf::RectangleShape newRectangle({rect[0], rect[1]});

        // Centre Origin
        newRectangle.setOrigin({rect[0] / 2, rect[1] / 2});
        newRectangle.setPosition({rect[2], rect[3]});
        // Add to vector
        this->obstacles.push_back(newRectangle);
    }
}
void Obstacles::validateObjects() const {
    // TODO
}
void Obstacles::draw(sf::RenderWindow& target) const {
    for (const auto& obstacle : this->obstacles) {
        target.draw(obstacle);
    }
    // TODO
}
