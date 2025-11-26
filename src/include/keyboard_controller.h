
#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H

#include <SFML/Graphics.hpp>

#include "./controller.h"

class KeyboardController : public Controller {
   public:
    Action getAction(const Being &self, const Game &game) override;
};

#endif
