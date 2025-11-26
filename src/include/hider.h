#ifndef HIDER_H
#define HIDER_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "./being.h"
class Controller;

class Hider : public Being {
   public:
    explicit Hider(Controller* inpController);
};

#endif
