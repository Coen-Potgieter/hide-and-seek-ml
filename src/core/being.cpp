
#include "../include/being.h"

#include "../include/controller.h"
#include "../include/game.h"

Being::Being(Controller* inpController) { this->controller = inpController; }

void Being::update(const Game& game) {
    Action updateAction = this->controller->getAction(*this, game);
    std::cout << "UPDATE: " << updateAction.moveX << ", " << updateAction.moveY
              << '\n';
    this->position.x += updateAction.moveX;
    this->position.y += updateAction.moveY;

    body.setPosition(position);
};

void Being::setBodySize(int inpRadius) {
    this->body.setRadius(inpRadius);
    this->body.setOrigin(
        {static_cast<float>(inpRadius), static_cast<float>(inpRadius)});
}
void Being::setPosition(const sf::Vector2f inpPos) {
    this->position = inpPos;
    this->body.setPosition(this->position);
}
void Being::setSpeed(const float inpSpeed) { this->speed = inpSpeed; }
void Being::setVelocity(const sf::Vector2f& inpVel) { this->velocity = inpVel; }
void Being::setColour(const sf::Color& inpColour) { this->colour = inpColour; }
void Being::draw(sf::RenderWindow& target) const { target.draw(this->body); }
