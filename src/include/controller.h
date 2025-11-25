

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "./being.h"
#include "./world.h"

struct Action {
    float moveX;
    float moveY;
};

class Controller {
   public:
    // Recall: the `= 0` tells the compiler that this is a "pure virtual"
    //  function
    virtual Action getAction(const Being& self, const World& world) = 0;

    // This is here to specify the destructor is strictly `virtual`
    virtual ~Controller() = default;
};

#endif
