
#include "../include/being.h"

#include "../include/controller.h"
#include "../include/world.h"

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

// ==================== World Logic ====================
void Being::draw(sf::RenderWindow& target) const { target.draw(this->body); }

void Being::update(World& world) {
    Action action = controller->getAction(*this, world);

    sf::Vector2f movement(action.moveX, action.moveY);
    sf::Vector2f finalMovement = movement;

    // ==================== Text X movement ====================
    // Get bounding box
    sf::FloatRect testBounds = this->body.getGlobalBounds();
    // See if next X movement collides with obstacle
    testBounds.position.x += movement.x;

    // Check if Seeker has caught Hider
    if (this->type == BeingType::SEEKER) {
        for (const Hider& hider : world.getHiders()) {
            if (areColliding(testBounds, hider.body.getGlobalBounds())) {
                world.setGameEnded(true);
                return;
            }
        }
    }

    // Check obstacles
    for (const auto& obstacle : world.getObstacles().obstacles) {
        if (areColliding(testBounds, obstacle.getGlobalBounds())) {
            finalMovement.x = 0;  // Block X movement
            break;
        }
    }

    // ==================== Text Y movement ====================
    // Get bounding box
    testBounds = this->body.getGlobalBounds();
    // See if next Y movement collides with obstacle
    testBounds.position.y += movement.y;
    for (const auto& obstacle : world.getObstacles().obstacles) {
        if (areColliding(testBounds, obstacle.getGlobalBounds())) {
            finalMovement.y = 0;  // Block Y movement
            break;
        }
    }

    // Update movement
    this->position += finalMovement;
    this->body.setPosition(this->position);
}
