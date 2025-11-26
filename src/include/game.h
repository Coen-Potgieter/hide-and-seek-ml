
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

#include "./hider.h"
#include "./keyboard_controller.h"
#include "./obstacles.h"

class Game {
   private:
    // ==================== Internal Variables ====================
    Obstacles obstacles{};
    Hider hider = Hider(new KeyboardController());

   public:
    // ==================== Constructor ====================
    // Default constructor when no obstacles are provided
    Game();
    // Constructor to initialise obstacles provided
    Game(const Obstacles& inpObstacles);

    // ==================== Methods ====================
    // Update & Draw the Game
    void update();
    void draw(sf::RenderWindow& target) const;
};

#endif
