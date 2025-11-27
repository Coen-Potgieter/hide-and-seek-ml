#include "../include/seeker.h"

#include "../include/controller.h"

// Here we are calling the Being constructor that also initialises the derived
//  Hider class using an initialiser list
Seeker::Seeker(Controller* inpController) : Being(inpController) {
    this->setColour(sf::Color::Red);
    this->setType(BeingType::SEEKER);
}
