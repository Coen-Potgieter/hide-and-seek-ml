#include "../include/hider.h"

#include "../include/controller.h"

// Here we are calling the Being constructor that also initialises the derived
//  Hider class using an initialiser list
Hider::Hider(Controller* inpController) : Being(inpController) {
    this->setColour(sf::Color::Blue);
}
