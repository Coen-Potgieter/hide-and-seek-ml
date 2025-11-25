#ifndef BEING_H
#define BEING_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "./constants.h"
#include "./controller.h"
#include "./world.h"

class Being {
   public:
    sf::Vector2f position = {30.f, 30.f};
    sf::CircleShape body = sf::CircleShape(3);
    sf::Vector2f velocity = {0.f, 0.f};
    float speed = 2;
    sf::Color colour = sf::Color::White;
    Controller* controller;

    explicit Being(Controller* inpController) {
        this->controller = inpController;
    }

    virtual ~Being() = default;

    void update(const World& world) {
        Action updateAction = this->controller->getAction(this, world);
        this->position.x += updateAction.moveX;
        this->position.y += updateAction.moveY;

        body.move(position);
    };

    void setBodySize(int inpRadius) {
        this->body.setRadius(inpRadius);
        this->body.setOrigin(
            {static_cast<float>(inpRadius), static_cast<float>(inpRadius)});
    }
    void setPosition(const sf::Vector2f inpPos) {
        this->position = inpPos;
        this->body.setPosition(this->position);
    }
    void setSpeed(const float inpSpeed) { this->speed = inpSpeed; }
    void setVelocity(const sf::Vector2f& inpVel) { this->velocity = inpVel; }
    void setColour(const sf::Color& inpColour) { this->colour = inpColour; }
    void draw(sf::RenderWindow& target) const { target.draw(this->body); }
};

#endif
