
#include "../include/game.h"

void Game::update() {}
void Game::draw(sf::RenderWindow& target) const {
    this->obstacles.draw(target);
}
