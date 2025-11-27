
#include "../include/game.h"

// Constructor to initialise obstacles provided
Game::Game(const Obstacles& inpObstacles) { this->obstacles = inpObstacles; }

// ==================== Getters ====================
Obstacles Game::getObstacles() const { return this->obstacles; }

// ==================== Game Logic ====================
void Game::update() {
    this->hider.update(*this);
    this->seeker.update(*this);
}

void Game::draw(sf::RenderWindow& target) const {
    this->obstacles.draw(target);
    this->hider.draw(target);
    this->seeker.draw(target);
}
