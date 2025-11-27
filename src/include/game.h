
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>

#include "./hider.h"
#include "./keyboard_controller.h"
#include "./obstacles.h"
#include "./seeker.h"

class Game {
   private:
    // ==================== Internal Variables ====================
    Obstacles obstacles{};
    Hider hider = Hider(new KeyboardController());
    Seeker seeker = Seeker(new KeyboardController());

   public:
    // ==================== Constructor ====================
    // Default constructor when no obstacles are provided
    Game() = default;
    // Constructor to initialise obstacles provided
    Game(const Obstacles& inpObstacles);

    // ==================== Getters ====================
    // Update & Draw the Game
    Obstacles getObstacles() const;

    // ==================== Game Logic ====================
    // Update & Draw the Game
    void update();
    void draw(sf::RenderWindow& target) const;
};

#endif
