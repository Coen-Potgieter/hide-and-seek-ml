

#include "../include/keyboard_controller.h"

Action KeyboardController::getAction(const Being &self, const Game &game) {
    Action beingAction = {0.f, 0.f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        beingAction.moveY = 2;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        beingAction.moveY = -2;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        beingAction.moveX = 2;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        beingAction.moveX = -2;
    }

    return beingAction;
}
