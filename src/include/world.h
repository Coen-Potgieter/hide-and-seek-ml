
#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <optional>
#include <vector>

#include "./constants.h"
#include "./hider.h"
#include "./keyboard_controller.h"
#include "./obstacles.h"
#include "./seeker.h"

class World {
   protected:
    // ==================== Internal Variables ====================
    // Default Set Values
    Obstacles obstacles{};
    bool ended = false;
    size_t scoreHiders = 0;
    size_t scoreSeekers = 0;

    // Requires initialisation
    std::vector<Hider> hiders;
    std::vector<Seeker> seekers;
    sf::Font endProgramFont;
    // sf::Text has no default constructor, ie. requires font to create a text
    //  object. So here we use `std::optional` to tell the program that either
    //  we have a text object here or it is nothing
    std::optional<sf::Text> endingText;

    // ==================== Constructor ====================
    // Default constructor when no obstacles are provided
    World();
    // Constructor to initialise obstacles provided
    World(const Obstacles& inpObstacles);
    void initText(const std::string& fontSrc);

   public:
    // ==================== Getters ====================
    Obstacles getObstacles() const;
    std::vector<Hider> getHiders() const;
    std::vector<Seeker> getSeekers() const;

    // ==================== Setters ====================
    void setGameEnded(bool isGameEnded);

    // ==================== World Logic ====================
    // Update & Draw the World
    void update();
    void draw(sf::RenderWindow& target) const;
};

#endif
