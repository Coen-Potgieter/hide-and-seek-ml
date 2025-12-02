

#include "../include/keyboard_controller.h"

#include "../include/being.h"

Action KeyboardController::getAction(const Being &self, const World &world) {
    Action beingAction = {0.f, 0.f};

    bool moveUpKeyDown;
    bool moveDownKeyDown;
    bool moveLeftKeyDown;
    bool moveRightKeyDown;

    if (self.getType() == BeingType::HIDER) {
        moveUpKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
        moveDownKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
        moveRightKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
        moveLeftKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    } else if (self.getType() == BeingType::SEEKER) {
        moveUpKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
        moveDownKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
        moveRightKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
        moveLeftKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
    }

    if (moveUpKeyDown) beingAction.moveY -= self.getSpeed();
    if (moveDownKeyDown) beingAction.moveY += self.getSpeed();

    if (moveRightKeyDown) beingAction.moveX += self.getSpeed();
    if (moveLeftKeyDown) beingAction.moveX -= self.getSpeed();

    return beingAction;
}
