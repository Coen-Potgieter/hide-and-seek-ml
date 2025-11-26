#ifndef BEING_H
#define BEING_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Controller;
class Game;

class Being {
   private:
    sf::Vector2f position = {30.f, 30.f};
    sf::CircleShape body = sf::CircleShape(3);
    sf::Vector2f velocity = {0.f, 0.f};
    float speed = 2;
    sf::Color colour = sf::Color::White;
    Controller* controller;

   protected:
    // We should never be creating a `Being` class in the main function, only by
    //  the derived class, so this goes here.
    explicit Being(Controller* inpController);

   public:
    virtual ~Being() = default;

    void update(const Game& game);

    void setBodySize(int inpRadius);
    void setPosition(const sf::Vector2f inpPos);
    void setSpeed(const float inpSpeed);
    void setVelocity(const sf::Vector2f& inpVel);
    void setColour(const sf::Color& inpColour);
    void draw(sf::RenderWindow& target) const;
};

#endif
