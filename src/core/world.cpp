
#include "../include/world.h"

void World::update() {}
void World::draw(sf::RenderWindow& target) const {
    this->obstacles.draw(target);
}
