
#include "../include/game.h"

// Default constructor when no obstacles are provided
Game::Game() {
    this->hider = Hider(new KeyboardController());
    this->obstacles = Obstacles();
}
// Constructor to initialise obstacles provided
Game::Game(const Obstacles& inpObstacles) {
    this->hider = Hider(new KeyboardController());
    this->obstacles = inpObstacles;
}

void Game::update() { this->hider.update(*this); }
void Game::draw(sf::RenderWindow& target) const {
    this->obstacles.draw(target);
    this->hider.draw(target);
}
