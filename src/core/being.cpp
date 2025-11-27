
#include "../include/being.h"

#include "../include/controller.h"
#include "../include/game.h"

// ==================== Constructors/Destructors ====================
Being::Being(Controller* inpController) { this->controller = inpController; }

// ==================== Setters ====================
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
void Being::setColour(const sf::Color& inpColour) {
    this->body.setFillColor(inpColour);
}
void Being::setType(const BeingType& inpType) { this->type = inpType; }

// ==================== Getters ====================
float Being::getSpeed() const { return this->speed; }
BeingType Being::getType() const { return this->type; }

// ==================== Game Logic ====================
void Being::draw(sf::RenderWindow& target) const { target.draw(this->body); }

void Being::update(const Game& game) {
    Action action = controller->getAction(*this, game);

    sf::Vector2f movement(action.moveX, action.moveY);
    sf::Vector2f finalMovement = movement;

    // ==================== Text X movement ====================

    // Check World Boundaries
    // Check obstacles
    //
    sf::FloatRect testBounds = this->body.getGlobalBounds();
    testBounds.position.x += movement.x;

    for (const auto& obstacle : game.getObstacles().obstacles) {
        if (areColliding(testBounds, obstacle.getGlobalBounds())) {
            finalMovement.x = 0;  // Block X movement
            break;
        }
    }

    // Test Y movement
    testBounds = this->body.getGlobalBounds();
    testBounds.position.y += movement.y;

    for (const auto& obstacle : game.getObstacles().obstacles) {
        if (areColliding(testBounds, obstacle.getGlobalBounds())) {
            finalMovement.y = 0;  // Block Y movement
            break;
        }
    }

    position += finalMovement;
    body.setPosition(position);
}
