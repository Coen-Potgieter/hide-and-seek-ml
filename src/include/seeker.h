
#ifndef SEEKER_H
#define SEEKER_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "./being.h"
class Controller;

class Seeker : public Being {
   public:
    explicit Seeker(Controller* inpController);
};

#endif
