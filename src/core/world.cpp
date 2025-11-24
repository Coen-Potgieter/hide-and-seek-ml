
#include "../include/world.h"

World::World(const std::vector<std::vector<float>>& inpObjects) {
    if (inpObjects.size() == 0) {
        std::cout << "No Objects Given...\n";
    }
    std::cout << "WE ARE CREATING THE WORLD...\n";
}

void World::update() {}
void World::draw(sf::RenderWindow& target) const {}
