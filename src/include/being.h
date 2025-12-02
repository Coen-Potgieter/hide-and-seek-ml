#ifndef BEING_H
#define BEING_H

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <utility>

#include "./helper_funcs.h"

enum BeingType {
    HIDER,
    SEEKER,
};

class Controller;
class World;

class Being {
   private:
    sf::Vector2f position = {30.f, 30.f};
    sf::CircleShape body = sf::CircleShape(3);
    float speed = 2;

    BeingType type;
    Controller* controller;

   protected:
    // We should never be creating a `Being` class in the main function, only by
    //  the derived class, so this goes here.
    explicit Being(Controller* inpController);

   public:
    virtual ~Being() = default;

    // Getters
    float getSpeed() const;
    BeingType getType() const;

    // Setters
    void setBodySize(int inpRadius);
    void setPosition(const sf::Vector2f inpPos);
    void setSpeed(const float inpSpeed);
    void setColour(const sf::Color& inpColour);
    void setType(const BeingType& inpType);

    // World Logic
    void draw(sf::RenderWindow& target) const;
    void update(World& world);
};

#endif
