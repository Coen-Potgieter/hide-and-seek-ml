
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

#include "./obstacles.h"

class Game {
   private:
    // ==================== Internal Variables ====================
    Obstacles obstacles{};
    Obstacles obstacles{};

   public:
    // ==================== Constructor ====================
    // Default constructor to initialise empty obstacles
    Game();
    // Constructor to initialise obstacles provided
    Game(const Obstacles& inpObstacles) : obstacles(inpObstacles) {}

    // ==================== Methods ====================
    // Update & Draw the Game
    void update();
    void draw(sf::RenderWindow& target) const;
};

#endif
