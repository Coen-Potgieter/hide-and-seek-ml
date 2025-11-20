
#include "../include/being.h"

Being::Being() {
    // Create Body (Circle)
    body = sf::CircleShape(BEING_SIZE, 4);

    // Set Colour
    body.setFillColor(BEING_COL);

    // Set Initial Position
    this->pos = {50.f, 50.f};
    body.setPosition(this->pos);

    // Tell Console Being Was Created
    std::cout << "Being Created...\n";
}

void Being::move() {
    this->pos.x += 0.1;
    this->pos.y += 0.1;
    body.setPosition(this->pos);
}

void Being::draw(sf::RenderWindow& target) const { target.draw(body); }
