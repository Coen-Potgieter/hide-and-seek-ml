

#include "../include/obstacles.h"

Obstacles::Obstacles(const std::vector<std::vector<sf::Vector2f>>& inpShapes) {
    std::cout << "Creating Obstacles...\n";

    for (const std::vector<sf::Vector2f>& shape : inpShapes) {
        sf::ConvexShape newShape;
        newShape.setPointCount(shape.size());
        size_t pointIdx = 0;
        for (const auto& point : shape) {
            newShape.setPoint(pointIdx, point);
            pointIdx += 1;
        }
        this->obstacles.push_back(newShape);
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
