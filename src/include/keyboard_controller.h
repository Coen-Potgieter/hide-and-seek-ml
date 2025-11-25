
#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include "./controller.h"

class KeyboardController : public Controller {
   public:
    KeyboardController();

    Action getAction(const Being &self, const World &world) override {
        Action beingAction;
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
};

#endif
